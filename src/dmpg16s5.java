import java.util.*;
import java.io.*;
public class dmpg16s5 {
	
	static class point {
		long v; int pos;
		point(long val1, int pos1) {
			v = val1; pos = pos1;
		}
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken()), K = Integer.parseInt(st.nextToken());
		long max = 0;
		st = new StringTokenizer(br.readLine());
		int v[] = new int[N+K];
		long psa[] = new long[N+K];
		for(int i=0;i<N;i++) v[i] = Integer.parseInt(st.nextToken());
		for(int i=0;i<K;i++) v[N+i] = v[i];
		psa[0] = v[0];
		for(int i=1;i<N+K;i++) psa[i] = v[i] + psa[i-1];
		Deque<point> dq = new LinkedList<point>();
		int l = 0, r = 0;
		while(r < N+K) {
			point cur = new point(psa[r], r);
			while(!dq.isEmpty() && dq.getLast().v >= cur.v) {
				if(dq.getLast().v == cur.v) {
					dq.removeLast();
					break;
				} else dq.removeLast();
			}
			dq.addLast(cur);
			max = Math.max(max, psa[r] - dq.getFirst().v);
			r++;
			if(r-l>K) {
				l++;
				if(dq.getFirst().pos < l) dq.removeFirst();
			}
		}
		
		System.out.println(max);
	}

}