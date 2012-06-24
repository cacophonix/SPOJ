/*
USER: zobayer
TASK: GCD2
ALGO: math, gcd
*/

#include <stdio.h>

int gcd(int a, int b)
{
	while(b) b^=a^=b^=a%=b;
	return a;
}

int main()
{
	int t, i;
	int n1, n2;
	char num[300];
	for(scanf("%d",&t);t;t--)
	{
		scanf("%d%s",&n1,num);
		if(!n1)
		{
			printf("%s\n",num);
			continue;
		}
		for(i=n2=0;num[i];i++)
			n2 = (n2*10+num[i]-'0')%n1;
		printf("%d\n",gcd(n1,n2));
	}
	return 0;
}

