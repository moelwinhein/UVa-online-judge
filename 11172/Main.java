import java.io.*;
import java.util.*;

class Main {

	void run() {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		try {
			int num = Integer.parseInt(br.readLine());
			while(num-- > 0) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				Integer a = Integer.parseInt(st.nextToken());
				Integer b = Integer.parseInt(st.nextToken());
				int cmp = a.compareTo(b);
				if (cmp > 0) pr.println('>');
				else if (cmp < 0) pr.println('<');
				else pr.println('=');
			}
			pr.close();
		} catch (Exception e) {
			return;
		}
	}

	public static void main(String arg[]) {
		Main ro = new Main();
		ro.run();	
	}
}