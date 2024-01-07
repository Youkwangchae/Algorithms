#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
	int count;
	cin >> count;
	cin.ignore();

	vector<pair<int, string>> vec;

	string str;

	int age;
	string name;
	
	for (int i = 0; i < count; i++)
	{
		cin >> age >> name;
		
		// 일단 벡터에 이름, 나이 쌍으로 저장.
		vec.push_back({ age, name });
	}
	
	stable_sort(vec.begin(), vec.end(), [](const pair<int, string>& lp, const pair<int, string>& rp) {
		return (lp.first < rp.first);
		});

	for (int i = 0; i < count; i++)
	{
		cout << vec[i].first << " " << vec[i].second << "\n";
	}
}