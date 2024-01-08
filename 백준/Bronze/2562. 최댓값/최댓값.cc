#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num = 0;
	int max = 0;
	int max_count = 0;

	for(int i=0;i<9;i++)
	{			
		cin >> num;
		if (num > max)
		{
			max = num;
			max_count = (i+1);
		}
	}

	cout << max << "\n" << max_count;
}