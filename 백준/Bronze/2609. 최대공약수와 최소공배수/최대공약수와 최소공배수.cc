#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	string str;
	getline(cin, str);

	istringstream ss(str);

	int num1 = 0;
	int num2 = 0;

	ss >> num1 >> num2;
	
	int vec1[10000] = { 0, };
	int vec2[10000] = { 0, };

	int check1 = 2;
	int cnt1 = 1;

	while (num1 > 1) {
		if (num1 % check1 == 0)
		{
			num1 = num1 / check1;
			vec1[cnt1] += 1;
		}
		else
		{
			cnt1++;
			check1++;
		}		
	}

	int check2 = 2;
	int cnt2 = 1;

	while (num2 > 1) {
		if (num2 % check2 == 0)
		{
			num2 = num2 / check2;
			vec2[cnt2] += 1;
		}
		else
		{
			cnt2++;
			check2++;
		}		
	}

	int co_min = 1;
	int co_max = 1;

	for (int i = 0; i < 10000; i++) {
		if (vec1[i] != 0 && vec2[i] != 0)
		{
			if (vec1[i] > vec2[i])
			{
				co_max *= pow((i + 1), vec1[i]);
				co_min *= pow((i + 1), vec2[i]);
			}
			else
			{
				co_max *= pow((i + 1), vec2[i]);
				co_min *= pow((i + 1), vec1[i]);
			}
		}			
		else if (vec1[i] != 0)
		{
			co_max *= pow((i + 1), vec1[i]);
		}
		else if (vec2[i] != 0)
		{
			co_max *= pow((i + 1), vec2[i]);
		}
	}

	cout << co_min << endl << co_max;
}