#include<iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <limits.h>

using namespace std;
long long Energy[100001];
string str1, str2, reverse1, reverse2;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int i, n;
	cin >> n;

	for (i = 0; i < n; i++)
		cin >> Energy[i];

	cin >> str1;
	reverse1 = str1; 
	reverse(reverse1.begin(), reverse1.end());

	bool cmp1, cmp2, cmp3, cmp4;
	long long cost = 0, costReverse = Energy[0], temp = 0;

	for (i = 1; i < n; i++)
	{
		cin >> str2;
		reverse2 = str2;
		reverse(reverse2.begin(), reverse2.end());

		temp = cost;

		cmp1 = strcmp(str2.c_str(), str1.c_str()) >= 0;
		cmp2 = strcmp(str2.c_str(), reverse1.c_str()) >= 0;

		if (cmp1 && cmp2) cost = min(cost, costReverse);
		else if (cmp1) cost = cost;
		else if (cmp2) cost = costReverse;
		else cost = LLONG_MAX;

		cmp3 = (strcmp(reverse2.c_str(), str1.c_str()) >= 0) && temp != LLONG_MAX;
		cmp4 = (strcmp(reverse2.c_str(), reverse1.c_str()) >= 0) && costReverse != LLONG_MAX;

		if (cmp3 && cmp4) costReverse = min(temp, costReverse) + Energy[i];
		else if (cmp3) costReverse = temp + Energy[i];
		else if (cmp4) costReverse = costReverse + Energy[i];
		else costReverse = LLONG_MAX;

		if (cost == LLONG_MAX && costReverse == LLONG_MAX) break;
		str1 = str2; reverse1 = reverse2;
	}		

	if (i == n) cout << min(cost, costReverse);
	else cout << -1;
}