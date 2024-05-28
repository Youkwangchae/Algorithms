#include <iostream>

using namespace std;

class myNode {
public:
	long long sum;
	long long Left, Right;
};

int test, n, q;
long long A[500005];

myNode myNodes[500005];

void building(long long nd, long long lf, long long rt)
{
	myNodes[nd].Left = lf;
	myNodes[nd].Right = rt;

	if (lf == rt)
	{
		myNodes[nd].sum = A[lf];	
	}
	else 
	{
		long long mid = (lf+rt) / 2;

		building(nd * 2, lf, mid);
		building(nd * 2 + 1, mid + 1, rt);

		myNodes[nd].sum = myNodes[nd * 2].sum + myNodes[nd * 2 + 1].sum;
	}	
}

void update(long long nd, long long index, long long v)
{
	if (myNodes[nd].Left == myNodes[nd].Right)
	{
		myNodes[nd].sum = v;
		return;
	}

	long long mid = (myNodes[nd].Left + myNodes[nd].Right) / 2;

	if (index <= mid)
	{
		update(nd * 2, index, v);
	}
	else
	{
		update(nd * 2 + 1, index, v);
	}
	
	myNodes[nd].sum = myNodes[nd * 2].sum + myNodes[nd * 2 + 1].sum;
}

long long query(long long nd, long long lf, long long rt)
{
	if (myNodes[nd].Left == lf && myNodes[nd].Right == rt)
	{		
		return myNodes[nd].sum;
	}
	else
	{
		long long mid = (myNodes[nd].Left + myNodes[nd].Right) / 2;
		
		long long left, right;
		left = right = 0;
		
		if (lf <= mid) left = query(nd * 2, lf, min(mid, rt));
		if (rt > mid) right = query(nd * 2 + 1, max(lf, mid + 1), rt);		

		return left + right;
	}
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
		{
			cin >> A[i];
		}

		building(1, 1, n);

		int op, l, r;
		long long answer = 0;
		for (int i = 0; i < q; i++)
		{
			cin >> op >> l >> r;
			if (op == 1)
			{
				answer += query(1, l, r); // °ª °è»ê
			}
			else
			{
				// update
				update(1, l, r);
			}
		}

		cout << "#" << j << " " << answer << '\n';
	}	

	return 0;
}