#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    set<int> S(nums.begin(), nums.end());

    if (S.size() < nums.size() / 2)
        answer = S.size();
    else
        answer = nums.size() / 2;
    return min(S.size(), nums.size() / 2);
}