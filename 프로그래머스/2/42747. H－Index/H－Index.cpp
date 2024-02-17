#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int& A, int& B) {
    return A > B;
}

int solution(vector<int> citations) {
    int answer = 0;
    int threshold = 0;
    int next = 0;
    sort(citations.begin(), citations.end(), cmp);

    for (int i = 0; i < citations.size(); i++)
    {
        int upCount = 0;    
        int downCount = 0;

        for (int j = 0; j < citations.size(); j++)
        {
            if (citations[j] >= citations[i])            
                upCount++;            
            else
                break;
        }

        downCount = citations.size() - upCount;

        if ((upCount >= citations[i]) && (downCount <= citations[i]))
        {
            if (threshold < citations[i])
            {
                threshold = citations[i];
                next = citations[i - 1];
            }
        }        
    }

    if (threshold == 0)
        threshold = citations[0];

    int count = 0;
    while (threshold < next) {
        count = 0;

        for (auto it : citations) {
            if (it >= threshold)
                count++;
        }

        if (count >= threshold)
        {
            if (answer < threshold)
                answer = threshold;
        }            

        threshold++;
    }

    while (threshold > 0) {
        count = 0;

        for (auto it : citations) {
            if (it >= threshold)
                count++;
        }

        if (count >= threshold)
        {
            if (answer < threshold)
                answer = threshold;
        }

        threshold--;
    }

    return answer;
}