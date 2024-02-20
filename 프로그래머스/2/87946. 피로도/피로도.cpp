#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> check;

vector<int> ans;

void brute(int k, int count, vector<vector<int>> dungeon) {

    if (k < 0)
    {
        ans.push_back(count - 1);
        return;
    }
    else if (k == 0)
    {
        ans.push_back(count);
        return;
    }

    for (int i = 0; i < dungeon.size(); i++)
    {
        if (check[i]) {             
            ans.push_back(count);
            continue; 
        }

        if (dungeon[i][0] <= k)
        {
            check[i] = true;
            brute(k - dungeon[i][1], count + 1, dungeon);
            check[i] = false;
        }      
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    
    check.resize(dungeons.size(), false);

    brute(k, 0, dungeons);

    int answer = *max_element(ans.begin(), ans.end());
    return answer;
}