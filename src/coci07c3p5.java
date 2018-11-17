import java.util.*;
import java.io.*;
public class coci07c3p5 {
	
	static long dp[][][] = new long[20][200][2];
	static long d[] = new long[20];
	static int S;
	
	static long solve(int pos, int sum, int limit) {
		if(pos < 0) return sum==S?1:0;
		if(dp[pos][sum][limit]>-1) return dp[pos][sum][limit];
		long up = limit==1?d[pos]:9;
		long ret = 0;
		for(int i=0;i<=up;i++) ret += solve(pos-1,sum+i,i==d[pos] && limit==1? 1:0);
		return dp[pos][sum][limit] = ret;
	}
	
	static long solve(long x) {
		int n = 0;
		for(int i=0;i<20;i++)
			for(int j=0;j<200;j++)
				for(int k=0;k<2;k++)
					dp[i][j][k] = -1;
		for(;x>0;x/=10) d[n++] = x%10L;
		return solve(n-1, 0, 1);
	}

	public static void main(String[] args) throws IOException {
		long a = readLong(), b = readLong(); S = readInt();
		pr.println(solve(b) - solve(a-1));
		long lo = a, hi = b, mid = 0, ans = 0;
		while(lo <= hi) {
			mid = (lo + hi)/2;
			if(solve(mid)-solve(lo-1)>0) {
				ans = mid; hi = mid-1;
			} else lo = mid+1;
		}
		pr.println(ans);
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