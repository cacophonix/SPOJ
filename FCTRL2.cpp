/*
USER: zobayer
TASK: FCTRL2
ALGO: math, big integer
*/

#include <cstdio>
#include <cstring>

#define MAXDIGIT 101
#define MAXLENGTH 159

using namespace std;

char factorial[MAXDIGIT][MAXLENGTH];

void multiply(int k)
{
	int carry = 0, sum, i = 0, len = strlen(factorial[k-1]);
	while(i<len)
	{
		sum = carry + (factorial[k-1][i] - '0') * k;
		factorial[k][i++] = (sum % 10) + '0';
		carry = sum/10;
	}
	while(carry>0)
	{
		factorial[k][i++] = (carry%10) + '0';
		carry/=10;
	}
}

int main()
{
	int n, k, len, t;
	factorial[0][0]='1'; factorial[1][0]='1';
	for(k=2;k<MAXDIGIT;k++)
		multiply(k);
	for(scanf("%d",&t);t;t--)
	{
		scanf("%d",&n);
	 	len = strlen(factorial[n]);
	 	for(k=len-1;k>=0;k--)
			printf("%c",factorial[n][k]);
		printf("\n");
	}
	return 0;
}

