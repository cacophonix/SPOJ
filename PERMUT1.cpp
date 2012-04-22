/*
USER: zobayer
TASK: PERMUT1
ALGO: dynamic programming
*/

#include <cstdio>
using namespace std;

int cnt[16][128];

void calc() {
	int i, j, k;
	cnt[1][0] = 1;
	for(i=1; i<12; i++) {
		for(j=0; cnt[i][j]; j++) {
			for(k=j; k<=i+j; k++) {
				cnt[i+1][k] += cnt[i][j];
			}
		}
	}
}

int main() {
	int t, n, k;
	calc();
	for(scanf("%d", &t); t; t--) {
		scanf("%d%d", &n, &k);
		printf("%d\n", cnt[n][k]);
	}
	return 0;
}
