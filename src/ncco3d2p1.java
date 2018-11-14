import java.util.*;
import java.io.*;
public class ncco3d2p1 {
	
	static int MAXN = 50005;
	static node segTree[] = new node[4*MAXN];
	
	static class node {
		int l, r, minV, maxV;
		public node(int l1, int r1, int v1, int v2) {
			l = l1; r = r1; minV = v1; maxV = v2;
		}
	}
	
	static void pushup(int idx) {
		segTree[idx].minV = Math.min(segTree[idx<<1].minV, segTree[idx<<1|1].minV);
		segTree[idx].maxV = Math.max(segTree[idx<<1].maxV, segTree[idx<<1|1].maxV);
	}
	
	static void build(int l, int r, int idx) {
		segTree[idx] = new node(0,0,0,0);
		segTree[idx].l = l; segTree[idx].r = r;
		segTree[idx].minV = -1; segTree[idx].maxV = -1;
		if(l!=r) {
			int mid = (l+r)/2;
			build(l, mid, idx<<1);
			build(mid+1, r, idx<<1|1);
			pushup(idx);
		}
	}
	
	static void update(int pos, int val, int idx) {
		if(segTree[idx].l == segTree[idx].r) {
			segTree[idx].minV = val;
			segTree[idx].maxV = val;
			return;
		}
		int mid = (segTree[idx].l + segTree[idx].r)/2;
		if(pos <= mid) update(pos, val, idx<<1);
		else update(pos, val, idx<<1|1);
		pushup(idx);
	}
	
	static int qmin(int l, int r, int idx) {
	    if(segTree[idx].l == l && segTree[idx].r == r) {
	        return segTree[idx].minV;
	    }
	    int mid = (segTree[idx].l + segTree[idx].r)/2;
	    if(r<=mid) return qmin(l, r, idx<<1);
	    else if(l>mid) return qmin(l, r, idx<<1|1);
	    else return Math.min(qmin(l, mid, idx<<1), qmin(mid+1, r, idx<<1|1));
	}
	
	static int qmax(int l, int r, int idx) {
	    if(segTree[idx].l == l && segTree[idx].r == r) {
	        return segTree[idx].maxV;
	    }
	    int mid = (segTree[idx].l + segTree[idx].r)/2;
	    if(r<=mid) return qmax(l, r, idx<<1);
	    else if(l>mid) return qmax(l, r, idx<<1|1);
	    else return Math.max(qmax(l, mid, idx<<1), qmax(mid+1, r, idx<<1|1));
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), Q = readInt();
		build(1,N,1);
		for(int i=1;i<=N;i++) {
			update(i, readInt(), 1);
		}
		
		for(int i=0;i<Q;i++) {
			int a = readInt(), b = readInt();
			pr.println(qmax(a,b,1) - qmin(a,b,1));
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