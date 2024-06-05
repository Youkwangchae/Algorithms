#include <iostream>

using namespace std;

class myNode {
public:
	int cnt, lazy;	// lazy가 1 : 아래가 전부 1. lazy가 0 : 아래가 전부 0. lazy가 -1 : 안해도 됨.
	int Left, Right;
};

int n, q;
char S[100005];

myNode myNodes[26][400005];	// 26개는 알파벳 26자에 대해 각각 하나의 트리로 삼은 것.

/// <summary>
/// 트리 빌딩
/// </summary>
/// <param name="c"></param> // 알파벳 c
/// <param name="nd"></param> // 알파벳 c의 트리에 대해 노드 nd의 정보를 빌드.
/// <param name="left"></param> // 알파벳 c의 트리의 노드 nd의 Left 정보.
/// <param name="right"></param> // 알파벳 c의 트리의 노드 nd의 Right 정보.
/// <returns></returns> // 알파벳 c의 트리의 노드 nd에 대해 적힌 cnt 값을 리턴.
int build(int c, int nd, int left, int right)
{
	myNodes[c][nd].Left = left;
	myNodes[c][nd].Right = right;

	if (left == right)	// leaf
	{
		if (S[left] - 'a' == c) myNodes[c][nd].cnt = 1;
		else myNodes[c][nd].cnt = 0;		
	}
	else
	{
		int mid = (left + right) / 2;
		int lr, rr;
		lr = build(c, nd * 2, left, mid);
		rr = build(c, nd * 2 + 1, mid + 1, right);
		myNodes[c][nd].cnt = lr + rr;	
	}

	myNodes[c][nd].lazy = -1;
	return myNodes[c][nd].cnt;
}

/// <summary>
/// 자식 노드들에 대해 lazy, cnt값을 내려 보냄.
/// </summary>
/// <param name="c"></param>
/// <param name="nd"></param>
void pushDown(int c, int nd)	
{
	if (myNodes[c][nd].lazy == 1)	// 내 밑의 lazy는 모두 1.
	{
		myNodes[c][nd * 2].lazy = 1;
		myNodes[c][nd * 2 + 1].lazy = 1;

		myNodes[c][nd * 2].cnt = myNodes[c][nd * 2].Right - myNodes[c][nd * 2].Left + 1;
		myNodes[c][nd * 2 + 1].cnt = myNodes[c][nd * 2 + 1].Right - myNodes[c][nd * 2 + 1].Left + 1;
	}
	else if (myNodes[c][nd].lazy == 0) // 내 밑의 lazy는 모두 0.
	{
		myNodes[c][nd * 2].lazy = 0;
		myNodes[c][nd * 2 + 1].lazy = 0;

		myNodes[c][nd * 2].cnt = 0;
		myNodes[c][nd * 2 + 1].cnt = 0;
	}
	else
	{
		// lazy가 -1이면 끝.
	}

	myNodes[c][nd].lazy = -1;
}

/// <summary>
/// 자식 노드들의 cnt 값으로 내 노드의 cnt 값 업데이트.
/// </summary>
/// <param name="c"></param>
/// <param name="nd"></param>
void pullUp(int c, int nd)
{
	myNodes[c][nd].cnt = myNodes[c][nd * 2].cnt + myNodes[c][nd * 2 + 1].cnt;
}

/// <summary>
/// 트리 c의 노드 nd의 lazy값을 v 로, cnt값은 v에 따라 업데이트.
/// </summary>
/// <param name="c"></param>
/// <param name="nd"></param>
/// <param name="left"></param>
/// <param name="right"></param>
/// <param name="v"></param>
void update(int c, int nd, int left, int right, int v)
{
	if (left <= myNodes[c][nd].Left && right >= myNodes[c][nd].Right)	// 범위 안에 lazy가 있으니 그냥 전체 다 하면 됨.
	{
		myNodes[c][nd].lazy = v;
		if (v == 1)
			myNodes[c][nd].cnt = myNodes[c][nd].Right - myNodes[c][nd].Left + 1;
		else
			myNodes[c][nd].cnt = 0;
	}
	else // 범위 안에 lazy가 없으니, 좌우 나눠야 함.
	{
		int mid = (myNodes[c][nd].Left + myNodes[c][nd].Right) / 2;

		// 자식 먼저 업데이트
		pushDown(c, nd);

		if (right <= mid)
			update(c, nd * 2, left, right, v);
		else if (left > mid)
			update(c, nd * 2 + 1, left, right, v);
		else
		{
			update(c, nd * 2, left, right, v);
			update(c, nd * 2 + 1, left, right, v);
		}
		// 자식 정보로부터 내 노드 업데이트.
		pullUp(c, nd);
	}
}

/// <summary>
/// 트리 c의 노드 nd에 대해 cnt 리턴
/// </summary>
/// <param name="c"></param>
/// <param name="nd"></param>
/// <param name="left"></param>
/// <param name="right"></param>
/// <returns></returns>
int query(int c, int nd, int left, int right)
{
	if (left <= myNodes[c][nd].Left && right >= myNodes[c][nd].Right)	// 범위 안에 있으면 바로 return.
	{
		return myNodes[c][nd].cnt;
	}	
	else 
	{
		// 범위 밖이니 자식 먼저 업데이트 하고, 내 노드 값을 업데이트.
		pushDown(c, nd);
		pullUp(c, nd);

		int mid = (myNodes[c][nd].Left + myNodes[c][nd].Right) / 2;
		if (right <= mid)
		{
			return query(c, nd * 2, left, right);
		}
		else if (left > mid)
		{
			return query(c, nd * 2 + 1, left, right);
		}
		else
		{
			int lr, rr;
			lr = query(c, nd * 2, left, right);
			rr = query(c, nd * 2 + 1, left, right);
			return lr + rr;
		}			
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	cin >> S + 1;

	for (int i = 0; i < 26; i++)
		build(i, 1, 1, n);

	int a, b, op;	
	int cnts[26];

	for (int i = 1; i <= q; i++)
	{
		cin >> a >> b >> op;

		if (op == 0)	// non-incresing
		{
			for (int j = 0; j < 26; j++)
			{
				cnts[j] = query(j, 1, a, b);
				update(j, 1, a, b, 0);
			}

			for (int c = a, j = 25; j >= 0; j--)
			{
				if (cnts[j] > 0)
					update(j, 1, c, c + cnts[j] - 1, 1);
				c += cnts[j];
			}
		}
		else			// increasing
		{
			for (int j = 0; j < 26; j++)
			{
				cnts[j] = query(j, 1, a, b);
				update(j, 1, a, b, 0);
			}

			for (int c = a, j = 0; j < 26; j++)
			{
				if (cnts[j] > 0)
					update(j, 1, c, c + cnts[j] - 1, 1);
				c += cnts[j];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int c = 0; c < 26; c++)
		{
			if (query(c, 1, i, i) == 1)
				printf("%c", c + 'a');
		}
	}
	return 0;
}