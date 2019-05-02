import java.util.*;
import java.io.*;

public class dmopc16c4p5 {
	static BufferedReader in;
	static StringTokenizer as;
	
	public static int[] par, rank, dis;
	public static ArrayList<p1> adj[];
	public static boolean[] vis;
	
	public static void make(int v) {
		par[v] = v;
		rank[v] = 0;
	}
	
	public static int find(int v) {
		if(v == par[v]) return v;
		return par[v] = find(par[v]);
	}
	
	public static void union(int a, int b) {
		a = find(a); b = find(b);
		if(a != b) {
			if(rank[a] > rank[b]) {
				int temp = a;
				a = b;
				b = temp;
			}
			par[b] = a;
			if(rank[a] == rank[b]) rank[a]++;
		}
	}
	
	public static class p implements Comparable<p>{
		int x, y, v;
		public p(int x1, int y1, int v1) {
			x = x1; y = y1; v = v1;
		}
		public int compareTo(p z) {
			return -Integer.compare(v, z.v);
		}
	}
	
	public static class p1 {
		int y, v;
		public p1(int y1, int v1) {
			y = y1; v = v1;
		}
	}
	
	public static void dfs(int u) {
		// System.out.println(u);
		for(p1 cur: adj[u]) {
			int y = cur.y, v = cur.v;
			if(!vis[y]) {
				vis[y] = true;
				dis[y] = Math.min(dis[u], v);
				dfs(y);
			}
		}
	}

	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		int N = readInt(), M = readInt();
		par = new int[N+1]; rank = new int[N+1];
		ArrayList<p> edges = new ArrayList<p>();
		for(int i=0;i<M;i++) {
			int a = readInt(), b = readInt(), p = readInt();
			edges.add(new p(a, b, p));
		}
		adj = new ArrayList[N+1];
		for(int i=1;i<=N;i++) adj[i] = new ArrayList<p1>();
		for(int i=1;i<=N;i++) make(i);
		Collections.sort(edges);
		for(int i=0;i<edges.size();i++) {
			p cur = edges.get(i);
			if(find(cur.x) != find(cur.y)) {
				adj[cur.x].add(new p1(cur.y, cur.v));
				adj[cur.y].add(new p1(cur.x, cur.v));
				union(cur.x, cur.y);
			}
		}
		dis = new int[N+1]; vis = new boolean[N+1];
		for(int i=1;i<=N;i++) dis[i] = Integer.MAX_VALUE;
		vis[1] = true;
		dfs(1);
		for(int i=1;i<=N;i++) System.out.println(dis[i]==Integer.MAX_VALUE?0:dis[i]);
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