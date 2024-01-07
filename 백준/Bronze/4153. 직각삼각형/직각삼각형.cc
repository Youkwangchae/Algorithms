#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string isRightTri(int a, int b, int longNum, string total) {
	if (pow(a, 2) + pow(b, 2) == pow(longNum, 2))
		return total + "\nright";
	else
		return total + "\nwrong";
}

string checkTri(string total) {

	vector<int> new_nums;

	string str;
	getline(cin, str);

	if (str == "0 0 0")
		return total;

	istringstream ss(str);
	string word;

	while (getline(ss, word, ' ')) {
		new_nums.push_back(atoi(word.c_str()));
	}

	sort(new_nums.begin(), new_nums.end());

	return checkTri(isRightTri(new_nums[0], new_nums[1], new_nums[2], total));
}

int main()
{
	string ans = checkTri("");
	if (ans.length() > 0) ans.erase(ans.begin());
	cout << ans;
}