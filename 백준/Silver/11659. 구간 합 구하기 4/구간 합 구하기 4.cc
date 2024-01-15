#include <iostream>
#include <vector>
using namespace std;

vector<int> V;
vector<long long> sum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		V.push_back(num);
	}		

	sum.push_back(V[0]);
	for (int i = 1; i < n; i++)
	{
		sum.push_back(sum[i - 1] + V[i]);
	}

	int i, j;
	for (int a = 0; a < m; a++)
	{
		cin >> i >> j;

		if (i == j)
			cout << V[i-1] << "\n";
		else
			cout << sum[j-1] - sum[i-1] + V[i-1] << "\n";
	}
}