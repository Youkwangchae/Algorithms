#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> name;

	string str;
	int count;

	// 단어 수 입력받기
	cin >> count;

	// 입력받은 단어 모두 벡터에 저장.
	for (int i = 0; i < count; i++)
	{
		cin >> str;

		if (find(name.begin(), name.end(), str) == name.end())
		{
			name.push_back(str);
		}
	}

	// 벡터 안을 정렬

	sort(name.begin(), name.end(), [](const string& ls, const string& rs) {
		if (ls.length() == rs.length())
			return ls < rs;
		else return ls.length() < rs.length();
		});

	for (int i = 0; i < name.size(); i++)
	{
		cout << name[i] + "\n";
	}
}