import java.util.*;
import java.io.*;
public class ds3 {
	
	static int MAXN = 100001;
	static node segTree[] = new node[4*MAXN];
	static int vs[] = new int[MAXN];
	
	static class node {
		int l, r, v, gcd, freq;
		public node(int l1, int r1, int v1, int v2, int v3) {
			l = l1; r = r1; v = v1; gcd = v2; freq = v3;
		}
	}
	
	static int gcd(int a, int b) {
		return b == 0 ? a : gcd(b, a % b);
	}
	
	static void pushup(int idx) {
		segTree[idx].v = Math.min(segTree[idx<<1].v, segTree[idx<<1|1].v);
		segTree[idx].gcd = gcd(segTree[idx<<1].gcd, segTree[idx<<1|1].gcd);
		segTree[idx].freq = 0;
		
		if(segTree[idx].gcd == segTree[idx<<1].gcd) segTree[idx].freq += segTree[idx<<1].freq;
		if(segTree[idx].gcd == segTree[idx<<1|1].gcd) segTree[idx].freq += segTree[idx<<1|1].freq;
	}
	
	static void build(int l, int r, int idx) {
		segTree[idx] = new node(0,0,0,0,0);
		segTree[idx].l = l; segTree[idx].r = r;
		segTree[idx].v = vs[l]; segTree[idx].gcd = vs[l]; segTree[idx].freq =1;
		if(l!=r) {
			int mid = (l+r)/2;
			build(l, mid, idx<<1);
			build(mid+1, r, idx<<1|1);
			pushup(idx);
		}
	}
	
	static void update(int pos, int val, int idx) {
		if(segTree[idx].l == segTree[idx].r) {
			segTree[idx].v = val;
			segTree[idx].gcd = val;
			segTree[idx].freq = 1;
			return;
		}
		int mid = (segTree[idx].l + segTree[idx].r)/2;
		if(pos <= mid) update(pos, val, idx<<1);
		else update(pos, val, idx<<1|1);
		pushup(idx);
	}
	
	static int qmin(int l, int r, int idx) {
	    if(l <= segTree[idx].l && r >= segTree[idx].r) {
	        return segTree[idx].v;
	    }
	    int mid = (segTree[idx].l + segTree[idx].r)/2;
	    if(r<=mid) return qmin(l, r, idx<<1);
	    else if(l>mid) return qmin(l, r, idx<<1|1);
	    else return Math.min(qmin(l, mid, idx<<1), qmin(mid+1, r, idx<<1|1));
	}
	
	static int qgcd(int l, int r, int idx) {
	    if(segTree[idx].l == l && segTree[idx].r == r) {
	        return segTree[idx].gcd;
	    }
	    int mid = (segTree[idx].l + segTree[idx].r)/2;
	    if(r<=mid) return qgcd(l, r, idx<<1);
	    else if(l>mid) return qgcd(l, r, idx<<1|1);
	    else return gcd(qgcd(l, mid, idx<<1), qgcd(mid+1, r, idx<<1|1));
	}
	
	static int qfreq(int l, int r, int v, int idx) {
	    if(segTree[idx].l == l && segTree[idx].r == r) {
	        return segTree[idx].gcd == v ? segTree[idx].freq : 0;
	    }
	    int mid = (segTree[idx].l + segTree[idx].r)/2;
	    if(r<=mid) return qfreq(l, r, v, idx<<1);
	    else if(l>mid) return qfreq(l, r, v, idx<<1|1);
	    else return qfreq(l, mid, v, idx<<1) + qfreq(mid+1, r, v, idx<<1|1);
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), Q = readInt();
		for(int i=1;i<=N;i++) vs[i] = readInt();
		build(1,N,1);
		
		for(int i=0;i<Q;i++) {
			String s = read();
			int a = readInt(), b = readInt();
			if(s.equals("C")) update(a, b, 1);
			else if(s.equals("M")) pr.println(qmin(a, b, 1));
			else if(s.equals("G")) pr.println(qgcd(a, b, 1));
			else {
				int v = qgcd(a, b, 1);
				pr.println(qfreq(a, b, v, 1));
			}
		}
		pr.close();
	}

	final private static int BUFFER_SIZE = 1 << 16;
	private static DataInputStream din = new DataInputStream(System.in);
	private static byte[] buffer = new byte[BUFFER_SIZE];
	private static int bufferPointer = 0, bytesRead = 0;
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

	public static String readLine() throws IOException {
		byte[] buf = new byte[64]; // line length
		int cnt = 0, c;
		while ((c = Read()) != -1) {
			if (c == '\n')
				break;
			buf[cnt++] = (byte) c;
		}
		return new String(buf, 0, cnt);
	}
	public static String read() throws IOException{
		byte[] ret = new byte[1024];
        int idx = 0;
        byte c = Read();
        while (c <= ' ') {
            c = Read();
        }
        do {
            ret[idx++] = c;
            c = Read();
        } while (c != -1 && c != ' ' && c != '\n' && c != '\r');
        return new String(ret, 0, idx);
	}
	public static int readInt() throws IOException {
		int ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');

		if (neg)
			return -ret;
		return ret;
	}

	public static long readLong() throws IOException {
		long ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');
		if (neg)
			return -ret;
		return ret;
	}

	public static double readDouble() throws IOException {
		double ret = 0, div = 1;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();

		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');

		if (c == '.') {
			while ((c = Read()) >= '0' && c <= '9') {
				ret += (c - '0') / (div *= 10);
			}
		}

		if (neg)
			return -ret;
		return ret;
	}

	private static void fillBuffer() throws IOException {
		bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
		if (bytesRead == -1)
			buffer[0] = -1;
	}

	private static byte Read() throws IOException {
		if (bufferPointer == bytesRead)
			fillBuffer();
		return buffer[bufferPointer++];
	}

	public void close() throws IOException {
		if (din == null)
			return;
		din.close();
	}

	static void print(Object o) {
		pr.print(o);
	}

	static void println(Object o) {
		pr.println(o);
	}

	static void flush() {
		pr.flush();
	}

	static void println() {
		pr.println();
	}

	static void exit() throws IOException {
		din.close();
		pr.close();
		System.exit(0);
	}
}