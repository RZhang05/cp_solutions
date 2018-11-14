import java.util.*;
import java.io.*;
public class dmopc13c1p4 {
	public static class Point{
		int r, c;
		Point(int r0, int c0){
			r = r0;
			c = c0;
		}
	}
	public static void main(String[]args) throws NumberFormatException, IOException{
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		Integer t = Integer.parseInt(bf.readLine());
		for(int i = 0; i < t; i++){
			StringTokenizer st = new StringTokenizer(bf.readLine());
			Integer w = Integer.parseInt(st.nextToken());
			Integer l = Integer.parseInt(st.nextToken());
			int [][] way = {{0,1}, {1,0}, {-1,0}, {0,-1}};
			boolean [][] vis = new boolean [l][w];
			int [][] dis = new int[l][w];
			int x = 0,  y = 0;
			int xe = 0, ye = 0;
			char [][] ac = new char [l][w];
			for(int j = 0; j < l; j++){
				StringTokenizer st1 = new StringTokenizer(bf.readLine());
				ac[j] = st1.nextToken().toCharArray();
				for(int k = 0; k < w; k++){
					if(ac[j][k] == 'C'){
						x = j;
						y = k;
					}
					else if(ac[j][k] == 'W'){
						xe = j;
						ye = k;
					}
				}
			}
			Queue<Point> Q = new LinkedList<Point>();
			Q.add(new Point(x, y));
			vis[x][y] = true; dis[x][y] = 0;
			while(! Q.isEmpty()){
				Point cur = Q.poll();
				for(int j = 0; j < 4; j++){
					int nx = cur.r + way[j][0], ny = cur.c + way[j][1];
					if(nx >= 0 && nx <= l-1 && ny >= 0 && ny <= w-1 && ac[nx][ny] != 'X' && vis[nx][ny] == false){
						Q.add(new Point(nx, ny)); vis[nx][ny] = true;
						dis[nx][ny] = dis[cur.r][cur.c] + 1;
					}
				}
			}
			if(dis[xe][ye] >= 60 || dis[xe][ye] == 0) System.out.println("#notworth");
			else System.out.println(dis[xe][ye]);
		}
	}
}