import java.util.*;
import java.io.*;

public class cj20191bp1 {
	static BufferedReader in;
	static StringTokenizer as;
	
	public static void solve(int cnt) throws IOException {
		int P = readInt(), Q = readInt();
		int diffx[] = new int[Q+2], diffy[] = new int[Q+2];
		for(int i=0;i<P;i++) {
			int x= readInt(), y = readInt();
			char D = read().charAt(0);
			if(D=='N') {
				diffy[y+1]+=1;
				diffy[Q+1]-=1;
			} else if(D=='S') {
				diffy[0]+=1;
				diffy[y]-=1;
			} else if(D=='E') {
				diffx[x+1]+=1;
				diffx[Q+1]-=1;
			} else {
				diffx[0]+=1;
				diffx[x]-=1;
			}
		}
		int maxx = -1, maxy = -1;
		int x=-1, y=-1;
		for(int i=0;i<=Q;i++) {
			if(i>0) diffx[i] += diffx[i-1];
			if(diffx[i] > maxx) {
				maxx = diffx[i];
				x=i;
			}
			if(i>0) diffy[i] += diffy[i-1];
			if(diffy[i] > maxy) {
				maxy = diffy[i];
				y=i;
			}
		}
		System.out.println("Case #"+(cnt+1)+": " + x + " " + y);
	}

	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new InputStreamReader(System.in));
		int T = readInt(), cnt = 0;
		while(cnt < T) {
			solve(cnt);
			cnt++;;
		}
	}

	static String read() throws IOException {
		while (as == null || !as.hasMoreTokens()) {
			as = new StringTokenizer(in.readLine().trim());
		}

		return as.nextToken();
	}

	static long readLong() throws IOException {
		return Long.parseLong(read());
	}

	static int readInt() throws IOException {
		return Integer.parseInt(read());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(read());
	}

	static String readLine() throws IOException {
		return in.readLine().trim();
	}

}
