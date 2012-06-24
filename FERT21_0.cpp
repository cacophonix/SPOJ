/*
USER: zobayer
TASK: FERT21_0
ALGO: math, big integer
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 1010

char ans[MAX][2*MAX], res[2*MAX];
int len[MAX], reslen;

void multiply(int n)
{
	int i, carry, a, k, p;
	for(i=k=carry=0; i<len[n-1] || carry; i++, k++)
	{
		a = (i<len[n-1])? ans[n-1][i]-'0' : 0;
		ans[n][k] = (a * 5 + carry) % 10 + '0';
		carry = (a * 5 + carry) / 10;
	}
	p = (n==1)? 0 : len[n-1];
	for(; k<=p; k++) ans[n][k] = '0';
	ans[n][k] = 0;
	len[n] = k;
}

void by2(int n)
{
	int i, k, carry, a;
	for(i=k=carry=0; i<len[n] || carry; i++, k++)
	{
		a = (i<len[n])? ans[n][i]-'0' : 0;
		res[k] = (a * 2 + carry) % 10 + '0';
		carry = (a * 2 + carry) / 10;
	}
	for(; k<len[n]; k++) res[k] = '0';
	res[k] = 0;
	reverse(res, res + k);
	for(--k; k>0; k--)
	{
		if(res[k]=='0') res[k] = 0;
		else break;
	}
}

int main()
{
	int i, t, n;
	ans[0][0] = '1', len[0] = 1;
	for(i=1; i<=MAX; i++) multiply(i);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		if(n>1)
		{
			by2(n);
			printf("0.%s\n", res);
		}
		else printf("1\n");
	}
	return 0;
}

