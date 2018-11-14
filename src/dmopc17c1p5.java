import java.util.*;
import java.io.*;
public class dmopc17c1p5 {
	
	static int MAXN = 1000005;
	static int BIT[] = new int[MAXN];
	
	static class p {
		int x, y;
		p(int x1, int y1) {
			x = x1; y = y1;
		}
	}
	
	static class query implements Comparable<query> {
		int l, r, idx;
		query(int l1, int r1, int idx1) {
			l = l1; r = r1; idx = idx1;
		}
		public int compareTo(query x) {
			return Integer.compare(l, x.l);
		}
	}
	
	static int qquery(int x) {
		int sum = 0;
		x++;
		for(;x>0;x-=(x&-x)) {
			sum += BIT[x];
		}
		return sum;
	}
	
	static void update(int x, int val) {
		x++;
		for(;x<=MAXN;x+=(x&-x)) {
			BIT[x] += val;
		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), Q = readInt();
		int[] A = new int[MAXN], ans = new int[MAXN];
		ArrayList<query> Qs = new ArrayList<query>();
		for(int i=0;i<N;i++) A[i] = readInt();
		for(int i=0;i<Q;i++) {
			int a = readInt(), b = readInt();
			a--; b--;
			Qs.add(new query(a, b, i));
		}
		Collections.sort(Qs, Collections.reverseOrder());
		update(N, 1);
		Stack<p> st = new Stack<p>();
		st.push(new p(N+1,N));
		for(int i=N-1, idx = 0;i>=0 && idx < Q;i--) {
			while(!st.isEmpty()) {
				p cur = st.peek();
				if(cur.x < A[i]) {
					update(cur.y, -1);
					st.pop();
				} else break;
			}
			st.push(new p(A[i], i));
			update(i,1);
			while(idx < Q && Qs.get(idx).l == i) {
				int n = qquery(Qs.get(idx).r);
				ans[Qs.get(idx).idx] = n;
				idx++;
			}
		}
		
		for(int i=0;i<Q;i++) {
			pr.println(ans[i]);
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