#include <iostream>
#include <string>
using namespace std;

int P(int n, int k)
{
	// k로 0이 들어왔을 경우 예외처리
	if (k == 0) return 1; 

	if (k == 1) return n;
	return (n * P(n - 1, k - 1));
}

int factorial(int val)
{
	// k로 0이 들어왔을 경우 예외처리
	if (val == 0) return 1;

	if (val == 1) return 1;

	return (val * factorial(val - 1));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int n, k;
	cin >> n >> k;

	cout << to_string(P(n, k) / factorial(k));
}