#include <iostream>
using namespace std;

int nums[10001] = { 0, }; // 숫자가 10000이하 자연수 들이니 횟수로 저장.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count;
	cin >> count;

	short num;
	for (int i = 0; i < count; i++)
	{
		cin >> num;
		nums[num-1]++;
	}	

	for (int a = 0; a < 10000; a++) {
		while (nums[a]--)
		{
			cout << a + 1 << "\n";
		}
	}	
}