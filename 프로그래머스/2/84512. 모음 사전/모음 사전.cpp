#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

string s = " AEIOU";

set<string> V;

void brute(string str) {
    if (str.length() == 5)
    {
        if (str.at(0) != ' ')
        {
            if (str.at(1) == ' ')
            {
                if (str.substr(1, 5) == "    ")
                {
                    V.emplace(str.substr(0, 1));
                }
            }
            else
            {
                if (str.at(2) == ' ')
                {
                    if (str.substr(2, 5) == "   ")
                    {
                        V.emplace(str.substr(0, 2));
                    }
                }
                else
                {
                    if (str.at(3) == ' ')
                    {
                        if (str.substr(3, 5) == "  ")
                        {
                            V.emplace(str.substr(0, 3));
                        }
                    }
                    else
                    {        
                        if (str.at(4) == ' ')
                            V.emplace(str.substr(0, 4));
                        else
                            V.emplace(str);
                    }
                }
            }
        }
        
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        brute(str + s[i]);
    }
}

int solution(string word) {

    // " " A E I O U
    // " "  : 0번째
    // A    : 1번째
    // AA   : 2번째
    // AAA  : 3번째
    // AAAA : 4번째  / AAAAA : 5번째  / AAAAU : 9번째  (4~9)
    // AAAE : 10번째 / AAAEA : 11번째 / AAAEU : 15번째 (10~15)
    // AAAI : 16번째 / AAAIA : 17번째 / AAAIU : 21번째 (16~21)
    // (22~27) (28~33)
    // 
    // AAE  : 34번째
    // AAEA : 35번째 / AAEAA : 36번째 / AAEAU : 40번째 (35~40)
    // AAEE : 41번째 / AAEEA : 11번째 / AAAEU : 46번째 (41~46)
    // AAEI : 47번째 / AAEIA : 18번째 / AAEIU : 52번째 (47~52)
    // (53~58) (59~64)
    // 
    // I : 1563번째      

    brute("");

    int answer = 0;
    
    for (auto it : V)
    {
        answer++;
        if (it == word)
        {
            break;
        }
    }
    return answer;
}