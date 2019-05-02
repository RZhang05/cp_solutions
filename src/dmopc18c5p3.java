import java.util.*;
import java.io.*;

public class dmopc18c5p3 {
	static BufferedReader in;
	static StringTokenizer as;

	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		int N = readInt(); long M = readLong();
		long v[] = new long[N];
		for(int i=0;i<N;i++) v[i] = readInt();
		int l=0,r=0,ans=0;
		long sum = v[r];
		while(r < N-1) {
			while(r < N-1 && sum < M) {
				r++;
				if(r < N) sum += v[r];
				ans = Math.max(ans, r-l);
			}
			sum -= v[l];
			l++;
		}
		System.out.println(ans);
	}

	static String read() throws IOException {
		while (as == null || !as.hasMoreTokens()) {
			as = new StringTokenizer(in.readLine().trim());
		}

		return as.nextToken();
	}

	static long readLong() throws IOException {
		return Long.parseLong(read());
	}

	static int readInt() throws IOException {
		return Integer.parseInt(read());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(read());
	}

	static String readLine() throws IOException {
		return in.readLine().trim();
	}

}
