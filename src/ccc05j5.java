import java.util.*;
public class ccc05j5 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		while(true) {
			String s = sc.nextLine();
			if(s.equals("X")) break;
			//Main Function
			if(checkMonkeyWord(s)) System.out.println("YES");
			else System.out.println("NO");
		}
	}
	static boolean checkMonkeyWord(String s) {
		if(checkAWord(s)) return true;
		else {
			for(int i=0; i<s.length();i++) {
				if(s.charAt(i) == 'N' && checkAWord(s.substring(0, i)) && checkMonkeyWord(s.substring(i+1))) return true;
			}
		}
			return false;
	}
	
	static boolean checkAWord(String s) {
		if(s.isEmpty()) return false;
		if(s.equals("A")) return true;
		if(s.charAt(0) == 'B' && s.charAt(s.length()-1) == 'S')
			return checkMonkeyWord(s.substring(1, s.length()-1));
		return false;
	}
}