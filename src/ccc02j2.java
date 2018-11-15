import java.util.Scanner;

public class ccc02j2 {
	public static void main(String[]args) {

		StringBuilder stringBuilder = new StringBuilder();
		Scanner sc = new Scanner (System.in);
		String[] conson = {"a","o","e","i","u","y"};
		int d = 0;
		int e = 0;


		for(int i = 0; i < 101; i++) {

			String Ameri = sc.nextLine();
			
			if (Ameri.equals("quit!")) {
				break;
			}
			
			else if (Ameri.length() <= 4 || Ameri.contains("or") == false) {
				System.out.println(Ameri);
			}
			
			else if (Ameri.contains("oor")) {
				System.out.println(Ameri);
			}
			
			else if (Ameri.contains("ort")) {
				System.out.println(Ameri);
			}
			
			else if (Ameri.length() >= 4) {
				String[] Ameriword = Ameri.split("");
				int Length = Ameriword.length;
				String change = Ameriword[Length-3] + Ameriword[Length-2] + Ameriword[Length-1] ;
				if (change.endsWith("or") && change.endsWith("oor") == false) {
					change = Ameriword[Length-3] + "our";

					for (int f = 0; f < (Ameri.length() -3); f ++) {
						stringBuilder.append(Ameriword[f]);
					}

					String finalString = stringBuilder.toString();
					System.out.println(finalString + change);
					stringBuilder.setLength(0);
				}
			}
		}
	}
}