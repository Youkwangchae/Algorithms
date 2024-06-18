#include <iostream>

using namespace std;

int n, m, k;

class Node
{
public:
	long long l, r;
	long long sum = 0;
	long long lazy = 0;
};

long long A[1000005];
Node myNodes[5000005];

void update_lazy(long long x, long long L, long long R)
{
	if (myNodes[x].lazy != 0)
	{
		myNodes[x].sum += (R - L + 1) * myNodes[x].lazy;

		if (L != R)
		{
			myNodes[x * 2].lazy += myNodes[x].lazy;
			myNodes[x * 2 + 1].lazy += myNodes[x].lazy;
		}

		myNodes[x].lazy = 0;
	}
}

void building(long long x, long long l, long long r)
{
	myNodes[x].l = l;
	myNodes[x].r = r;

	if (l == r)
	{
		myNodes[x].sum = A[l];
		return;
	}
	else
	{
		long long mid = (l + r) / 2;

		building(x * 2, l, mid);
		building(x * 2 + 1, mid + 1, r);
		myNodes[x].sum = myNodes[x * 2].sum + myNodes[x * 2 + 1].sum;
	}
}

long long query(long long x, long long L, long long R, long long l, long long r)
{
	update_lazy(x, L, R);
	if (r < myNodes[x].l || myNodes[x].r < l) return 0;
	if (l <= myNodes[x].l && r >= myNodes[x].r) return myNodes[x].sum;
	
	long long mid = (myNodes[x].l + myNodes[x].r) / 2;

	long long rvl, rvr;
	rvl = rvr = 0;

	rvl = query(x * 2, L, mid, l, r);
	rvr = query(x * 2 + 1, mid + 1, R, l, r);

	return rvl + rvr;
}

void update(long long x, long long L, long long R, long long l, long long r, long long v)
{
	update_lazy(x, L, R);
	if (r < myNodes[x].l || myNodes[x].r < l) return;
	if (l <= myNodes[x].l && myNodes[x].r <= r)
	{
		myNodes[x].sum += (R - L + 1) * v;

		if (myNodes[x].l != myNodes[x].r)
		{
			myNodes[x * 2].lazy += v;
			myNodes[x * 2 + 1].lazy += v;
		}

		return;
	}

	long long mid = (myNodes[x].l + myNodes[x].r) / 2;
	update(x * 2, L, mid, l, r, v);
	update(x * 2 + 1, mid + 1, R, l, r, v);

	myNodes[x].sum = myNodes[x * 2].sum + myNodes[x * 2 + 1].sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> A[i];

	building(1, 1, n);

	long long op, a, b, c;

	for (int i = 1; i <= m + k; i++)
	{
		cin >> op;
		if (op == 1)
		{
			cin >> a >> b >> c;
			update(1, 1, n, a, b, c);
		}
		else
		{
			cin >> a >> b;
			cout << query(1, 1, n, a, b) << '\n';
		}
	}

	return 0;
}