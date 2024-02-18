#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    int not_lost = n - lost.size();

    vector<bool> check; // 이미 빌려줬는지 여부를 저장.
    check.resize(n+1, false);

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    vector<int> reserveAndLost;

    // 여벌옷 가져온 학생이 도난 당한 경우 => lost, reserver 배열에서 제외.
    for (int i = 0; i < lost.size(); i++)
    {
        if (find(reserve.begin(), reserve.end(), lost[i]) != reserve.end())
        {
            reserveAndLost.push_back(lost[i]);            
        }
    }

    for (int i = 0; i < reserveAndLost.size(); i++)
    {
        lost.erase((find(lost.begin(), lost.end(), reserveAndLost[i])));
        reserve.erase(find(reserve.begin(), reserve.end(), reserveAndLost[i]));
        not_lost++;
    }

    int borrow = 0;
    for (int i = 0; i < lost.size(); i++)
    {                
        for (int j = 0; j < reserve.size(); j++)
        {
            // 이미 빌려준 경우는 패스.
            if (check[reserve[j]]) continue;

            // 여분 체육복이 도난 학생 앞뒤 학생일 때
            if (abs(reserve[j] - lost[i]) == 1)
            {
                check[reserve[j]] = true;
                borrow++;
                break;
            }
        }
    }

    int answer = not_lost + borrow;
    return answer;
}