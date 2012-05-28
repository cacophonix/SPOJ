/*
USER: zobayer
TASK: FUNPROB
ALGO: math, probability, catalan number
*/

#include <stdio.h>

int main() {
	int m, n;
	double mm, nn;
	while(scanf("%d %d", &n, &m)==2 && m+n) {
		if(!n) printf("1.000000\n");
		else if(n > m) printf("0.000000\n");
		else {
			mm = m; nn = n;
			printf("%lf\n", (mm-nn+1.0) / (mm+1.0));
		}
	}
	return 0;
}
