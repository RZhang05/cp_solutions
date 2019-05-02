import java.util.*;
import java.io.*;

public class sssp {
	static BufferedReader in;
	static StringTokenizer as;
	
	public static class p implements Comparable<p> {
		int y, v;
		public p(int y1, int v1) {
			y = y1; v = v1;
		}
		public int compareTo(p z) {
			return Integer.compare(v, z.v);
		}
	}

	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		int N = readInt(), M = readInt();
		ArrayList<p> adj[] = new ArrayList[N+1];
		for(int i=1;i<=N;i++) adj[i] = new ArrayList<p>();
		for(int i=0;i<M;i++) {
			int u = readInt(), v = readInt(), w = readInt();
			adj[u].add(new p(v,w));
			adj[v].add(new p(u,w));
		}
		int dis[] = new int[N+1];
		for(int i=2;i<=N;i++) dis[i] = Integer.MAX_VALUE;
		PriorityQueue<p> pq = new PriorityQueue<p>();
		pq.add(new p(1,0));
		while(!pq.isEmpty()) {
			p cur = pq.poll();
			for(p z: adj[cur.y]) {
				if(dis[cur.y] + z.v < dis[z.y]) {
					dis[z.y] = dis[cur.y] + z.v;
					pq.add(new p(z.y, dis[z.y]));
				}
			}
		}
		for(int i=1;i<=N;i++) System.out.println(dis[i]==Integer.MAX_VALUE?-1:dis[i]);
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
