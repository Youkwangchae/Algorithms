import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static long mul(long n, long k, long t) {
		if(k==1)
			return n%t;
		if(k%2==0) 
			{long num = mul(n,k/2,t);
				return (num*num)%t;
			}else
				return (mul(n,k-1,t)*(n%t))%t;
		}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			StringTokenizer st = new StringTokenizer(br.readLine()," ");
			bw.write(Integer.toString((int)mul((long)Integer.parseInt(st.nextToken()),(long)Integer.parseInt(st.nextToken()),(long)Integer.parseInt(st.nextToken()))));
			bw.flush();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
