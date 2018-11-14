import java.util.*;

public class ccc15s4 {
	
	static class p {
		ArrayList<E> adj = new ArrayList<E>();
		int shortestPath, hullCount;
		p() {
			shortestPath = Integer.MAX_VALUE;
			hullCount = -1;
		}
	}
	
	static class E {
		int v, w, h;
		E(int v0, int w0, int h0) {
			v = v0; w = w0; h = h0;
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int K = sc.nextInt(), N = sc.nextInt(), M = sc.nextInt();
		
		p places[] = new p[N+1];
		
		for(int i=0;i<=N;i++) {
			places[i] = new p();
		}
		
		for(int i=0;i<M;i++) {
			int a = sc.nextInt(), b = sc.nextInt(), t = sc.nextInt(), h = sc.nextInt();
			places[a].adj.add(new E(b, t, h));
			places[b].adj.add(new E(a, t, h));
		}
		
		int A = sc.nextInt(), B = sc.nextInt();
		
		Queue<p> Q = new LinkedList<p>();
		Queue<Integer> dis = new LinkedList<Integer>();
		Queue<Integer> hull = new LinkedList<Integer>();
		
		places[A].shortestPath = 0;
		
		Q.add(places[A]);
		dis.add(0);
		hull.add(K);
		
		while(!Q.isEmpty()) {
			p cur = Q.poll();
			int dist = dis.poll();
			int hullDmg = hull.poll();
			
			for(E v: cur.adj) {
				int hullHp = hullDmg - v.h;
				int weight = dist + v.w;
				p endpoint = places[v.v];
				
				if((weight < endpoint.shortestPath || hullHp > endpoint.hullCount) && hullHp > 0) {
					endpoint.shortestPath = Math.min(endpoint.shortestPath, weight);
					endpoint.hullCount = Math.max(endpoint.hullCount, hullHp);
					Q.add(endpoint);
					hull.add(hullHp);
					dis.add(weight);
				}
			}
		}
		
		if(places[B].shortestPath == Integer.MAX_VALUE) System.out.println(-1);
		else System.out.println(places[B].shortestPath);
		
	}

}