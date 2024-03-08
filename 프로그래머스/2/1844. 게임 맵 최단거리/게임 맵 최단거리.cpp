#include<vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    vector<vector<int>> map;
    vector<vector<bool>> check;

    map.resize(maps.size() + 2, vector<int>());
    check.resize(maps.size() + 2, vector<bool>());

    for (int i = 0; i < maps.size() + 2; i++)
    {
        for (int j = 0; j < maps[0].size() + 2; j++)
        {
            map[i].push_back(0);
            check[i].push_back(false);
        }
    }

    for (int i = 1; i < maps.size() + 1; i++)
    {
        for (int j = 1; j < maps[0].size() + 1; j++)
        {
            map[i][j] = maps[i - 1][j - 1];
        }
    }

    queue<pair<int, int>> pos;
    pos.push({ 1, 1 });

    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    int count[102][102] = { 0, };
    count[1][1] = 1;

    while (!pos.empty())
    {
        pair<int, int> p = pos.front();
        pos.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if (nx == (map.size() - 2) && (ny == map[0].size() - 2))
            {
                return count[p.first][p.second] + 1;
            }

            if (!check[nx][ny] && map[nx][ny] == 1)
            {
                check[nx][ny] = true;
                pos.push({ nx, ny });
                count[nx][ny] = count[p.first][p.second] + 1;
            }
        }
    }
        return -1;
}