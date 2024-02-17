#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {

    // 1번 수포자 : 1~5 순서
    vector<int> ans1 = { 1,2,3,4,5 };
    
    // 2번 수포자 : 2-1 / 2-3 / 2-4 / 2-5 순서
    vector<int> ans2 = { 2,1,2,3,2,4,2,5 };
    // 3번 수포자 : 3-3 / 1-1 / 2-2 / 4-4 / 5-5 순서
    vector<int> ans3 = { 3,3,1,1,2,2,4,4, 5, 5 };

    vector<int> result = { 0, 0, 0 };

    for (int i = 0; i < answers.size(); i++)
    {
        if (answers[i] == ans1[i % 5])
            result[0]++;

        if (answers[i] == ans2[i % 8])
            result[1]++;

        if (answers[i] == ans3[i % 10])
            result[2]++;
    }    

    int idx = max_element(result.begin(), result.end()) - result.begin();

    vector<int> answer;    
    answer.push_back(idx + 1);

    for (int i = 0; i < result.size(); i++)
    {
        if (i == idx) continue;
        if (result[i] == result[idx])
            answer.push_back(i + 1);
    }

    sort(answer.begin(), answer.end());

    return answer;
}