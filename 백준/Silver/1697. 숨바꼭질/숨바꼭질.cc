#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> q;
int used[100001] = { 0, };

void bfs(int start, int k) {
	q.push(make_pair(start, 0));

	int num = 0;
	int cost = 0;

	int num1 = 0;
	int num2 = 0;
	int num3 = 0;

	while (!q.empty()) {
		num = q.front().first;
		cost = q.front().second;

		if (num == k)
		{
			cout << cost;
			break;
		}

		q.pop();

		num1 = num - 1;
		num2 = num + 1;
		num3 = num * 2;
		if (num1 >= 0 && num1 < 100001 && used[num1] == 0) {
			used[num1] = 1;
			q.push(make_pair(num1, cost + 1));			
		}

		if (num2 >= 0 && num2 < 100001 && used[num2] == 0) {
			used[num2] = 1;
			q.push(make_pair(num2, cost + 1));
		}

		if (num3 >= 0 && num3 < 100001 && used[num3] == 0) {		
			used[num3] = 1;
			q.push(make_pair(num3, cost + 1));
		}
	}
}

int main()
{
	int n, k;

	cin >> n >> k;

	bfs(n, k);

	return 0;
}