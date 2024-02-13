#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {

    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size() - 1; i++)
    {
        int minLen = min(phone_book[i].length(), phone_book[i+1].length());

        bool check = true;

        for (int k = 0; k < minLen; k++)
        {
            if (phone_book[i].at(k) != phone_book[i+1].at(k))
            {
                check = false;
                break;
            }
        }

        if (check)
            return false;
    }
    
    return true;
}