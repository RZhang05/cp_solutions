import java.util.*;
public class gfssoc3s3 {
	
	static long MOD = 1000000000;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		long testa = 0;
		
		if(a.length() > 19) testa = (long) 1e19;
		else testa = Long.parseLong(a);
		
		
		if(testa == 1) System.out.println("9");
		else {
			long half = testa/2; long rest = testa-half;
            System.out.println((pow(10,rest) + pow(10,half) - 2 + MOD)%MOD);
		}
	}
	
	public static long pow(long base, long exp) {
        if(exp == 0) return 1;
        if(exp == 1) return base;
        if(exp % 2 == 0) { long half = pow(base, exp/2); return half*half%MOD;}
        else { long half = pow(base, (exp-1)/2); return ((base*half%MOD)*half)%MOD;}
    }

}