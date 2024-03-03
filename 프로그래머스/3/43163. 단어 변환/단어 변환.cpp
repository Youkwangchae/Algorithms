#include <string>
#include <vector>

using namespace std;

vector<bool> check;
int minTotal;

void DFS(string begin, string target, vector<string> words, int count) {
    if (count == words.size())
    {
        if (begin == target)
        {
            minTotal = min(count, minTotal);
        }
    }
    else {
        if (begin == target)
        {
            minTotal = min(count, minTotal);
        }
        else
        {
            for (int i = 0; i < words.size(); i++)
            {
                if (check[i]) continue;
                if (words[i] == begin) continue;

                int num = 0;
                for (int j = 0; j < words[i].length(); j++)
                {
                    if (begin[j] == words[i][j]) num++;
                }

                // 한 글자만 다른 경우
                if (num == words[i].length() - 1)
                {
                    check[i] = true;
                    DFS(words[i], target, words, count + 1);
                    check[i] = false;
                }
            }
        }
    }

}

int solution(string begin, string target, vector<string> words) {
    
    check.resize(words.size(), false);

    minTotal = words.size() + 1;

    DFS(begin, target, words, 0);

    if (minTotal == words.size() + 1)
        return 0;
    else
        return minTotal;    
}