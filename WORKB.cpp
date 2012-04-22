/*
USER: zobayer
TASK: WORKB
ALGO: greedy
*/

#include <cstdio>

#define i64 long long
#define MAX 100001
#define min(a,b) ((a)<(b)?(a):(b))

int main() {
	int test, cs, n, i, tm[MAX];
	i64 fair, sal, res;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %lld %lld", &n, &fair, &sal);
		for(i = 0; i < n; i++) scanf("%d", tm + i);
		res = fair + sal;
		for(i = n-2; i >= 0; i--) res += sal + min(fair<<1, sal*(tm[i+1]-tm[i]-1));
		res += fair;
		printf("Case #%d: %lld\n", cs, res);
	}
	return 0;
}