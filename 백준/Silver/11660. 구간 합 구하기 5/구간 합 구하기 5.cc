#include <iostream>
int m_sum[1030][1030] = { 0, };
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, x1, y1, x2, y2;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			int num;
			cin >> num;
			m_sum[i][j] = m_sum[i][j - 1] + num;
		}
	}

	for (int i = 0; i < m; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		
		for (int j = x1; j < x2 + 1; j++)
		{			
			m_sum[1025][3] += m_sum[j - 1][y2] - m_sum[j - 1][y1 - 1];
		}
		cout << m_sum[1025][3] << "\n";
		m_sum[1025][3] = 0;
	}
}