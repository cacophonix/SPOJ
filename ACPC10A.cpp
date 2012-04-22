/*
USER: zobayer
TASK: ACPC10A
ALGO: ad-hoc
*/

#include <stdio.h>

int main() {
	int a, b, c;
	while(scanf("%d%d%d", &a, &b, &c)==3 && (a|b|c)) {
		if(b - a == c - b) printf("AP %d\n", c + c - b);
		else printf("GP %d\n", c * c / b);
	}
	return 0;
}