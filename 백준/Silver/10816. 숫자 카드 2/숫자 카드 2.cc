#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
int nums[2][10000000] = { 0, };	// -10,000,000 ~ 10,000,000 저장 (0 제외.)
int zero = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int count;

	cin >> count;
	cin.ignore();	

	int num;

	for (int i = 0; i < count; i++) {
		cin >> num;
		if (num > 0) nums[0][(num - 1)]++;
		else if (num < 0) nums[1][(num * -1) - 1]++;
		else zero++;
	}

	int find;
	cin >> find;
	cin.ignore();

	string ans = "";
	
	for (int i = 0; i < find; i++) {
		cin >> num;
		if (num > 0)
		{
			ans += " " + to_string(nums[0][(num - 1)]);			
		}
		else if (num < 0) 
		{
			ans += " " + to_string(nums[1][(num * -1) - 1]);
		}
		else {
			ans += " " + to_string(zero);			
		}
	}	
	
	ans.erase(ans.begin());

	cout << ans;
}