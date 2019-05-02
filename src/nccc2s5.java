import java.util.*;
import java.io.*;

public class nccc2s5 {
	static BufferedReader in;
	static StringTokenizer as;
	public static int[] par, rank;
	public static boolean[] vis;
	public static ArrayList<p> adj[];
	public static ArrayList<p1> edges;
	public static ArrayList<p1> temp;
	
	public static class p {
		int y, v;
		public p(int y1, int v1) {
			y = y1; v = v1;
		}
	}
	
	public static class p1 implements Comparable<p1> {
		int x, y, z;
		public p1(int x1, int y1, int z1) {
			x = x1; y = y1; z = z1;
		}
		public int compareTo(p1 f) {
			if(z == f.z) return Integer.compare(x, f.z);
			return -Integer.compare(z, f.z);
		}
	}
	
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
		if(a!=b) {
			if(rank[a] > rank[b]) {
				int temp = a;
				a = b;
				b = temp;
			}
			par[b] = a;
			if(rank[a] == rank[b]) rank[a]++;
		}
	}
	
	public static void mst() {
		for(int i=0;i<temp.size();i++) {
			p1 cur = temp.get(i);
			// System.out.println("value check: " + cur.x + " " + cur.y + " " + cur.z);
			if(find(cur.x) != find(cur.y)) {
				adj[cur.x].add(new p(cur.y, cur.z));
				adj[cur.y].add(new p(cur.x, cur.z));
				union(cur.x, cur.y);
			}
		}
	}
	
	public static void dfs(int v, int b, int w) {
		// System.out.println(adj[v].size());
		for(p cur: adj[v]) {
			if(!vis[cur.y] && cur.v >= w) {
				// System.out.println("dfs check: " + v + " " + cur.y + " " + cur.v);
				vis[cur.y] = true;
				if(vis[b]) break;
				dfs(cur.y, b, w);
			}
		}
	}
	
	public static void update(int N, int M) {
		par = new int[N+1]; rank = new int[N+1]; adj = new ArrayList[N+1];
		for(int j=1;j<=N;j++) {
			adj[j] = new ArrayList<p>();
			make(j);
		}
		mst();
	}
	
	public static int bsearch(int l, int r, p1 v) {
		while(l <= r) {
			int mid = (l+r)/2;
			if(temp.get(mid).z > v.z) l=mid+1;
			else if(temp.get(mid).z < v.z) r = mid-1;
			else {
				if(temp.get(mid).x > v.z) r = mid-1;
				else if(temp.get(mid).z < v.z) l = mid+1;
				return mid;
			}
		}
		return l;
	}

	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		int N = readInt(), M = readInt();
		edges = new ArrayList<p1>(); 
		for(int i=0;i<M;i++) {
			int x = readInt(), y = readInt(), v = readInt();
			edges.add(new p1(x, y, v));
		}
		temp = new ArrayList<p1>(edges);
		Collections.sort(temp);
		update(N, M);
		int Q = readInt();
		for(int i=0;i<Q;i++) {
			int op = readInt();
			if(op == 1) {
				int m = readInt();
				int x = readInt();
				p1 r = edges.remove(m-1);
				p1 r2 = new p1(r.x,r.y,x);
				edges.add(m-1, r2);
				int ind = bsearch(0, M-1, r);
				temp.remove(ind);
				ind = bsearch(0, M-2, r2);
				temp.add(ind, r2);
				update(N, M);
				// System.out.println("update check: " + edges.get(m-1).x + " " + edges.get(m-1).y + " " + edges.get(m-1).z);
			} else {
				int a = readInt(), b = readInt(), w = readInt();
				vis = new boolean[N+1];
				dfs(a,b,w);
				System.out.println(vis[b]?1:0);
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