import java.io.*;
import java.util.StringTokenizer;
public class <ClASS_NAME> {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
		/*
			code
			goes
			here
		*/
        out.close();
    }
    static class Scanner
    {
        StringTokenizer st;
        BufferedReader br;
        public Scanner(InputStream s){	br = new BufferedReader(new InputStreamReader(s));
        public String next() throws IOException 
        {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }
        public int nextInt() throws IOException {return Integer.parseInt(next());}
        public long nextLong() throws IOException {return Long.parseLong(next());}
        public double nextDouble() throws IOException { return Double.parseDouble(next()); }
        public String nextLine() throws IOException {return br.readLine();}
        public boolean ready() throws IOException { return br.ready(); }
    }
}