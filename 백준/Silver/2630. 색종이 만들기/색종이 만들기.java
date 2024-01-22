import java.util.Scanner;

public class Main {
static int b=0,w=0;
	static void paper(int[][]map,int n,int x,int y) {
		int a = map[x][y];
		if(n==1)
			if(a==1)
				b++;
			else
				w++;
		else
		{boolean c = false;
			for(int i=x;i<(n+x);i++)
			for(int j=y;j<(n+y);j++)
				if(map[i][j]!=a)
					c=true;
			if(c)
				{paper(map,n/2,x,y);
				paper(map,n/2,x+n/2,y);
				paper(map,n/2,x,y+n/2);
				paper(map,n/2,x+n/2,y+n/2);
				}
			else
				if(a==1)
					b++;
				else
					w++;
		}
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int[][] map = new int[n][n];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				map[i][j]=scan.nextInt();
		paper(map,n,0,0);
		System.out.println(w);
		System.out.println(b);

	}

}
