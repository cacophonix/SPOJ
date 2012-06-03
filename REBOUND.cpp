/*
USER: zobayer
TASK: REBOUND
ALGO: geometry
*/

#include <cstdio>
#include <cmath>

typedef long long i64;

int main() {
	int test, cs;
	i64 x, y, z, rt, a, b, d;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lld %lld %lld", &x, &y, &z);
		d = x*x + y*y + 2*y*z;
		rt = (long long)sqrt((double)d);
		if(rt * rt != d) printf("Not this time.\n");
		else {
			a = 2*x*z + 2*z*rt;
			b = 2*y + 4*z;
			if(a % b) printf("Not this time.\n");
			else printf("%lld\n", a / b);
		}
	}
	return 0;
}