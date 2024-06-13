#include <iostream>
#include <vector>
using namespace std;

int n, m;

int Visited[10005];
vector<vector<int>> Edges;
long long DD[10005];

long long dfs(int source)
{
    Visited[source] = 1;
    int s = Edges[source].size();

    DD[source] = 0;

    for (int i = 0; i < s; i++)
    {
        if (Visited[Edges[source][i]] == 0)
            DD[source] = max(DD[source], dfs(Edges[source][i]) + 1);
        else
            DD[source] = max(DD[source], DD[Edges[source][i]] + 1);
    }

    return DD[source];
}

int solve()
{
    cin >> n >> m;

    Edges.clear();

    for (int i = 1; i <= n; i++)
    {
        Visited[i] = 0;
        DD[i] = 0;
    }

    Edges.resize(n + 1);

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        Edges[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        dfs(i);

    long long answer = 0;

    for (int i = 1; i <= n; i++)
        answer = max(answer, DD[i]);

    return answer;
}

int main()
{
    int ts;
    cin >> ts;

    for (int i = 1; i <= ts; i++)
    {
        cout << "#" << i << ' ' << solve() << '\n';
    }

    return 0;
}
