#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> M;

string solution(vector<string> participant, vector<string> completion) {

    map<string, int> M;

    string answer = "";

    for (int i = 0; i < participant.size(); i++)
    {
        M[participant[i]]++;
    }

    for (int i = 0; i < completion.size(); i++)
    {
        M[completion[i]]--;
    }

    for (int i = 0; i < participant.size(); i++)
    {
        if (M[participant[i]] == 1)
            answer = participant[i];
    }
    
    return answer;
}