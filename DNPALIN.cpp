/*
USER: zobayer
TASK: DNPALIN
ALGO: ad-hoc
*/

#include <cstdio>
#include <cstring>
using namespace std;

bool isNearPalin(char *str, int len)
{
	int cnt = 0, i, j;
	for(i=0, j=len-1; i<j; i++, j--)
		if(str[i]!=str[j])
			cnt++;
	if(cnt==1 || (!cnt && i==j)) return true;
	return false;
}

int main()
{
	char str[50], i, len;
	while(scanf("%s", str)==1)
	{
		if(!strcmp(str, "*END*")) break;
		len = strlen(str);
		for(i=1; i<len-1; i++)
			if(isNearPalin(str, i) && isNearPalin(&str[i], len-i))
				break;
		if(i<len-1) printf("%s is a double near palindrome.\n", str);
		else printf("%s is not a double near palindrome.\n", str);
	}
}

