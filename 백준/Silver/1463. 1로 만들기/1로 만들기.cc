#include <iostream>
using namespace std;
int vec[1000001];
int cq(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}

int cp(int x) {
	if (x == 1)
		return 0;
	if (x == 2 || x == 3)
		return 1;
	if (vec[x] != 0)
		return vec[x];

	if (x % 3 == 0 && x % 2 == 0)
		return vec[x] = cq(cp(x - 1), cq(cp(x / 2), cp(x / 3))) + 1;
	else if (x % 3 == 0)
		return vec[x] = cq(cp(x - 1), cp(x / 3)) + 1;
	else if (x % 2 == 0)
		return vec[x] = cq(cp(x - 1), cp(x / 2)) + 1;
	else
		return vec[x] = cp(x-1)+ 1;
}

int main() {
	int n;
	cin >> n;
	cout <<cp(n);
}