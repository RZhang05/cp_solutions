import java.util.*;
import java.io.*;
public class ccc18s3 {

	static class p {
		int x, y;
		p(int x1, int y1) {
			x = x1; y = y1;
		}
	}

	public static void main(String[] args) throws IOException {
		int N = readInt(), M = readInt();
		String map[][] = new String[N][M];
		ArrayList<p> cams = new ArrayList<p>();
		p start = new p(0,0);
		for(int i=0;i<N;i++) {
			String S[] = read().split("");
			for(int j=0;j<M;j++) {
				map[i][j] = S[j];
				if(S[j].equals("C")) cams.add(new p(i,j));
				else if(S[j].equals("S")) start = new p(i,j);
			}
		}
		boolean valid = true;
		for(int i=0;i<cams.size();i++) {
			p cur = cams.get(i);
			for(int j=cur.x+1;j<N;j++) {
				if(map[j][cur.y].equals("W")) break;
				else if(map[j][cur.y].equals(".")) map[j][cur.y] = "N";
				else if(map[j][cur.y].equals("S")) valid = false;
			}
			for(int j=cur.x-1;j>0;j--) {
				if(map[j][cur.y].equals("W")) break;
				else if(map[j][cur.y].equals(".")) map[j][cur.y] = "N";
				else if(map[j][cur.y].equals("S")) valid = false;
			}
			for(int j=cur.y+1;j<M;j++) {
				if(map[cur.x][j].equals("W")) break;
				else if(map[cur.x][j].equals(".")) map[cur.x][j] = "N";
				else if(map[cur.x][j].equals("S")) valid = false;
			}
			for(int j=cur.y-1;j>0;j--) {
				if(map[cur.x][j].equals("W")) break;
				else if(map[cur.x][j].equals(".")) map[cur.x][j] = "N";
				else if(map[cur.x][j].equals("S")) valid = false;
			}
			map[cur.x][cur.y] = "W"; 
		}
		int dis[][] = new int[N][M];
		if(valid) {
			Queue<p> Q = new LinkedList<p>();
			Q.add(start);
			for(int i=0;i<N;i++) {
				for(int j=0;j<M;j++) {
					if(map[i][j].equals("W") || map[i][j].equals("N")) dis[i][j] = -1;
					else dis[i][j] = Integer.MAX_VALUE;
				}
			}
			dis[start.x][start.y] = 0;
			while(!Q.isEmpty()) {
				p cur = Q.poll();
				if(map[cur.x][cur.y].equals(".") || map[cur.x][cur.y].equals("S")) {
					if(dis[cur.x+1][cur.y] > dis[cur.x][cur.y]+ 1) {
						dis[cur.x+1][cur.y] = dis[cur.x][cur.y] + 1;
						Q.add(new p(cur.x + 1, cur.y));
					}
					if(dis[cur.x-1][cur.y] > dis[cur.x][cur.y]+1) {
						dis[cur.x-1][cur.y] = dis[cur.x][cur.y] + 1;
						Q.add(new p(cur.x-1, cur.y));
					}
					if(dis[cur.x][cur.y+1] > dis[cur.x][cur.y]+1) {
						dis[cur.x][cur.y+1] = dis[cur.x][cur.y]+1;
						Q.add(new p(cur.x, cur.y+1));
					}
					if(dis[cur.x][cur.y-1] > dis[cur.x][cur.y]+1) {
						dis[cur.x][cur.y-1] = dis[cur.x][cur.y]+1;
						Q.add(new p(cur.x, cur.y-1));
					}
				} else if(map[cur.x][cur.y].equals("U")) {
					if(dis[cur.x-1][cur.y]>dis[cur.x][cur.y]) {
						dis[cur.x-1][cur.y]= dis[cur.x][cur.y];
						Q.add(new p(cur.x-1, cur.y));
					}
				} else if(map[cur.x][cur.y].equals("L")) {
					if(dis[cur.x][cur.y-1] > dis[cur.x][cur.y]) {
						dis[cur.x][cur.y-1] = dis[cur.x][cur.y];
						Q.add(new p(cur.x, cur.y-1));
					}
				} else if(map[cur.x][cur.y].equals("R")) {
					if(dis[cur.x][cur.y+1] > dis[cur.x][cur.y]) {
						dis[cur.x][cur.y+1] = dis[cur.x][cur.y];
						Q.add(new p(cur.x, cur.y+1));
					}
				} else if(map[cur.x][cur.y].equals("D")) {
					if(dis[cur.x+1][cur.y] > dis[cur.x][cur.y]) {
						dis[cur.x+1][cur.y] = dis[cur.x][cur.y];
						Q.add(new p(cur.x+1, cur.y));
					}
				}
			}
		}
		if(!valid) {
			for(int i=0;i<N;i++) {
				for(int j=0;j<M;j++) {
					if(map[i][j].equals(".") || map[i][j].equals("N")) pr.println(-1);
				}
			}
		} else {
			for(int i=0;i<N;i++) {
				for(int j=0;j<M;j++) {
					if(map[i][j].equals(".") || map[i][j].equals("N")) {
						if(dis[i][j] == Integer.MAX_VALUE) pr.println(-1);
						else pr.println(dis[i][j]);
					}
				}
			}
		}
		pr.close();
	}

	final private static int BUFFER_SIZE = 1 << 16;
	private static DataInputStream din = new DataInputStream(System.in);
	private static byte[] buffer = new byte[BUFFER_SIZE];
	private static int bufferPointer = 0, bytesRead = 0;
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

	public static String readLine() throws IOException {
		byte[] buf = new byte[64]; // line length
		int cnt = 0, c;
		while ((c = Read()) != -1) {
			if (c == '\n')
				break;
			buf[cnt++] = (byte) c;
		}
		return new String(buf, 0, cnt);
	}
	public static String read() throws IOException{
		byte[] ret = new byte[1024];
		int idx = 0;
		byte c = Read();
		while (c <= ' ') {
			c = Read();
		}
		do {
			ret[idx++] = c;
			c = Read();
		} while (c != -1 && c != ' ' && c != '\n' && c != '\r');
		return new String(ret, 0, idx);
	}
	public static int readInt() throws IOException {
		int ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');

		if (neg)
			return -ret;
		return ret;
	}

	public static long readLong() throws IOException {
		long ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');
		if (neg)
			return -ret;
		return ret;
	}

	public static double readDouble() throws IOException {
		double ret = 0, div = 1;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();

		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');

		if (c == '.') {
			while ((c = Read()) >= '0' && c <= '9') {
				ret += (c - '0') / (div *= 10);
			}
		}

		if (neg)
			return -ret;
		return ret;
	}

	private static void fillBuffer() throws IOException {
		bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
		if (bytesRead == -1)
			buffer[0] = -1;
	}

	private static byte Read() throws IOException {
		if (bufferPointer == bytesRead)
			fillBuffer();
		return buffer[bufferPointer++];
	}

	public void close() throws IOException {
		if (din == null)
			return;
		din.close();
	}

	static void print(Object o) {
		pr.print(o);
	}

	static void println(Object o) {
		pr.println(o);
	}

	static void flush() {
		pr.flush();
	}

	static void println() {
		pr.println();
	}

	static void exit() throws IOException {
		din.close();
		pr.close();
		System.exit(0);
	}
}