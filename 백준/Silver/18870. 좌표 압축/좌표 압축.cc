#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
vector<int> point;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;

	int p;

	for (int i = 0; i < n; i++)
	{
		cin >> p;
		vec.push_back(p);
		point.push_back(p);		
	}	

	// 오름차순 정렬
	sort(vec.begin(), vec.end());

	// 겹치는 것들 삭제 
	// unique(vec.begin(), vec.end()) 하면 겹치는게 사라지는게 아니라 맨 뒤로 옮겨짐
	// 그래서 erase로 지워야 제대로 사라짐. unique가 반환한 iterator는 unique가 만든 마지막 값을 가리키고 있기 때문.
	// unique의 시간복잡도는 O(N)이다.
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for(int i=0;i< point.size();i++)
	cout << lower_bound(vec.begin(), vec.end(), point[i]) - vec.begin() << " ";
}