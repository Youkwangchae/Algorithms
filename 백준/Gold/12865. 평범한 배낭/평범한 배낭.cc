#include <iostream>
#include <string>
using namespace std;

int weight[101] = { 0, };
int val[101] = { 0, };
int total[100001] = { 0, }; // i번째 : 무게가 i일 때 최댓값.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	
	int n, k;
	cin >> n >> k;	

	int w, v;
	for (int i = 0; i < n; i++)
	{
		cin >> w >> v;

		weight[i] = w;
		val[i] = v;
	}	

	int maxNum = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = k; j > weight[i] - 1; j--)
		{
			total[j] = max(total[j], total[j - weight[i]] + val[i]);
			if (maxNum < total[j])
				maxNum = total[j];
		}
	}

	cout << maxNum;
}