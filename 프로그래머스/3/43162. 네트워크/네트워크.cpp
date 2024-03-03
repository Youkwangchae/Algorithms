#include <string>
#include <vector>
#include <deque>
#include <set>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> check;
    check.resize(n, false);    

    deque<int> DQ;
    for (int i = 0; i < n; i++)
    {        
        set<int> ans;

        for (int j = 0; j < computers[i].size(); j++)
        {
            // if (i == j) continue;

            if (computers[i][j] == 1)
            {
                if (check[j]) continue;

                DQ.push_back(j);
                check[j] = true;

                ans.emplace(j);
            }
        }

        while (!DQ.empty())
        {
            int start = DQ.front();
            DQ.pop_front();

            for (int i = 0; i < computers[start].size(); i++)
            {
                if (computers[start][i] == 1)
                {
                    if (check[i]) continue;

                    DQ.push_back(i);
                    check[i] = true;

                    ans.emplace(i);
                }
            }
        }

        if (ans.size() > 0)
            answer++;
    }    

    return answer;
}