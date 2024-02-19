#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int backBrute(string str, string name, int stop) {
    int answer = 0;    

    for (int i = name.length() - 1; i > stop - 1; i--)
    {
        if (str == name) break;

        answer++;

        // N~Z 는 뒤로.
        if (name[i] - str[i] > 13)
        {
            answer += 'Z' - name[i] + 1;
        }
        else
        {
            answer += name[i] - str[i];
        }

        str[i] = name[i];
    }

    // stop 위치에서 앞으로 돌아가야 함.    
    answer += name.length() - stop;

    if (name[0] - str[0] > 13)
        answer += 'Z' - name[0] + 1;
    else
        answer += name[0] - str[0];

    str[0] = name[0];

    // Stop 위치까진 앞으로.
    for (int i = 1; i < stop; i++)
    {
        if (str == name) break;

        // 다음 위치가 A가 아닐 경우 커서 옮겨서 조이스틱 조작 필요.
        answer++;

        // N~Z 는 뒤로.
        if (name[i] - str[i] > 13)
        {
            answer += 'Z' - name[i] + 1;
        }
        else
        {
            answer += name[i] - str[i];
        }

        str[i] = name[i];
    }

    return answer;
}

int brute(string str, string name, int stop) {
    int answer = 0;

    // Stop 위치까진 앞으로.
    for (int i = 0; i < stop + 1; i++)
    {
        if (str == name) break;

        // 다음 위치가 A가 아닐 경우 커서 옮겨서 조이스틱 조작 필요.
        if (i > 0) answer++;

        // N~Z 는 뒤로.
        if (name[i] - str[i] > 13)
        {
            answer += 'Z' - name[i] + 1;
        }
        else
        {
            answer += name[i] - str[i];
        }
        
        str[i] = name[i];
    }

    // Stop 위치에서 첫번째 위치까지 조작.
    answer += stop;

    for (int i = name.length() - 1; i > stop; i--)
    {
        if (str == name) break;

        answer++;

        // N~Z 는 뒤로.
        if (name[i] - str[i] > 13)
        {
            answer += 'Z' - name[i] + 1;
        }
        else
        {
            answer += name[i] - str[i];
        }
        
        str[i] = name[i];
    }

    return answer;
}

int solution(string name) {

    string str = "";
    string str2 = "";
    string name2 = "";

    string str3 = "";
    string name3 = "";

    for (int i = 0; i < name.length(); i++)
    {
        str.push_back('A');
    }

    int answer1 = 0;
    int answer2 = 0;

    str2 = str;
    name2 = name;

    str3 = str;
    name3 = name;

    // 알파벳은 총 26자. A부터 시작하면, A~M까지는 앞으로.
    for (int i = 0; i < name.length(); i++)
    {
        if (str == name) break;

        // 다음 위치가 A가 아닐 경우 커서 옮겨서 조이스틱 조작 필요.
        if (i > 0) answer1++;

        // N~Z 는 뒤로.
        if (name[i] - str[i] > 13)
        {
            answer1 += 'Z' - name[i] + 1;
        }
        else
        {
            answer1 += name[i] - str[i];
        }

        str[i] = name[i];
    }   

    if (name2[0] - str2[0] > 13)
        answer2 = 'Z' - name2[0] + 1;
    else
        answer2 = name2[0] - str2[0];

    str2[0] = name2[0];

    for (int i = name2.length() - 1; i > 0; i--)
    {
        if (str2 == name2) break;

        answer2++;

        // N~Z 는 뒤로.
        if (name2[i] - str2[i] > 13)
        {
            answer2 += 'Z' - name2[i] + 1;
        }
        else
        {
            answer2 += name2[i] - str2[i];
        }        

        str2[i] = name2[i];
    }
    
    vector<int> Vec;

    for (int i = 1; i < str3.length() - 1; i++)
    {
        Vec.push_back(brute(str3, name3, i));
        Vec.push_back(backBrute(str3, name3, str3.length() - i));
    }    
    if (Vec.size() == 0)
        return min(answer1, answer2);
    else
        return min(min(answer1, answer2), *min_element(Vec.begin(), Vec.end()));
}