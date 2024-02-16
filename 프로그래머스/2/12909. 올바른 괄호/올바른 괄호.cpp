
#include <queue>
#include <vector>
#include <string>
using namespace std;

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(string s) {

    string str = s;

    queue<char> Q;

    Q.push(str[0]);

    for (int i = 1; i < str.size(); i++)
    {       
        if (str[i] == ')')
        {
            if (Q.front() == '(')
            {
                Q.pop();
            }
            else
                Q.push(str[i]);
        }
        else
        {
                Q.push(str[i]);
        }
    }
   
    bool answer = Q.size() == 0;
    return answer;
}