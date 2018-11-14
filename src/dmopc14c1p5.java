import java.util.*;
public class dmopc14c1p5 {
	
	static class pair {
		int x, y;
		public pair(int a, int b) {
			x = a; y = b;
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int R = sc.nextInt(), C = sc.nextInt();
		int sx = sc.nextInt(), sy = sc.nextInt();
		int mx = sc.nextInt(), my = sc.nextInt();
		
		String[][] map = new String[R][C];
		boolean[][] vis = new boolean[R][C];
		int[][] dis = new int[R][C];
		Queue<pair> Q = new LinkedList<pair>();
		
		for(int i=0;i<R;i++) {
			String S = sc.next();
			for(int j=0;j<C;j++) {
				map[i][j] = S.substring(j, j + 1);
			}
		}
		
		Q.add(new pair(sx, sy)); vis[sx][sy] = true; dis[sx][sy] = 0;
		while(!Q.isEmpty()) {
			pair cur = Q.poll();
			// System.out.println(cur.x + " " + cur.y + ": " + vis[cur.x][cur.y]);
			if(cur.x > 0 && map[cur.x - 1][cur.y].equals("O") && !vis[cur.x - 1][cur.y]) {
				vis[cur.x - 1][cur.y] = true;
				dis[cur.x - 1][cur.y] = dis[cur.x][cur.y] + 1;
				Q.add(new pair(cur.x - 1, cur.y));
			}
			if(cur.y > 0 && map[cur.x][cur.y - 1].equals("O") && !vis[cur.x][cur.y - 1]) {
				vis[cur.x][cur.y - 1] = true;
				dis[cur.x][cur.y - 1] = dis[cur.x][cur.y] + 1;
				Q.add(new pair(cur.x, cur.y - 1));
			}
			if(cur.x < R - 1 && map[cur.x + 1][cur.y].equals("O") && !vis[cur.x + 1][cur.y]) {
				vis[cur.x + 1][cur.y] = true;
				dis[cur.x + 1][cur.y] = dis[cur.x][cur.y] + 1;
				Q.add(new pair(cur.x + 1, cur.y));
			}
			if(cur.y < C - 1 && map[cur.x][cur.y + 1].equals("O") && !vis[cur.x][cur.y + 1]) {
				vis[cur.x][cur.y + 1] = true;
				dis[cur.x][cur.y + 1] = dis[cur.x][cur.y] + 1;
				Q.add(new pair(cur.x, cur.y + 1));
			}
		}
		
		int T = sc.nextInt();
		int minDis = Integer.MAX_VALUE;
		for(int i=0;i<T;i++) {
			int a = sc.nextInt(), b = sc.nextInt();
			if(vis[a][b]) minDis = Math.min(minDis, dis[a][b]);
		}
		
		// System.out.println(dis[mx][my] + " " + minDis);
		int totDis = dis[mx][my] - minDis;
		if(totDis < 0) totDis = 0;
		System.out.println(totDis);
	}

}