#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int fact(int i)
{
    if (i == 0 || i == 1)
        return 1;
    return fact(i - 1) * i;
}

int completion(int n, int k)
{
    if (n < k) return 0;

    return fact(n) / (fact(n - k) * fact(k));
}

int solution(vector<vector<string>> clothes) {

    unordered_map<string, int> M;

    for (int i = 0; i < clothes.size(); i++)
    {
        M[clothes[i][1]]++;
    }
    
    int answer = 0;
    int count = 1;

    for (auto it : M)
    {        
        // 해당 카테고리를 착용 안하는 경우의 수 1가지 + 착용 하면 종류 n개 중 고르는 경우의 수
        count *= (M[it.first] + 1);
    }
    
    return count - 1;
}