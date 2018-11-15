import java.util.Scanner;

public class ccc01j1 {
	public static void main(String[]args) {
	
		Scanner sc = new Scanner(System.in);
	
		int H = sc.nextInt();
	
		String ast = "*";
		String space = " ";
		int spacing = H*2 - 2;
		int increase = 1;
		int decrease = Math.round(H/2);
	
		for(int i = 0; i < H; i++) {
			for(int e = 0; e < increase; e ++) {
				System.out.print(ast);
			}
			for(int e = 0; e < spacing; e++) {
				System.out.print(space);
			}
			for(int p = 0; p < increase; p ++) {
				System.out.print(ast);
			}
			System.out.println("");
			if(i < decrease) {
				spacing = spacing - 4;
				increase = increase + 2;
			}
			if(i >= decrease) {
				spacing = spacing + 4;
				increase = increase - 2;
			}
		}

	}
}