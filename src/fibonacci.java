import java.math.BigInteger;
import java.util.Scanner;

public class fibonacci {
	
	static void multiply(BigInteger a[][], BigInteger b [][]) {
		BigInteger res[][] = new BigInteger[2][2];
		for(int i=0;i<2;i++) {
			for(int j=0;j<2;j++) {
				res[i][j] = BigInteger.valueOf((long)0);
				for(int k=0;k<2;k++) {
					res[i][j] = res[i][j].add( (a[i][k].multiply(b[k][j]) ).remainder( BigInteger.valueOf( (long) 1000000007) ) );
					// System.out.print(a[i][k].multiply(b[k][j]) + " ");
				}
			}
		}
		
		// System.out.println();
		for(int i=0;i<2;i++) {
			for(int j=0;j<2;j++) {
				a[i][j] = res[i][j];
			}
		}
	}
	
	static BigInteger power(BigInteger F[][], BigInteger n) {
		BigInteger M[][] = {{BigInteger.ONE,BigInteger.ONE,BigInteger.ONE},{BigInteger.ONE,BigInteger.ZERO,BigInteger.ZERO}};
		if(n.equals(BigInteger.valueOf((long)1))) return ( (F[0][0].add(F[0][1])).remainder(BigInteger.valueOf((long)1000000007)) );
		power(F, n.divide(BigInteger.valueOf((long)2)));
		multiply(F,F);
		if(!n.remainder(BigInteger.valueOf((long)2)).equals(BigInteger.valueOf((long)0))) multiply(F, M);
		return (F[0][0].add(F[0][1]).remainder(BigInteger.valueOf((long)1000000007)));
	}
	
	static BigInteger findNthTerm(BigInteger n) {
		BigInteger F[][] = {{BigInteger.ONE,BigInteger.ONE,BigInteger.ONE},{BigInteger.ONE,BigInteger.ZERO,BigInteger.ZERO}};
		n = n.subtract(BigInteger.valueOf((long)2));
		// System.out.println(n);
		return power(F, n);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		BigInteger N = sc.nextBigInteger();
		//N = N.subtract(BigInteger.valueOf((long)1));		
		System.out.println(findNthTerm(N));

	}


}