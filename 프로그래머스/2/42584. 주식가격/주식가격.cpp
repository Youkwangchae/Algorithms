#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for (int i = 0; i < prices.size() - 1; i++)
    {
        bool isDown = false;
        for (int j = i + 1; j < prices.size(); j++)
        {
            if (prices[i] > prices[j])
            {
                answer.push_back(j - i);
                isDown = true;
                break;
            }
        }
        if (!isDown)
            answer.push_back(prices.size() - i - 1);
    }
    answer.push_back(0);
    return answer;
}