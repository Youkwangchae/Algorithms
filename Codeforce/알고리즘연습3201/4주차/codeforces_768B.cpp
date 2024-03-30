#include <iostream>
using namespace std;

long long solve(long long n, long long l, long long r)
{
	long long newNum, mid, length;

	newNum = n/2; length = 1;
	while(newNum > 0)
	{
		newNum /= 2; 
		length = length * 2 + 1;			// 가운데엔 mod 2 연산한게 오므로.
	}

	if (l == 1 && r == length) return n;	// l이 처음이고, r이 끝이면 그 안에 1은 n개 있으니 그냥 n 리턴.

	mid = (length + 1)/ 2;					// 중간을 기준으로. 가운데는 n % 2 연산한게 있다.

	if (l > mid) return solve(n / 2, l - mid, r - mid);					// l이 가운데 오른쪽이면, mid 기준 오른쪽만 보면 됨.
	if (r < mid) return solve(n / 2, l, r);								// r이 가운데 왼쪽이면, mid 기준 왼쪽만 보면 됨.
	if (l == mid && r == mid) return n % 2;								// l과 r이 모두 가운데면, mod 2 연산한거 내보내면 됨.
	if (l == mid) return solve(n / 2, 1, r - mid) + n % 2;				// l이 가운데면, mid 바로 오른쪽부터 쭉 오른쪽만 보면 됨.
	if (r == mid) return solve(n / 2, l, mid - 1) + n % 2;				// r이 가운데면, 맨 처음부터 mid 바로 왼쪽까지 보면 됨.

	// 이제 mid를 기준으로, l은 왼쪽, r은 오른쪽임이 보장됨.
	// 한번에 하지 말고, l~mid - 1, mid, mid + 1 ~ r로 쪼개서 보자.
	return solve(n / 2, l, mid - 1) + solve(n / 2, 1, r-mid) + n % 2;	// mid 기준으로, l부터 mid 바로 왼쪽까지 보고, mid 바로 오른쪽부터 r까지 본 후, mid의 값을 보자.
}

int main()
{
	long long n, l, r;
	cin >> n >> l >> r;
	
	cout << solve(n, l, r);
}