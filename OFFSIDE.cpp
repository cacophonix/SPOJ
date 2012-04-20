/*
USER: zobayer
TASK: OFFSIDE
ALGO: ad-hoc
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int a, d, A[11], D[11], i;
	while(scanf("%d %d", &a, &d)==2 && a + d)
	{
		for(i=0; i<a; i++) scanf("%d", &A[i]);
		for(i=0; i<d; i++) scanf("%d", &D[i]);
		sort(A, A+a);
		sort(D, D+d);
		if(A[0] < D[1]) printf("Y\n");
		else printf("N\n");
	}
	return 0;
}
