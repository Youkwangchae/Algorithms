#include <vector>
#include <map>
using namespace std;

map<int, int> M;
vector<int>nums;
vector<int> things;
int solution(vector<int> nums)
{
    int answer = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        M[nums[i]]++;

        if (M[nums[i]] == 1)
            things.push_back(nums[i]);
    }

    if (things.size() < nums.size() / 2)
        answer = things.size();
    else
        answer = nums.size() / 2;

    return answer;
}