#include <iostream>

using namespace std;

int main()
{
	// A : 1 => -1, 0 => 1�� �ٲ� �迭.
	// B : ���� ���� ����.
	// S : Maximum SubArray�� ���۵� ����.
	// M : i��° ��ġ���� ���� ū Maximum SubArray��.
	int n, A[101], B[101], S[101], M[101];

	cin >> n;	

	for (int i = 0; i < n; i++)
	{
		cin >> B[i];
		if (B[i] == 1) A[i] = -1;
		else A[i] = 1;
	}	

	M[0] = A[0]; S[0] = 0;

	for (int i = 1; i < n; i++)
	{
		if (M[i - 1] + A[i] > A[i])
		{
			M[i] = M[i - 1] + A[i];
			S[i] = S[i - 1];
		}
		else
		{
			M[i] = A[i];
			S[i] = i;
		}
	}

	int maxLen = -1;	
	for (int i = 0; i < n; i++)
	{
		maxLen = max(M[i], maxLen);
	}

	int index = 0;
	for (int i = 0; i < n; i++)
	{
		if(M[i] == maxLen)
		{
			index = i;
		}
	}

	if (n == 1)
		cout << 1 - B[0];
	else
	{
		int ans = 0;
		for (int i = S[index]; i <= index; i++)
		{			
			B[i] = 1 - B[i];
		}				

		for (int i = 0; i < n; i++)
			ans += B[i];

		cout << ans;
	}
}