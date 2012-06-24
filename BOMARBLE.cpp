/*
USER: zobayer
TASK: BOMARBLE
ALGO: math
*/

#include <stdio.h>

int main() {
	int n;
	while(scanf("%d", &n)==1 && n) {
		n++;
		printf("%d\n", n * (3*n - 1) / 2);
	}
	return 0;
}
