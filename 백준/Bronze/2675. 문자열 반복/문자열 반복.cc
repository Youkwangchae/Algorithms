#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int count;
	cin >> count;
	
	int repeat;
	string str = "";

	string paste = "";

	for (int i = 0; i < count; i++)
	{
		paste = "";
		cin >> repeat >> str;

		for (int j = 0; j < str.length(); j++)
		{
			for(int a = 0; a < repeat; a++)
				paste += str[j];			
		}

		cout << paste << "\n";
	}
}