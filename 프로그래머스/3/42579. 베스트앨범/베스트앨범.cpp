#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<int, pair<string, int>>& a, pair<int, pair<string, int>>& b)
{
    return a.first > b.first;
}

bool bmp(pair<string, int>& a, pair<string, int>& b)
{
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {    

    vector<pair<int, pair<string, int>>> chart; // {{장르, 플레이}, 고유번호}

    map<string, int> M;

    for (int i = 0; i < genres.size(); i++)
    {
        chart.push_back({ plays[i], { genres[i], i} });

        M[genres[i]] += plays[i];
    }        

    vector<pair<string, int>> V;

    // value 값 기준 정렬.
    for (auto it : M)
    {
        V.push_back(it);
    }

    sort(V.begin(), V.end(), bmp);

    sort(chart.begin(), chart.end(), cmp);
    
    vector<int> answer;
    int count = 0;

    for (int a=0;a<V.size();a++)
    {
        count = 0;
        for (int i = 0; i < chart.size(); i++)
        {
            // 장르가 같은 것들만 분류
            if (chart[i].second.first == V[a].first)
            {
                // 고유번호 저장.
                answer.push_back(chart[i].second.second);

                count++;

                if (count == 2)
                    break;
            }
        }
    }
        
    return answer;
}