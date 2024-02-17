#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++)
    {        
        vector<int> V(array.begin() + (commands[i][0] - 1), array.begin() + (commands[i][1]));

        sort(V.begin(), V.end());
        
        answer.push_back(V[commands[i][2] - 1]);
    }

    return answer;
}