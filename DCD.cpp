/*
USER: zobayer
TASK: DCD
ALGO: binary search
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long i64;

i64 sum[1<<18], a[18];

int main() {
	int n, m, i, j, tot, sz, mx;
	i64 am, d, lst, st, nd;
	while(scanf("%d %d", &n, &m)==2) {
		for(i = 0; i < n; i++) scanf("%lld", a + i);
		for(i = 0; i < m; i++) scanf("%lld", a + n + i);
		tot = m + n;
		for(sz = 0, i = 0; i < (1<<tot); i++) {
			for(am = j = 0; j < tot; j++) {
				if(i & (1<<j)) {
					if(j < n) am += a[j];
					else am -= a[j];
				}
			}
			sum[sz++] = am;
		}
		sort(sum, sum + sz);
		scanf("%lld", &d);
		for(i = mx = 0; i < sz; i++) {
			lst = sum[i] + d - 1;
			j = upper_bound(sum + i, sum + sz, lst) - sum;
			if(j-i > mx) {
				mx = j-i;
				st = sum[i];
				nd = sum[i] + d - 1;
			}
		}
		printf("%lld %lld %d\n", st, nd, mx);
	}
	return 0;
}
