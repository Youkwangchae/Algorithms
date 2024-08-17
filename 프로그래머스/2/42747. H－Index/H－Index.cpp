#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int threshold = 0;
    int next = 0;
    sort(citations.begin(), citations.end(), greater<int>());

    for (int i = 0; i < citations.size(); i++)
    {
        int upCount = 0;    

        for (int j = 0; j < citations.size(); j++)
        {
            if (citations[j] >= citations[i])            
                upCount++;            
            else
                break;
        }

        if ((upCount >= citations[i]))
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