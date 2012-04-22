/*
USER: zobayer
TASK: YODANESS
ALGO: divide and conquer
*/

#include <cstdio>
#include <map>
#include <string>
using namespace std;

const int MAX = 30003, LEN = 33;
int total;

void Merge(int *a, int p, int q, int r)
{
	int i, j, k, n1 = q-p+1, n2 = r-q;
	int L[n1], R[n2];
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

map< string, int > M;
map< string, int > :: iterator mit;
char word[MAX][LEN];
int a[MAX];

int main() {
	int t, n, i;
	char temp[LEN];
	scanf("%d", &t);
	while(t--) {
		M.clear();
		scanf("%d", &n);
		for(i = 0; i < n; i++) scanf("%s", word[i]);
		for(i = 0; i < n; i++) {
			scanf("%s", temp);
			M.insert(pair< string, int >(temp, i));
		}
		for(i = 0; i < n; i++) a[i] = M[word[i]];
		total = 0;
		Merge_Sort(a, 0, n-1);
		printf("%d\n", total);
	}
	return 0;
}
