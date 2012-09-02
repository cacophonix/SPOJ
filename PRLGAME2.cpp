/*
USER: zobayer
TASK: PRLGAME2
ALGO: math
*/

#include <cstdio>

int main() {
	int cs = 1, n, p, q;
	while(scanf("%d %d %d", &n, &p, &q) == 3) printf("Case %d: %.4lf\n", cs++, (double)(q+1) / (p+2));
	return 0;
}
