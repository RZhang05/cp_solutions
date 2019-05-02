import java.util.*;
import java.io.*;

public class dpd {
	static BufferedReader in; 
	static StringTokenizer as;

	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		int N = readInt(), W = readInt();
		int v[] = new int[N+1], w[] = new int[N+1];
		int ind = 1, change = -1;
		long dp[][] = new long[2][W+1];
		for(int i=1;i<=N;i++) {
			w[i] = readInt();
			v[i] = readInt();
		}
		for(int i=1;i<=N;i++) {
			for(int j=1;j<=W;j++) {
				if(w[i] > j) dp[ind][j] = dp[ind+change][j];
				else dp[ind][j] = Math.max(dp[ind+change][j], v[i]+dp[ind+change][j-w[i]]);
			}
			ind += change;
			change = -change;
		}
		System.out.println(dp[ind+change][W]);
	}

	static String read() throws IOException {
		while (as == null || !as.hasMoreTokens ())
		{
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
