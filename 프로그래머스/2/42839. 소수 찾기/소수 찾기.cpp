#include <string>
#include <vector>
#include <set>

using namespace std;

bool isCompositeNumber(int num) {    

    if (num < 2) return true;

    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
            return true;
    }
    return false;
}

vector<bool> isvisit;
string number;
set<string> S;
vector<string> vec;

void brute(string str) {
    for (int i = 0; i < number.length(); i++) {
        if (isvisit[i]) continue;
        isvisit[i] = true;
        S.emplace(str + vec[i]);
        brute(str + vec[i]);
        isvisit[i] = false;
    }
}

int solution(string numbers) {

    number = numbers;
    
    for (int i = 0; i < numbers.length(); i++)
    {
        vec.push_back(to_string(numbers[i] - '0'));
    }

    isvisit.resize(vec.size(), false);

    brute("");

    set<int> ans;

    for (string it : S)
    {        
        if (!isCompositeNumber(stoi(it)))
        {
            ans.emplace(stoi(it));
        }
    }

    int answer = ans.size();
    return answer;
}