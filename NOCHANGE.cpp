/*
USER: zobayer
TASK: NOCHANGE
ALGO: dynamic programming
*/

#include <cstring>
#include <cstdio>

#define MAX 100001
#define NC 5

using namespace std;

int main()
{
	int i, m, k, j, c[NC];
	bool f[MAX];
	while(scanf("%d", &m)==1)
	{
		scanf("%d", &k);
		for(i=0; i<k; i++) scanf("%d", &c[i]);
		for(i=1; i<k; i++) c[i] += c[i-1];
		memset(f, 0, sizeof(f));
		f[0] = 1;
		for(i=k-1; i>=0; i--)
			for(j=c[i]; j<=m; j++)
				f[j] |= f[j-c[i]];
		if(f[m]) printf("YES\n");
		else printf("NO\n");
	}	
	return 0;
}
