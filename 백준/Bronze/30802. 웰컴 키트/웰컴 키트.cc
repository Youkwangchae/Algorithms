#include <iostream>
#include <cmath>
using namespace std;

long long n;
double S, M, L, XL, XXL, XXXL;

long long t, p;
long long tAns, pAns, mAns;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	cin >> S >> M >> L >> XL >> XXL >> XXXL;

	cin >> t >> p;

	tAns = 0;
	pAns = 0;
	mAns = 0;

	tAns += (long long)(ceil(S / t) + ceil(M / t) + ceil(L / t) + ceil(XL / t) + ceil(XXL / t) + ceil(XXXL / t));

	pAns = n / p;
	mAns = n % p;

	cout << tAns << '\n';
	cout << pAns << ' ' << mAns;
}