#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {

    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = i + 1; j < phone_book.size(); j++)
        {
            int minLen = min(phone_book[i].length(), phone_book[j].length());

            bool check = true;

            for (int k = 0; k < minLen; k++)
            {
                if (phone_book[i].at(k) != phone_book[j].at(k))
                {
                    check = false;
                    break;
                }
            }

            if (check)
                return false;
            else
                break;
        }
    }
    
    return true;
}