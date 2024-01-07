#include <iostream>
using namespace std;

// 홀수 일 경우, 가운데 기준 좌우 한자리 씩 옮겨가며 비교.
bool binary_search(string str, int size)
{
	int l, r, m;

	l = 0, r = str.length() - 1;
	m = (l + r) / 2;

	if (size == (l + r) / 2) return true;

	if (str.at(m - 1 - size) == str.at(m + 1 + size)) return binary_search(str, size + 1);
	else return false;
}

string even_search(string str)
{
	if (str.length() == 2)
	{
		if (str[0] == str[1])
			return "\nyes";
		else
			return "\nno";
	}

	if (str.length() == 4)
	{
		if (str[0] == str[3] && str[1] == str[2])
			return "\nyes";
		else
			return "\nno";
	}
}

string isPalindrome(string total) {
	string input;
	cin >> input;

	if (input == "0") return total;

	// 짝수면 중간 부터가 아닌 단순 비교.
	if (input.length() % 2 == 0) {
		return isPalindrome(total + even_search(input));
	}
	else if (!binary_search(input, 0)) return isPalindrome(total + "\nno");
	else return isPalindrome(total + "\nyes");
}

int main()
{
	string str;			
	string ans = isPalindrome("");

	if (ans.length() > 0) ans.erase(ans.begin());
	cout << ans;
}