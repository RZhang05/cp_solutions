import java.util.*;
import java.io.*;
public class rte16s3 {
	
	static int n, lca[][], dep[]; static long dis[];
	static ArrayList<Integer> adj[], w[];
	
	static void dfs(int u, int pa) {
		for(int i=0;i<adj[u].size();i++) {
			int v= adj[u].get(i), w0 = w[u].get(i);
			if(v!=pa) {
				dep[v] = dep[u]+1; dis[v] = dis[u] + w0; lca[0][v]=u; dfs(v,u); 
			}
		}
	}
	
	static int qLCA(int u, int v) {
		if(dep[u] < dep[v]) {
			int a=u; u = v; v = a;
		}
		for(int i=lca.length-1;i>=0;i--) {
			if(lca[i][u]!=-1 && dep[lca[i][u]]>=dep[v]) u = lca[i][u];
		}
		if(u==v) return v;
		for(int i=lca.length-1;i>=0;i--) {
			if(lca[i][u]!=-1 && lca[i][v]!=-1 && lca[i][u]!=lca[i][v]) {
				u = lca[i][u];
				v = lca[i][v];
			}
		}
		return lca[0][u];
	}
	
	static void buildLCA() {
		for(int i=1;i<lca.length;i++) {
			for(int j=0;j<=n;j++) {
				if(lca[i-1][j] != -1) lca[i][j] = lca[i-1][lca[i-1][j]];
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		n = readInt(); lca = new int[13][n+1]; dep = new int[n+1]; dis= new long[n+1];
		adj = new ArrayList[n+1]; w = new ArrayList[n+1];
		for(int i=0;i<lca.length;i++) Arrays.fill(lca[i], -1); 
		for(int i=0;i<=n;i++) {
			adj[i] = new ArrayList<Integer>();
			w[i] = new ArrayList<Integer>();
		}
		for(int i=0;i<n-1;i++) {
			int u = readInt(), v = readInt(), w0 = readInt();
			adj[u].add(v);
			adj[v].add(u);
			w[u].add(w0);
			w[v].add(w0);
		}
		dfs(0,-1); buildLCA();
		int Q = readInt();
		for(int i=1;i<=Q;i++) {
			int u = readInt(), v = readInt(), rt = qLCA(u,v);
			pr.println(dis[u] + dis[v] - 2*dis[rt]);
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