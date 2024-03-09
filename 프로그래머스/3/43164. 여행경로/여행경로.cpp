#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(vector<string> A, vector<string> B)
{
    return A[1] < B[1];
}

vector<vector<string>> ans;

void DFS(vector<string> route, vector<vector<string>> tickets, vector<vector<string>> others, vector<bool> check)
{
    if (route.size() > tickets.size())
    {
        ans.push_back(route);
        return;
    }

    string start = route[route.size() - 1];

    for (int i = 0; i < others.size(); i++)
    {
        string str = others[i][0];
        if (str == start)
        {
            if (!check[i])
            {
                route.push_back(others[i][1]);
                check[i] = true;
                DFS(route, tickets, others, check);
                check[i] = false;
                route.pop_back();
            }
        }
    }    
}

vector<string> solution(vector<vector<string>> tickets) {

    vector<vector<string>> ticket;
    vector<vector<string>> others;    

    for (int i = 0; i < tickets.size(); i++)
    {
        /*if (tickets[i][0] == "ICN")
            ticket.push_back(tickets[i]);
        else*/
            others.push_back(tickets[i]);
    }

    sort(ticket.begin(), ticket.end(), cmp);    
    
    vector<string> answer;

    answer.push_back("ICN");
    // answer.push_back(ticket[0][1]);

    for (int i = 1; i < ticket.size(); i++)
    {
        others.push_back(ticket[i]);
    }

    vector<bool> check;
    check.resize(tickets.size(), false);
    
    DFS(answer, tickets, others, check);    

    sort(ans.begin(), ans.end());
    return ans[0];
}