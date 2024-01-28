#include <iostream>
using namespace std;

pair<char, char> edge[26];

// 중위 순회
void inorder(char root) {
	if (root == '.') return;
	inorder(edge[root - 'A'].first);
	cout << root;
	inorder(edge[root - 'A'].second);
}

// 전위 순회
void preorder(char root) {
	if (root == '.') return;
	cout << root;
	preorder(edge[root - 'A'].first);
	preorder(edge[root - 'A'].second);
}

// 후위 순회
void backorder(char root) {
	if (root == '.') return;	
	backorder(edge[root - 'A'].first);
	backorder(edge[root - 'A'].second);
	cout << root;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	char root, child_left, child_right;
	for (int i = 0; i < n; i++)
	{
		cin >> root >> child_left >> child_right;
		edge[root - 'A'] = pair<char, char>(child_left, child_right);
	}		

	preorder('A');
	cout << "\n";

	inorder('A');
	cout << "\n";

	backorder('A');	
}