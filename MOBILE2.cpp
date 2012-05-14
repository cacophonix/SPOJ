/*
USER: zobayer
TASK: MOBILE2
ALGO: greedy
*/

#include <cstdio>

const int MAXN = 200000;

int L[MAXN], R[MAXN], lo[MAXN], hi[MAXN];

int main() {
	int test, cs, i, n, sol, l, r;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 1; i <= n; i++) {
			scanf("%d %d", &L[i], &R[i]);
			if(L[i] == -1) L[i] = 0;
			if(R[i] == -1) R[i] = 0;
		}
		for(i = n, sol = 0; i >= 1; i--) {
			l = L[i], r = R[i];
			if(hi[r] > lo[l]) sol++;
			lo[i] = (lo[l] < lo[r] ? lo[l] : lo[r]) + 1;
			hi[i] = (hi[l] > hi[r] ? hi[l] : hi[r]) + 1;
			if((lo[l] != hi[l] && lo[r] != hi[r]) || (hi[i] - lo[i] > 1)) {
				printf("-1\n");
				break;
			}
		}
		if(i < 1) printf("%d\n", sol);
	}
	return 0; 
}
