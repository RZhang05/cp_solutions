import java.util.*;
public class ccc00j5 {

	static ArrayList<String> websites = new ArrayList<String>();

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		Queue<Integer> Q = new LinkedList<Integer>(); 
		ArrayList<String> links = new ArrayList<String>();
		ArrayList<String> linkedFrom = new ArrayList<String>();
		ArrayList<Integer> linkers = new ArrayList<Integer>();
		ArrayList<Integer> linkers2 = new ArrayList<Integer>();
		ArrayList<String> output = new ArrayList<String>();

		for(int i=0;i<N;i++) {
			String website = sc.next();
			websites.add(website);
			String line;
			do {
				line = sc.nextLine();
				if(line.contains("<A HREF")) {
					int first = 0;
					for(int j=0;j<line.length();j++) {
						if(line.charAt(j) == '<' && line.charAt(j + 1) == 'A' && line.charAt(j + 3) == 'H') {
							first = j;
						} else if(line.charAt(j) == '\"' && line.charAt(j + 1) == '>') {
							int last = j;
							String test = line.substring(first + 9, last);
							output.add("Link from " + website + " to " + test);
							linkedFrom.add(website);
							links.add(test);
							if(!websites.contains(test)) {
								websites.add(test);
							}
						}
					}
				}
			} while (!line.equals("</HTML>"));
		}

		String line;
		String line2;
		do {
			line = sc.next();
			line2 = sc.next();
			if(!line.equals("The") && !line2.equals("End")) {
				linkers.add(check(line));
				linkers2.add(check(line2));
			}
		} while(!line.equals("The") && !line2.equals("End"));

		ArrayList<Integer>[] adj = new ArrayList[websites.size() + 1];
		for(int i=0;i<=websites.size();i++) {
			adj[i] = new ArrayList<Integer>();
		}

		for(int i=0;i<links.size();i++) {
			String link = links.get(i);
			String host = linkedFrom.get(i);
			adj[check(host)].add(check(link));
		}

		for(int i=0;i<output.size();i++) {
			System.out.println(output.get(i));
		}

		for(int i=0;i<linkers.size();i++) {
			boolean vis[] = new boolean[websites.size() + 1];
			Q.add(linkers.get(i)); vis[linkers.get(i)] = true;
			while(!Q.isEmpty()) {
				int cur = Q.poll();
				for(int v: adj[cur]) {
					if(!vis[v]) {
						Q.add(v); vis[v] = true;
					}
				}
			}
			if(vis[linkers2.get(i)]) {
				System.out.println("Can surf from " + reverse(linkers.get(i)) + " to " + reverse(linkers2.get(i)) + ".");
			} else {
				System.out.println("Can\'t surf from " + reverse(linkers.get(i)) + " to " + reverse(linkers2.get(i)) + ".");
			}
		}

	}

	public static int check(String value) {
		for(int j=0;j<websites.size();j++) {
			if(websites.get(j).equals(value)) {
				return j;
			}
		}
		return -1;
	}

	public static String reverse(int value) {
		return websites.get(value);
	}

}