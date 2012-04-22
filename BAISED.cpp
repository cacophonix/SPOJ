/*
USER: zobayer
TASK: BAISED
ALGO: sorting
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int a[100001];

int main()
{
	string name;
	int n, i, t;
	long long tot;
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(i=0; i<n; i++) cin >> name >> a[i];
		sort(a, a+n);
		tot = 0;
		for(i=0; i<n; i++) tot += abs(a[i]-(i+1));
		cout << tot << endl;
	}
	return 0;
}
