#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

    vector<int> truck_pos;
    truck_pos.resize(truck_weights.size(), 0);

    int bridge_start = 0;
    int bridge_end = 1;
    int weight_sum = 0;

    int answer = 0;

    while (bridge_start != truck_weights.size())
    {
        answer++;
        weight_sum = 0;

        bool isFull = false;

        for (int i = bridge_start; i < bridge_end; i++)
        {
            weight_sum += truck_weights[i];

            if (weight_sum > weight)
            {
                isFull = true;
                break;
            }

            truck_pos[i] += 1;
        }        

        if (truck_pos[bridge_start] == bridge_length)
        {
            bridge_start++;
        }

        if (isFull)
        {
            continue;
        }
        else
        {
            if(bridge_end < truck_weights.size())
            bridge_end++;
        }
    }
    
    return answer + 1;
}