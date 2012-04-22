/*
USER: zobayer
TASK: REC
ALGO: recursion
*/

#include <stdio.h>
#include <string.h>

#define MAX 200

int lastlen;

void rightshift(char *str)
{
	int i, mod, div, f, a, j;
	for(i=j=f=mod=0; str[i]; i++)
	{
		a = str[i]-'0';
		div = (mod*10 + a)>>1;
		mod = (mod*10 + a)&1;
		if(div) f = 1;
		if(f) str[j++] = div + '0';
	}
	if(!j) str[j++] = '0';
	str[j] = 0;
	lastlen = j;
}

int bigmod(char *str, int m)
{
	int i, mod;
	for(i=mod=0; str[i]; i++)
		mod = (mod*10 + str[i]-'0') % m;
	return mod;
}

inline bool isodd(char *n)
{
	return ((n[lastlen-1]-'0') & 1);
}

long long solve(int x, long long &y, char *n, int m)
{
	if(n[0]=='1' && n[1]==0)
	{
		y = x;
		return 1;
	}
	bool f = isodd(n);
	rightshift(n);
	long long r = solve(x, y, n, m);
	r = r * (1 + y);
	y = y * y;
	if(f)
	{
		r = r + y;
		y = y * x;
	}
	y = y % m;
	return r % m;
}

int main()
{
	int a, b, m, t;
	long long y, r;
	char A[MAX], B[MAX], N[MAX];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s%s%s%d", A, B, N, &m);
		if(m==1) printf("0\n");
		else if(N[0]=='0' && N[1]==0) printf("1\n");
		else
		{
			lastlen = strlen(N);
			a = bigmod(A, m);
			b = bigmod(B, m);
			r = solve(a, y, N, m);
			r = (y + b*r) % m;
			printf("%lld\n", r);
		}
	}
	return 0;
}
