#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> check;
bool cmp(pair<int, int>& A, pair<int, int>& B) {
    if (A.first == B.first)
    {
        string str1 = to_string(check[A.second]) + to_string(check[B.second]);
        string str2 = to_string(check[B.second]) + to_string(check[A.second]);        

        return stoi(str1) > stoi(str2);
    }
    else
        return A.first > B.first;
}

string solution(vector<int> numbers) {

    check = numbers;

    vector<pair<int, int>> firstLetters;

    bool isAllZero = true;

    for (int i = 0; i < numbers.size(); i++)
    {
        string str = to_string(numbers[i]).substr(0, 1);

        if (stoi(str) > 0) isAllZero = false;

        firstLetters.push_back({ stoi(str), i });
    }

    if (isAllZero)
        return "0";
    
    std::sort(firstLetters.begin(), firstLetters.end(), cmp);

    string answer = "";

    for (int i = 0; i < firstLetters.size(); i++)
    {
        answer += to_string(numbers[firstLetters[i].second]);
    }

    return answer;
}