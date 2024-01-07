#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> nums;

	int count;
	int num;

	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cin >> num;
		nums.push_back(num);
	}

	sort(nums.begin(), nums.end());

	for (int i = 0; i < count; i++)
	{
		cout << nums[i] << "\n";
	}
}