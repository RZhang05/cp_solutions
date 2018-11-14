import java.io.*;
import java.util.*;
public class ccc13s4 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		Queue<Integer> Q = new LinkedList<Integer>();
		ArrayList<Integer>[] adj = new ArrayList[N + 1];
		
		for(int i=0;i<=N;i++) {
			adj[i] = new ArrayList<Integer>();
		}
		
		for(int i = 1;i <= M; i++) {
			st = new StringTokenizer(br.readLine());
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			adj[u].add(v);
		}
		
		st = new StringTokenizer(br.readLine());
		int p = Integer.parseInt(st.nextToken());
		int q = Integer.parseInt(st.nextToken());
		
		boolean vis[] = new boolean[N + 1];
		Q.add(p); vis[p] = true;
		
		while(!Q.isEmpty()) {
			int cur = Q.poll();
			for(int v: adj[cur]) {
				if(!vis[v]) {
					Q.add(v); vis[v] = true;
				}
			}
		}
		
		if(vis[q]) {
			System.out.println("yes");
		} else {   
			boolean vis2[] = new boolean[N + 1];
			Q.add(q); vis2[q] = true;
			while(!Q.isEmpty()) {
				int cur = Q.poll();
				for(int v: adj[cur]) {
					if(!vis2[v]) {
						Q.add(v); vis2[v] = true;
					}
				}
			}
			if(vis2[p]) {
				System.out.println("no");
			} else {
				System.out.println("unknown");
			}
		}
		
		
		
	}

}