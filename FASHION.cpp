/*
USER: zobayer
TASK: FASHION
ALGO: sorting
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <ios>
#include <algorithm>
using namespace std;

#define MAX 1001

int a[MAX], b[MAX];

int main()
{
	int t, n, i, sum;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		sum = 0;
		for(i=0; i<n; i++) scanf("%d", &a[i]);
		for(i=0; i<n; i++) scanf("%d", &b[i]);
		sort(a, a+n);
		sort(b, b+n);
		for(i=0; i<n; i++) sum += a[i]*b[i];
		printf("%d\n", sum);
	}
	return 0;
}
