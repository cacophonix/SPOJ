/*
USER: zobayer
TASK: INVCNT
ALGO: divide and conquer
*/

#include <cstdio>
using namespace std;

#define MAX 200002

int a[MAX], L[MAX/2+1], R[MAX/2+1];
long long total;

void Merge(int *a, int p, int q, int r)
{
	int i, j, k, n1 = q-p+1, n2 = r-q;
	for(i=0;i<n1;i++) L[i] = a[p+i];
	for(j=0;j<n2;j++) R[j] = a[q+j+1];
	for(k=p,i=j=0;k<=r;k++)
	{
		if(j>=n2 || (i<n1 && L[i]<=R[j])) a[k] = L[i++];
		else
		{
			total += n1-i;
			a[k] = R[j++];
		}
	}
}

void Merge_Sort(int *a, int p, int r)
{
	if(p<r)
	{
		int q = (p+r)/2;
		Merge_Sort(a,p,q);
		Merge_Sort(a,q+1,r);
		Merge(a,p,q,r);
	}
}

int main()
{
	int i, n, t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d",&n);
		total = 0;
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		Merge_Sort(a,0,n-1);
		printf("%lld\n", total);
	}
	return 0;
} 
