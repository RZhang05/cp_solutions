import java.util.*;
import java.io.*;
public class cco13p2 {
	
	static class p{
		int v, pos;
		p(int v1, int pos1) {
			v = v1; pos = pos1;
		}
	}
	
	static p comp(p v, p x) {
		if(v.v > x.v) return v;
		else return x;
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt();
		int s = (int)Math.pow(2, N+1);
		p[] t = new p[s];
		for(int i=0;i<s/2;i++) {
			t[s/2+i] = new p(readInt(), i+1);
		}
		for(int i=(int)Math.pow(2, N)-1;i>0;i--) {
			t[i] = comp(t[2*i], t[2*i+1]);
		}
		for(int i=0;i<M;i++) {
			String op = read();
			if(op.equals("R")) {
				int pos = readInt(), S = readInt();
				int realPos = pos+s/2-1;
				t[realPos] = new p(S, pos);
				realPos /= 2;
				while(realPos > 0) {
					t[realPos] = comp(t[2*realPos], t[2*realPos+1]);
					realPos /= 2;
				}
			} else if(op.equals("W")) pr.println(t[1].pos);
			else {
				int pos = readInt();
				int realPos = pos+s/2-1;
				int count = 0;
				realPos/=2;
				while(realPos > 0) {
					if(t[realPos].pos == pos) count++;
					else break;
					realPos /= 2;
				}
				pr.println(count);
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