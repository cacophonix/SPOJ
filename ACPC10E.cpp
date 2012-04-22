/*
USER: zobayer
TASK: ACPC10E
ALGO: math
*/

#include <cstdio>
using namespace std;

int main() {
	int g, a, t, d, i;
	long long p, k;
	while(scanf("%d%d%d%d", &g, &t, &a, &d)==4 && g > 0) {
		k = (long long) g * a + d;
		for(i = 0; (1LL<<i) < k; i++);
		p =  (long long) t * (t-1) / 2 * g + (1LL<<i) - 1;
		printf("%d*%d/%d+%d=%lld+%lld\n", g, a, t, d, p, (1LL<<i) - k);
	}
	return 0;
}