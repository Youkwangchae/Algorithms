#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321;

bool cmp(vector<int>& A, vector<int>& B)
{
    return A[1] < B[1];
}

int solution(vector<vector<int>> jobs) {

    sort(jobs.begin(), jobs.end(), cmp);

    int answer = INF;
    int start = 0;
    int time = 0;
    int size = jobs.size();

    // 한 프로세스가 작업의 요청부터 종료까지 걸린 시간 = (프로세스가 시작된 시간) + (프로세스가 총 진행되는 시간) - (프로세스가 요청된 시간)

    while (!jobs.empty()) {
        for (int i = 0; i < jobs.size(); i++) 
        {
            if (jobs[i][0] <= start)
            {
                start += jobs[i][1];
                time += start - jobs[i][0];
                jobs.erase(jobs.begin() + i);
                break;
            }

            if (i == jobs.size() - 1) start++;
        }
    }

    answer = time / size;
    return answer;
}