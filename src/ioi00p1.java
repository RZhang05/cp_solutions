import java.util.*;

public class ioi00p1 {
	public static int LCS(String X, String Y) {
		int m = X.length(), n = Y.length(), prev;
		int[] curr = new int[n + 1];

		for (int i = 0; i <= m; i++) {
			prev = curr[0];
			for (int j = 0; j <= n; j++) {
				int backup = curr[j];
				if (i == 0 || j == 0) curr[j] = 0;
				else {
					if (X.charAt(i - 1) == Y.charAt(j - 1)) curr[j] = prev + 1;
					else curr[j] = Integer.max(curr[j], curr[j - 1]);
				}
				prev = backup;
			}
		}

		return curr[n];
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		sc.nextLine();
		String X = sc.nextLine(), Y = "";
		for(int i=0;i<X.length();i++) {
			Y = X.charAt(i) + Y;
		}
		System.out.print(N - LCS(X, Y));
	}
}