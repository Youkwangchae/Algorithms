#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int n;
    int m;

    int total = brown + yellow;

    // brown = 2 * (n + m) - 4;    

    vector<int> answer;

    for (int i = 1; i < total; i++)
    {
        if (total % i == 0)
        {
            int a = total / i;
            int b = i;

            if (brown == (2 * (a + b) - 4))
            {
                answer.push_back(max(a, b));
                answer.push_back(min(a, b));
                break;
            }
        }
    }
    
    return answer;
}