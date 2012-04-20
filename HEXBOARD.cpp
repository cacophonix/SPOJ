/*
USER: zobayer
TASK: HEXBOARD
ALGO: simulation
*/

#include <cstdio>
using namespace std;

int main() {
	int n, i, j, sp;
	while(scanf("%d", &n)==1 && n > 0) {
		for(i = 0; i < n; i++) {
			sp = 2 * n - 1;
			for(j = sp - i * 2; j > 0; j--) putchar(' ');
			putchar('_');
			for(j = 0; j < i; j++) printf("/ \\_");
			putchar('\n');
		}
		for(i = 0; i < n; i++) {
			printf("/ \\");
			for(j = 1; j < n; j++) printf("_/ \\");
			putchar('\n');
			printf("\\_/");
			for(j = 1; j < n; j++) printf(" \\_/");
			putchar('\n');
		}
		for(i = 1; i < n; i++) {
			sp = 2 * i;
			for(j = 0; j < sp; j++) putchar(' ');
			printf("\\_/");
			for(j = 1; j < n - i; j++) printf(" \\_/");
			putchar('\n');
		}
		puts("***");
	}
	return 0;
}