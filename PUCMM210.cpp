/*
USER: zobayer
TASK: PUCMM210
ALGO: math
*/

#include <cstdio>

typedef long long i64;

const int MOD = 1000000003;

inline i64 mod(i64 a) {
	return a < MOD ? a : a % MOD;
}

int main() {
	int test, i;
	i64 sum, n, p[6], co[6] = {0, 4, 30, 50, 30, 6}, inv = 441666668;
	scanf("%d", &test);
	while(test--) {
		scanf("%lld", &n);
		for(i = 1, p[0] = 1; i <= 5; i++) p[i] = mod(n * p[i-1]);
		for(i = 1; i <= 5; i++) p[i] = mod(co[i] * p[i]);
		for(i = 1, sum = 0; i <= 5; i++) sum = mod(sum + p[i]);
		sum = mod(sum * inv);
		printf("%lld\n", sum);
	}
	return 0;
}
