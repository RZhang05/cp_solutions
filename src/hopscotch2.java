import java.util.*;
import java.io.*;
public class hopscotch2 {
	
	static class point {
		long v, pos, prev;
		point(long v1, long pos1, long prev1) {
			v = v1; pos = pos1; prev = prev1;
		}
	}

	public static void main(String[] args) throws IOException {
		long N = readLong(), K = readLong();
		Deque<point> minQ = new LinkedList<point>();
		point[] p = new point[(int)N+1];
		ArrayList<Long> ans = new ArrayList<Long>();
		minQ.add(new point(0,0,-1));
		long l=0;
		for(long r=1;r<=N;r++) {
			long v = readLong() + minQ.getFirst().v;
			long prev = minQ.getFirst().pos;
			while(!minQ.isEmpty() && minQ.getLast().v >= v) minQ.removeLast();
			point temp = new point(v,r,prev);
			minQ.add(temp);
			p[(int)r] = temp;
			if(r-l+1>K) {
				l++;
				if(minQ.getFirst().pos < l) minQ.removeFirst();
			}
		}
		point temp = minQ.getFirst();
		pr.println(temp.v);
		long prev = temp.prev;
		while(prev != 0) {
			ans.add(prev);
			prev = p[(int)prev].prev;
		}
		for(int i=ans.size()-1;i>=0;i--) {
			pr.print(ans.get(i) + " ");
		}
		pr.print(temp.pos);
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