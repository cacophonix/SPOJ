/*
USER: zobayer
TASK: SAMER08F
ALGO: math
*/

#include<ios>
int main()
{
	long long n;
	while(scanf("%lld",&n)==1 && n)
		printf("%lld\n",n*(n+1)*(2*n+1)/6);
	return 0;
}
