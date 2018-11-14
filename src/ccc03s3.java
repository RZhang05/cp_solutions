import java.util.*;
public class ccc03s3 {
	
	static String[][] house;
	static int r;
	static int c;
	static ArrayList<Integer> rooms = new ArrayList();
	static int index = 0;
	static int floorlength = 1;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int F = sc.nextInt();
		r = sc.nextInt();
		c = sc.nextInt();
		
		house = new String[r][c];
		
		for(int i=0; i<r;i++) {
			String[] line = sc.next().split("");
			house[i] = line;
		}
		
		for(int i=0;i<r;i++) {
			for(int j=0;j<c;j++) {
				if(house[i][j].equals(".")) {
					dfs(i, j);
					rooms.add(floorlength);
				}
				floorlength = 1;
			}
		}
		
		int rooms2[] = new int[rooms.size()];
		
		for(int i=0;i<rooms.size();i++) {
			rooms2[i] = rooms.get(i);
		}
		
		Arrays.sort(rooms2);
		int count = 0;
		int finalRoom = 0;
		for(int i=rooms2.length - 1;i>=0;i--) {
			if(count < F && count + rooms2[i] > F) break;
			count+=rooms2[i];
			finalRoom++;
		}
		
		if(finalRoom == 1) {
			System.out.println(finalRoom + " room, " + (F - count) + " square metre(s) left over");
		} else {
			System.out.println(finalRoom + " rooms, " + (F - count) + " square metre(s) left over");
		}
		
		
	}
	
	static void dfs(int i, int j) {
		house[i][j] = "I";
		if(i > 0 && !house[i - 1][j].equals("I")) {
			floorlength ++;
			dfs(i - 1, j);
		}
		if(i < r - 1) {
			if(i < r && !house[i + 1][j].equals("I")) {
				floorlength ++;
				dfs(i + 1, j);
			}
		}
		if(j > 0 && !house[i][j - 1].equals("I")) {
			floorlength ++;
			dfs(i, j - 1);
		}
		if(j < c - 1) {
			if(j < c && !house[i][j + 1].equals("I")) {
				floorlength ++;
				dfs(i, j + 1);
			}
		}
	}
}