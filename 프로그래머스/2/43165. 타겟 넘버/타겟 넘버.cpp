#include <string>
#include <vector>
#include <deque>
using namespace std;

int total = 0;

void brute(vector<int> numbers, int target)
{
    int count = 0;
    int num = 0;

    deque<int> DQ;

    DQ.push_front(numbers[0]);
    DQ.push_front(-numbers[0]);

    count++;

    while (count < numbers.size())
    {
        num = 0;
        deque<int> temp;
        
        for (auto it : DQ)
        {
            num++;
            temp.push_back(it + numbers[count]);
            temp.push_back(it - numbers[count]);
        }

        for (int i = 0; i < num; i++)
            DQ.pop_front();
        
        for(auto t : temp)
            DQ.push_back(t);

        count++;
    }

    for (auto it : DQ)
    {
        if (it == target)
            total++;
    }
}
int solution(vector<int> numbers, int target) {
    brute(numbers, target);
    return total;
}