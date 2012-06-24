/*
USER: zobayer
TASK: CPRMT
ALGO: dynamic programming
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 1111

char s1[MAX], s2[MAX];
int len1, len2, dp[MAX][MAX];

void lcs()
{
	int i, j;
	for(i=1;i<=len1;i++)
	{
		for(j=1;j<=len2;j++)
		{
			if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
			else if(dp[i][j-1] > dp[i-1][j]) dp[i][j] = dp[i][j-1];
			else dp[i][j] = dp[i-1][j];
		}
	}
}

void print(int i, int j)
{
	if(!i || !j) return;
	if(s1[i-1]==s2[j-1])
	{
		print(i-1,j-1);
		printf("%c",s1[i-1]);
	}
	else if(dp[i][j-1] > dp[i-1][j]) print(i,j-1);
	else print(i-1,j);
}

int main()
{
	while(gets(s1))
	{
		gets(s2);
		len1 = strlen(s1);
		len2 = strlen(s2);
		sort(s1,s1+len1);
		sort(s2,s2+len2);
		lcs();
		print(len1, len2);
		printf("\n");
	}
	return 0;
}


