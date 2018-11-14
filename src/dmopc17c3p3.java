import java.util.*;
import java.io.*;
public class dmopc17c3p3 {
	
	static class p implements Comparable<p>{
		ArrayList<Integer> subs;
		int v;
		p(ArrayList<Integer> t, int v1) {
			subs = t; v = v1;
		}
		public int compareTo(p z) {
			return Integer.compare(v, z.v);
		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt();
		int p[] = new int[N];
		for(int i=0;i<N;i++) p[i] = readInt();
		ArrayList<p> subs = new ArrayList<p>();
		ArrayList<Integer> temp;
		for(int i=0;i<(1<<N);i++) {
			int count = 0;
			temp = new ArrayList<Integer>();
			for(int j=0;j<N;j++) {
				if((i & (1<<j)) > 0) {
					temp.add(j+1);
					count += p[j];
				}
			}
			subs.add(new p(temp, count));
		}
		Collections.sort(subs);
		int smallest = Integer.MAX_VALUE;
		ArrayList<Integer> f = new ArrayList<Integer>();
		ArrayList<Integer> g = new ArrayList<Integer>();
		for(int i=subs.size()-1;i>0;i--) {
			p prev = subs.get(i-1);
			p cur = subs.get(i);
			smallest = Math.min(smallest, cur.v - prev.v);
			if(cur.v - prev.v == smallest) {
				f = cur.subs;
				g = prev.subs;
			}
		}
		for(int i=0;i<f.size();i++) {
			pr.print(f.get(i) + " ");
		}
		pr.println("");
		for(int i=0;i<g.size();i++) {
			pr.print(g.get(i) + " ");
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