/*
USER: zobayer
TASK: AE1B
ALGO: sorting
*/

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 1111

int main()
{
	int a[MAX], n, s, t, i, r, d, c;
	scanf("%d%d%d", &n, &s, &t);
	for(i=0; i<n; i++) scanf("%d", &a[i]);
	sort(a, a+n);
	r = s*t;
	d = c = 0;
	for(i=n-1; i>=0; i--)
	{
		d += a[i];
		c++;
		if(d >= r) break;
	}
	printf("%d\n", c);
	return 0;
}
