#include <iostream>

using namespace std;

class myNode {
public:
	int cnt, lazy;	// lazy�� 1 : �Ʒ��� ���� 1. lazy�� 0 : �Ʒ��� ���� 0. lazy�� -1 : ���ص� ��.
	int Left, Right;
};

int n, q;
char S[100005];

myNode myNodes[26][400005];	// 26���� ���ĺ� 26�ڿ� ���� ���� �ϳ��� Ʈ���� ���� ��.

/// <summary>
/// Ʈ�� ����
/// </summary>
/// <param name="c"></param> // ���ĺ� c
/// <param name="nd"></param> // ���ĺ� c�� Ʈ���� ���� ��� nd�� ������ ����.
/// <param name="left"></param> // ���ĺ� c�� Ʈ���� ��� nd�� Left ����.
/// <param name="right"></param> // ���ĺ� c�� Ʈ���� ��� nd�� Right ����.
/// <returns></returns> // ���ĺ� c�� Ʈ���� ��� nd�� ���� ���� cnt ���� ����.
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
/// �ڽ� ���鿡 ���� lazy, cnt���� ���� ����.
/// </summary>
/// <param name="c"></param>
/// <param name="nd"></param>
void pushDown(int c, int nd)	
{
	if (myNodes[c][nd].lazy == 1)	// �� ���� lazy�� ��� 1.
	{
		myNodes[c][nd * 2].lazy = 1;
		myNodes[c][nd * 2 + 1].lazy = 1;

		myNodes[c][nd * 2].cnt = myNodes[c][nd * 2].Right - myNodes[c][nd * 2].Left + 1;
		myNodes[c][nd * 2 + 1].cnt = myNodes[c][nd * 2 + 1].Right - myNodes[c][nd * 2 + 1].Left + 1;
	}
	else if (myNodes[c][nd].lazy == 0) // �� ���� lazy�� ��� 0.
	{
		myNodes[c][nd * 2].lazy = 0;
		myNodes[c][nd * 2 + 1].lazy = 0;

		myNodes[c][nd * 2].cnt = 0;
		myNodes[c][nd * 2 + 1].cnt = 0;
	}
	else
	{
		// lazy�� -1�̸� ��.
	}

	myNodes[c][nd].lazy = -1;
}

/// <summary>
/// �ڽ� ������ cnt ������ �� ����� cnt �� ������Ʈ.
/// </summary>
/// <param name="c"></param>
/// <param name="nd"></param>
void pullUp(int c, int nd)
{
	myNodes[c][nd].cnt = myNodes[c][nd * 2].cnt + myNodes[c][nd * 2 + 1].cnt;
}

/// <summary>
/// Ʈ�� c�� ��� nd�� lazy���� v ��, cnt���� v�� ���� ������Ʈ.
/// </summary>
/// <param name="c"></param>
/// <param name="nd"></param>
/// <param name="left"></param>
/// <param name="right"></param>
/// <param name="v"></param>
void update(int c, int nd, int left, int right, int v)
{
	if (left <= myNodes[c][nd].Left && right >= myNodes[c][nd].Right)	// ���� �ȿ� lazy�� ������ �׳� ��ü �� �ϸ� ��.
	{
		myNodes[c][nd].lazy = v;
		if (v == 1)
			myNodes[c][nd].cnt = myNodes[c][nd].Right - myNodes[c][nd].Left + 1;
		else
			myNodes[c][nd].cnt = 0;
	}
	else // ���� �ȿ� lazy�� ������, �¿� ������ ��.
	{
		int mid = (myNodes[c][nd].Left + myNodes[c][nd].Right) / 2;

		// �ڽ� ���� ������Ʈ
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
		// �ڽ� �����κ��� �� ��� ������Ʈ.
		pullUp(c, nd);
	}
}

/// <summary>
/// Ʈ�� c�� ��� nd�� ���� cnt ����
/// </summary>
/// <param name="c"></param>
/// <param name="nd"></param>
/// <param name="left"></param>
/// <param name="right"></param>
/// <returns></returns>
int query(int c, int nd, int left, int right)
{
	if (left <= myNodes[c][nd].Left && right >= myNodes[c][nd].Right)	// ���� �ȿ� ������ �ٷ� return.
	{
		return myNodes[c][nd].cnt;
	}	
	else 
	{
		// ���� ���̴� �ڽ� ���� ������Ʈ �ϰ�, �� ��� ���� ������Ʈ.
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