#include <iostream>
using namespace std;

int n, m, k;

class Node
{
public:
	long long sum;
	int left, right, updateNum;
};

Node myNodes[5000005];
long long A[1000005];

void build(long long x, long long L, long long R)
{
	myNodes[x].left = L;
	myNodes[x].right = R;

	if (L == R)	// Leaf임.
	{
		myNodes[x].sum = A[L];
	}
	else
	{
		long long mid = (L + R) / 2;

		build(x * 2, L, mid);
		build(x * 2 + 1, mid + 1, R);

		myNodes[x].sum = myNodes[x * 2].sum + myNodes[x * 2 + 1].sum;
	}
}

long long query(long long x, long long L, long long R)
{
	long long mid, rvl, rvr;
	if (L == myNodes[x].left && R == myNodes[x].right)
	{
		return myNodes[x].sum;
	}
	else
	{
		mid = (myNodes[x].left + myNodes[x].right) / 2;
		rvl = rvr = 0;

		if (L <= mid) rvl = query(x * 2, L, min(mid, R));
		if (R > mid) rvr = query(x * 2 + 1, max(L, mid + 1), R);

		return rvl + rvr;
	}
}

void update(long long x, long long i, long long v)
{
	long long mid;

	if (myNodes[x].left == myNodes[x].right)
		myNodes[x].sum = v;
	else
	{
		mid = (myNodes[x].left + myNodes[x].right) / 2;
		if (i <= mid) update(x * 2, i, v);
		else update(x * 2 + 1, i, v);

		myNodes[x].sum = myNodes[x * 2].sum + myNodes[x * 2 + 1].sum;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
	}

	build(1, 1, n);

	long long op, a, b;
	for (int i = 1; i <= m + k; i++)
	{
		cin >> op >> a >> b;

		if (op == 1)
		{
			// update
			update(1, a, b);
		}
		else
		{
			// sum
			cout << query(1, a, b) << '\n';
		}
	}

	return 0;
}