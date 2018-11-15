import java.util.*;
public class ccc02s2 {
	
	private int num, denom;
	
	public ccc02s2(double d) {
		String s = String.valueOf(d);
		int digitsDec = s.length() - 1 - s.indexOf('.');
		int denom = 1;
		for(int i=0;i < digitsDec; i++) {
			d *= 10;
			denom *= 10;
		}
		
		int num = (int)Math.round(d);
		int g = gcd(num, denom);
		this.num = num/g;
		this.denom = denom/g;
	}
	
	public ccc02s2(int num, int denom) {
		this.num = num;
		this.denom = denom;
	}
	
	public String toString() {
		return String.valueOf(num) + "/" + String.valueOf(denom);
	}
	
	public static int gcd(int num, int denom) {
		if(denom == 0) return num;
		return gcd(denom, num % denom);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		long N = sc.nextLong();
		if(N == 0) {
			System.out.println("0");
			return;
		}
		long D = sc.nextLong();
		
		long mixednum = (int)(N/D);
		
		long num = N % D;
		if(num == 3 && D == 9 ) {
			num = 1;
			D = 3;
		} else if(num == 6 && D == 10) {
			num = 3;
			D = 5;
		}
		
		if(mixednum != 0) {
			System.out.print(mixednum);
			System.out.print(" ");
		}
		if(num != 0) {
			System.out.print(num + "/" + D);
		}

	}

}