#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define MAX_SIZE 100000+1

deque<int> DQ;
int visited[MAX_SIZE];

priority_queue<int, vector<int>, greater<int>> PQ;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;

	memset(visited, 0, sizeof(int) * MAX_SIZE);

	DQ.push_back(n);
	visited[n] = 1;	

	if (n >= k)
		PQ.push(n - k);
	else
	{
		// 순간이동이 0초 이므로, 가중치가 있는 bfs => 다익스트라 => deque or priority queue
		while (!DQ.empty())
		{			
			int num = DQ.front();
			DQ.pop_front();			

			if (num == k)
			{				
				PQ.emplace(visited[num] - 1);
				continue;
			}
			
			// 순간이동은 우선순위에서 앞이니 push_front
			if (num * 2 < MAX_SIZE && !visited[num * 2])
			{
				DQ.push_front(num * 2);
				visited[num * 2] = visited[num];
			}

			// 걷는건 우선순위에서 밀리므로 push_back			

			if (num - 1 > 0 && !visited[num - 1])
			{
				DQ.push_back(num - 1);
				visited[num - 1] = visited[num] + 1;
			}

			if (num + 1 < MAX_SIZE && !visited[num + 1])
			{
				DQ.push_back(num + 1);
				visited[num + 1] = visited[num] + 1;
			}
		}
	}

	std::cout << PQ.top();
}