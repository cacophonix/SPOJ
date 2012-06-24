/*
USER: zobayer
TASK: MINCOUNT
ALGO: math
*/

#include <cstdio>
using namespace std;

int main()
{
	unsigned long long n, k;
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%llu", &n);
		if(n==0) { printf("0\n"); continue; }
		k = (n-1)/3;
		printf("%llu\n", (3*k*(k+1))/2 + ((n-1)%3) * (k+1));
	}
	return 0;
}
