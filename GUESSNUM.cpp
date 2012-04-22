/*
USER: zobayer
TASK: GUESSNUM
ALGO: binary search
*/

#include <cstdio>

int main() {
	int a, b, m;
	char ver[16];
	scanf("%d %d", &a, &b);
	while(a <= b) {
		m = (a + b) >> 1;
		printf("%d\n", m);
		fflush(stdout);
		scanf("%s", ver);
		if(ver[0] == 'W') break;
		if(ver[0] == 'H') b = m-1;
		else a = m+1;
	}
	return 0;
}