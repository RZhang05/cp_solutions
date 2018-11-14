import java.util.*;
public class graph1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int M = sc.nextInt();
		
		int check[] = new int[N + 1]; boolean vis[] = new boolean[N + 1];
		ArrayList<Integer> adj[] = new ArrayList[N + 1];
		Queue<Integer> Q = new LinkedList<Integer>();
		
		
		for(int i=0;i<=N;i++) {
			adj[i] = new ArrayList<Integer>();
		}
		
		for(int i=1;i<=M;i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			adj[a].add(b);
			adj[b].add(a);
		}
		
		int X = sc.nextInt();
		int Y = sc.nextInt();
		
		Q.add(X); vis[X] = true;
		
		while(!Q.isEmpty()) {
			int cur = Q.poll();
			for(int v: adj[cur]) {
				if(!vis[v]) {
					Q.add(v); vis[v] = true;
				}
			}
		}
		
		if(vis[Y]) {
			System.out.println(1);
		} else {
			System.out.println(0);
		}
		
		

	}

}