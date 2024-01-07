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

		// 벡터 안에 이미 있는 것인지 algorithm.find로 확인.
		if (find(name.begin(), name.end(), str) == name.end())
		{
			name.push_back(str);
		}
	}

	// 벡터 안을 정렬
	sort(name.begin(), name.end(), [](const string& ls, const string& rs) {
		// 길이가 같으면 사전식 정렬.
		if (ls.length() == rs.length())
			return ls < rs;
		else return ls.length() < rs.length(); // 그렇지 않으면 길이가 짧은 것 먼저 나오게.
		});

	for (int i = 0; i < name.size(); i++)
	{
		cout << name[i] + "\n";
	}
}