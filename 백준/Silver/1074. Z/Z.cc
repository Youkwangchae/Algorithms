#include <iostream>
using namespace std;
int cnt = 0;
int a = 1;
void letsgo(int n, int x, int y, int r, int c) {
	if (n == 2) {
		for(int i=0;i<2;i++)
			for (int j = 0; j < 2; j++) {
				//x+i은 열, y+j은 행
				if (x + i == r && y + j == c)
				{
					cout << cnt << endl;
					return;
				}
				else
					cnt++;
			}
	}
	else {
		int b = n / 2;
		if (b+x > r)
		{
			if(b+y>c)
			letsgo(b, x, y, r, c);
			else
			{
				cnt += (b*b);
				letsgo(b, x, y + b, r, c);
			}
		}
		else {
			if (b+y > c)
			{
				cnt += (b*b)*2;
				letsgo(b, x + b, y, r, c);
			}
			else
			{
				cnt += (b*b)*3;
				letsgo(b, x + b, y + b, r, c);
			}
		}
	}
}


int main() {
	int N, r, c;
	cin >> N >> r >> c;
	for (int i = 0; i < N; i++)
		a = a * 2;
	letsgo(a, 0, 0, r, c);

}