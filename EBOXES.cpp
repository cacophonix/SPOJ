/*
USER: zobayer
TASK: EBOXES
ALGO: math
*/

#include <cstdio>

int main() {
	int cs, n, k, t, f;
	scanf("%d", &cs);
	while(cs--) {
		scanf("%d %d %d %d", &n, &k, &t, &f);
		printf("%d\n", (f - n) / (k - 1) + f);
	}
	return 0;
}
