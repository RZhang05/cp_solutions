import java.util.*;
import java.io.*;

public class ds2 {
	static BufferedReader in;
	static StringTokenizer as;
	
	public static class p {
		int x, y;
		public p(int x1, int y1) {
			x = x1; y = y1;
		}
	}
	
	public static int[] par, rank;
	
	public static void make(int v) {
		par[v] = v;
		rank[v] = 0;
	}
	
	public static void union(int a, int b) {
		a = find(a); b = find(b);
		if(a!=b) {
			if(rank[a] < rank[b]) {
				int temp = a;
				a = b;
				b = temp;
			}
			par[b] = a;
			if(rank[a]==rank[b]) rank[a]++;
		}
	}
	
	public static int find(int v) {
		if(v==par[v]) return v;
		return par[v] = find(par[v]);
	}

	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		int N = readInt(), M = readInt();
		par = new int[N+1]; rank = new int[N+1];
		ArrayList<p> edges = new ArrayList<p>();
		for(int i=0;i<=N;i++) make(i);
		for(int i=0;i<M;i++) {
			edges.add(new p(readInt(), readInt()));
		}
		ArrayList<Integer> graph = new ArrayList<Integer>();
		int cnt = 1;
		for(p cur: edges) {
			if(find(cur.x)!=find(cur.y)) {
				graph.add(cnt);
				union(cur.x,cur.y);
			}
			cnt++;
		}
		if(graph.size()!=N-1) System.out.println("Disconnected Graph");
		else for(int i=0;i<graph.size();i++) System.out.println(graph.get(i));
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
