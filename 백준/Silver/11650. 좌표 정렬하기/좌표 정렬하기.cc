#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Point
{
	int x;
	int y;
};

Point points[100000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int count;
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		// x, y좌표 저장.
		cin >> points[i].x >> points[i].y;
	}	

	sort(points, points + count, [](const Point p1, const Point p2) {
		if (p1.x == p2.x)
			return p1.y < p2.y;
		return p1.x < p2.x;
		});

	for (int i = 0; i < count; i++)
	{
		cout << points[i].x << " " << points[i].y << "\n";
	}
}