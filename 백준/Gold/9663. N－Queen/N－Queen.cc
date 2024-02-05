#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int n; int res=0;
void map(int line, vector<int> check, int cnt)
{
	if (cnt == n)
	{
		res++;
		return;
	}


	for (int i = line; i < n; i++)
	{
		if (i > cnt)
			return;

		if (check[i] == -1)//(i+1)번째 줄에 퀸이 없음.
		{

			for (int j = 0; j < n; j++)
			{
				bool isPossible = true;
				for (int k=0; k<line;k++)
				{
					if (check[k] != -1)
					{
						if (abs(i-k) == abs(j-check[k]) || check[k] == j)
						{
							isPossible = false;
							break;
						}
					}
				}

				if (isPossible)
				{
					check[i] = j;
					map(line + 1, check, cnt+1);
				}
				

			}

		}

	}




}

int main()
{
	vector<int> check;//check[0]은 맨 윗줄에서 어느 자리에 퀸을 놓았는지 의미함. check[0]이 2이면 맨 윗줄 왼쪽에서 두번째 자리에 퀸이 있음.
	cin >> n;

	for (int i = 0; i < n; i++)
		check.push_back(-1);

	map(0, check, 0);
	cout << res;
}