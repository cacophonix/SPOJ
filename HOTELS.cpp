/*
USER: zobayer
TASK: HOTELS
ALGO: binary-search
*/

#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long i64;

const int MAX = 300001;

i64 sum[MAX];

int main() {
	int n, m, a, i, j;
	i64 res;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++) {
		scanf("%d", &a);
		sum[i] = sum[i-1] + a;
	}
	for(i = 1, res = 0; i <= n; i++) {
		j = (upper_bound(sum + i, sum + n + 1, sum[i-1] + m) - sum) - 1;
		if(j >= i) res = max(res, sum[j] - sum[i-1]);
	}
	printf("%lld\n", res);
	return 0;
}