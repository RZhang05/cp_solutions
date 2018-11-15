import java.util.Scanner;

public class ccc01j2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		
		int x = sc.nextInt();
		int m = sc. nextInt();
		
		
		for (int i = 0; i < m; i ++) {
			int value = x*i%m;
			if (value == 1){
				System.out.println(i);
				i = m;
			}
			if (i == m - 1) {
				if (value != 1) {
					System.out.println("No such integer exists.");
				}
			}
		}
		
	}

}