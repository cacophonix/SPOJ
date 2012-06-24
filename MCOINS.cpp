/*
USER: zobayer
TASK: MCOINS
ALGO: ad-hoc
*/

#include <stdio.h>

#define MAX 1000032
#define ch(x) (f[x>>5]&(1<<(x&31)))
#define st(x) (f[x>>5]|=(1<<(x&31)))

unsigned f[MAX>>5];
char res[60];
int l, k, last, n;

void calc()
{
	int i;
	for(i=last+1; i<=n; i++)
	{
		if(ch(i)) continue;
		if(i+1 < MAX) st((i+1));
		if(i+l < MAX) st((i+l));
		if(i+k < MAX) st((i+k));
	}
	last = n;
}

int main()
{
	int i, m;
	last = -1;
	scanf("%d %d %d", &k, &l, &m);
	for(i=0; i<m; i++)
	{
		scanf("%d", &n);
		if(n > last) calc();
		res[i] = (ch(n))? 'A' : 'B';
	}
	puts(res);
	return 0;
}
