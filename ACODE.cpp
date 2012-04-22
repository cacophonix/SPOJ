/*
USER: zobayer
TASK: ACODE
ALGO: dynamic programming
*/

#include <stdio.h>
#include <string.h>

#define mset(x,v) memset(x,v,sizeof(x))
#define MAX 5005
#define i64 long long
#define FS "%lld"

i64 dp[MAX];
int len;
char str[MAX];

i64 solve(int i)
{
	if(i>=len) return 1;
	if(dp[i]) return dp[i];
	if(str[i]=='0') return 0;
	i64 ret=0;
	ret += solve(i+1);
	if(i+1<len && 10*(str[i]-'0')+str[i+1]-'0' <= 26) ret += solve(i+2);
	return dp[i]=ret;
}

int main()
{
	while(scanf("%s",str)==1)
	{
		if(str[0]=='0') break;
		len = strlen(str);
		mset(dp,0);
		printf(FS"\n",solve(0));
	}
	return 0;
}
