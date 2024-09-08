#include <iostream>
#include <string>
using namespace std;

const int MX = 1000005;
int pre[MX], nxt[MX];
string dat[MX];
int unused = 1;
int current = 0;

void insert(int addr, int num) {
    dat[unused] = num;

    int cur = nxt[addr];

    pre[unused] = addr;
    nxt[unused] = cur;
    nxt[addr] = unused;

    if (cur != -1)
    {
        pre[cur] = unused;        
    }     
    
    unused++;
}

void erase(int addr) {
    int cur = nxt[addr];

    pre[cur] = pre[addr];
    nxt[pre[addr]] = cur;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	fill(pre, pre + MX, -1);
	fill(nxt, nxt + MX, -1);

	string str;
	cin >> str;

	int n;
	cin >> n;

	for (auto c : str)
	{
		insert(current, c);
		current++;
	}

	while (n--)
	{
		char op;
		cin >> op;

		if (op == 'P')
		{
			char add;
			cin >> add;
			insert(current, add);
			current = nxt[current];
		}
		else if (op == 'L')
		{
			if (pre[current] != -1)
				current = pre[current];
		}
		else if (op == 'D')
		{
			if (nxt[current] != -1)
				current = nxt[current];
		}
		else
		{
			if (pre[current] != -1)
			{
				erase(current);
				current = pre[current];
			}
		}
	}

	int ans = nxt[0];
	while(ans != -1)
	{		
		cout << dat[ans];
		ans = nxt[ans];
	}
}