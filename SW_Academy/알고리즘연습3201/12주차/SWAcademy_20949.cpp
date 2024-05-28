#include <iostream>

using namespace std;

int test, n, q;

long long A[500005];

class myNode {
public:
	long long mx;
	long long Left, Right;
};

myNode myNodes[500005];

void building(long long nd, long long lf, long long rt)
{
	myNodes[nd].Left = lf;
	myNodes[nd].Right = rt;

	if (lf == rt)
	{
		myNodes[nd].mx = A[lf];
		return;
	}

	long long mid = (lf + rt) / 2;
	building(nd * 2, lf, mid);
	building(nd * 2 + 1, mid + 1, rt);

	myNodes[nd].mx = max(myNodes[nd * 2].mx, myNodes[nd * 2 + 1].mx);
}

void update(long long nd, long long index, long long v)
{
	if (myNodes[nd].Left == myNodes[nd].Right)
	{
		myNodes[nd].mx = v;
		return;
	}

	long long mid = (myNodes[nd].Left + myNodes[nd].Right) / 2;

	if (index <= mid) update(nd * 2, index, v);
	else update(nd * 2 + 1, index, v);

	myNodes[nd].mx = max(myNodes[nd * 2].mx, myNodes[nd * 2 + 1].mx);
}

long long query(long long nd, long long lf, long long rt)
{
	if (myNodes[nd].Left == lf && myNodes[nd].Right == rt)
	{
		return myNodes[nd].mx;
	}

	long long mid = (myNodes[nd].Left + myNodes[nd].Right) / 2;

	long long leftMax, rightMax;
	leftMax = rightMax = 0;

	if (lf <= mid) leftMax = query(nd * 2, lf, min(mid, rt));
	if (mid < rt) rightMax = query(nd * 2 + 1, max(mid + 1, lf), rt);

	return max(leftMax, rightMax);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> test;

	for (int j = 1; j <= test; j++)
	{
		cin >> n >> q;

		for (int i = 1; i <= n; i++)
			cin >> A[i];

		building(1, 1, n);

		int op, l, r;
		long long answer = 0;	

		for (int i = 1; i <= q; i++)
		{
			cin >> op >> l >> r;
			if (op == 1)
			{
				// query
				answer += query(1, l, r);
			}
			else
			{
				// update
				update(1, l, r);
			}
		}

		cout << "#" << j << ' ' << answer << '\n';
	}

	return 0;
}