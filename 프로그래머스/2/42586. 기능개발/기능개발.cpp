#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
        
    int max_day = 0;
    vector<int> ans;
    
    for(int i=0;i<progresses.size();i++)
    {
        int day = (99 - progresses[i]) / speeds[i] + 1;
        
        if(ans.empty() || max_day < day)
        {
            ans.push_back(1);
        }
        else
        {
            ans.back()++;            
        }
        
        max_day = max(max_day, day);
    }    
    
    return ans;
}