/*
USER: zobayer
TASK: SCPC11D
ALGO: ad-hoc
*/

#include <cstdio>

int main() {
	int a, b, c;
	while(scanf("%d %d %d", &a, &b, &c)==3 && (a|b|c)) {
		a = a * a, b = b * b, c = c * c;
		if(a + b == c || b + c == a || c + a == b) puts("right");
		else puts("wrong");
	}
	return 0;
}