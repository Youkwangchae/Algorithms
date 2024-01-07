#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
	int count;

	cin >> count;

	cin.ignore();

	string str;

	getline(cin, str);

	vector<int> nums;

	istringstream ss(str);

	string word;
	int now_num = 0;

	int max = 0;

	while (getline(ss, word, ' ')) {
		now_num = atoi(word.c_str());
		nums.push_back(now_num);
		if (now_num > max) max = now_num;
	}

	int total = 0;

	bool isPrime = false;

	for (int i = 0; i < nums.size(); i++){
		isPrime = true;

		if (nums[i] > 1) {
			for (int j = 2; j < nums[i]; j++) {
				if (nums[i] % j == 0) {
					isPrime = false;
				}
			}
		}
		else isPrime = false;

		if (isPrime) total++;
	}

	cout << total;
}