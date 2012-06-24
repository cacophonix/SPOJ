/*
USER: zobayer
TASK: STAMPS
ALGO: sorting
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int t, x, n, a[1001], s, i, c;
	ios::sync_with_stdio(false);
	cin >> t;
	for(x = 1; x <= t; x++)
	{
		cin >> s >> n;
		for(i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a+n);
		for(i = n-1, c = 0; i >= 0; i--)
		{
			c += a[i];
			if(c >= s) break;
		}
		cout << "Scenario #" << x << ":\n";
		if(i==-1) cout << "impossible\n";
		else cout << n-i << endl;
		cout << endl;
	}
	return 0;
}
