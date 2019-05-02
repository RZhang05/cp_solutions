import java.util.*;
import java.io.*;

public class dwite11c2p5 {
	static BufferedReader in;
	static StringTokenizer as;
	
	public static int[] par, rank;
	public static HashMap<String, Integer> hm;
	
	public static int find(int v) {
		if(v == par[v]) return v;
		return par[v] = find(par[v]);
	}
	
	public static void make(int v) {
		par[v] = v;
		rank[v] = 0;
	}
	
	public static void union(int a, int b) {
		a = find(a); b = find(b);
		if(a != b) {
			if(rank[a] < rank[b]) {
				int temp = a;
				a = b;
				b = temp;
			}
			par[b] = a;
			if(rank[a] == rank[b]) rank[a]++;
		}
	}
	
	public static void solve() throws IOException {
		int N = readInt();
		par = new int[200002]; rank = new int[200002];
		for(int i=0;i<200002;i++) make(i);
		hm = new HashMap<String, Integer>();
		for(int i=0;i<N;i++) {
			String S = read(), x = read(), y = read();
			if(!hm.containsKey(x)) hm.put(x, hm.size());
			if(!hm.containsKey(y)) hm.put(y, hm.size());
			if(S.equals("p")) union(hm.get(x), hm.get(y));
			else System.out.println(find(hm.get(x))==find(hm.get(y))?"connected":"not connected");
		}
	}

	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		for(int i=0;i<5;i++) solve();
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
