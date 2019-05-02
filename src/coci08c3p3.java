import java.util.*;
import java.io.*;

public class coci08c3p3 {
	static BufferedReader in;
	static StringTokenizer as;

	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		String arr[][] = new String[9][9];
		for(int i=0;i<9;i++) arr[i] = read().split("");
		int cnt = 1;
		while(cnt > 0) {
			for(int i=0;i<9;i++) {
				
			}
		}
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
