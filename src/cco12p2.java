import java.util.*;
import java.io.*;

public class cco12p2 {
	public static class p implements Comparable<p> {
		int y, w;
		public p(int y1, int w1) {
			y = y1; w = w1;
		}
		public int compareTo(p z) {
			return Integer.compare(w, z.w);
		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt();
		ArrayList<p> adj[] = new ArrayList[N+1];
		int dis[] = new int[N+1], dis2[] = new int[N+1];
		for(int i=1;i<=N;i++) {
			adj[i] = new ArrayList<p>();
			dis[i] = Integer.MAX_VALUE;
			dis2[i] = Integer.MAX_VALUE;
		}
		for(int i=0;i<M;i++) {
			int a = readInt(), b = readInt(), w = readInt();
			adj[a].add(new p(b, w));
			//adj[b].add(new p(a, w));
		}
		PriorityQueue<p> pq = new PriorityQueue<p>();
		dis[1] = 0;
		pq.add(new p(1,0));
		while(!pq.isEmpty()) {
			p cur = pq.poll();
			for(p z: adj[cur.y]) {
				if(cur.w + z.w < dis[z.y]) {
					dis2[z.y] = dis[z.y]; 
					dis[z.y] = cur.w + z.w;
					pq.add(new p(z.y, dis[z.y]));
				} else if(cur.w + z.w != dis[z.y] && cur.w + z.w < dis2[z.y]) {
					dis2[z.y] = cur.w + z.w;
					pq.add(new p(z.y, dis2[z.y]));
				}
			}
		}
		// for(int i=1;i<=N;i++) System.out.println(dis[i]);
		pr.println(dis2[N]==Integer.MAX_VALUE?-1:dis2[N]);
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