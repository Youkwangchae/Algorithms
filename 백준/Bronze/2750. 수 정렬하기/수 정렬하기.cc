#include <iostream>
#include <vector>

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

	int temp, min;
	for (int i = 0; i < count; i++)
	{
		min = i;
		for (int j = i; j < count; j++)
		{
			if (nums[min] > nums[j])
				min = j;
		}

		temp = nums[min]; nums[min] = nums[i]; nums[i] = temp;
	}

	for (int i = 0; i < count; i++)
	{
		cout << nums[i] << endl;
	}
}