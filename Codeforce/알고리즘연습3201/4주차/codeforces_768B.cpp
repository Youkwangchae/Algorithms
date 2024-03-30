#include <iostream>
using namespace std;

long long solve(long long n, long long l, long long r)
{
	long long newNum, mid, length;

	newNum = n/2; length = 1;
	while(newNum > 0)
	{
		newNum /= 2; 
		length = length * 2 + 1;			// ����� mod 2 �����Ѱ� ���Ƿ�.
	}

	if (l == 1 && r == length) return n;	// l�� ó���̰�, r�� ���̸� �� �ȿ� 1�� n�� ������ �׳� n ����.

	mid = (length + 1)/ 2;					// �߰��� ��������. ����� n % 2 �����Ѱ� �ִ�.

	if (l > mid) return solve(n / 2, l - mid, r - mid);					// l�� ��� �������̸�, mid ���� �����ʸ� ���� ��.
	if (r < mid) return solve(n / 2, l, r);								// r�� ��� �����̸�, mid ���� ���ʸ� ���� ��.
	if (l == mid && r == mid) return n % 2;								// l�� r�� ��� �����, mod 2 �����Ѱ� �������� ��.
	if (l == mid) return solve(n / 2, 1, r - mid) + n % 2;				// l�� �����, mid �ٷ� �����ʺ��� �� �����ʸ� ���� ��.
	if (r == mid) return solve(n / 2, l, mid - 1) + n % 2;				// r�� �����, �� ó������ mid �ٷ� ���ʱ��� ���� ��.

	// ���� mid�� ��������, l�� ����, r�� ���������� �����.
	// �ѹ��� ���� ����, l~mid - 1, mid, mid + 1 ~ r�� �ɰ��� ����.
	return solve(n / 2, l, mid - 1) + solve(n / 2, 1, r-mid) + n % 2;	// mid ��������, l���� mid �ٷ� ���ʱ��� ����, mid �ٷ� �����ʺ��� r���� �� ��, mid�� ���� ����.
}

int main()
{
	long long n, l, r;
	cin >> n >> l >> r;
	
	cout << solve(n, l, r);
}