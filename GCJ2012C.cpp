/*
USER: zobayer
TASK: GCJ2012C
ALGO: simulation
*/

#include <cstdio>

int main() {
	int test, cs, a, b, m, i, k, n, div, mod, cnt, ans;
	int pow10[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &a, &b);
		cnt = 0, k = a;
		while(k) k /= 10, cnt++;
		m = pow10[cnt - 1];
		ans = 0;
		for(i = a; i <= b; i++) {
			k = n = i, cnt = 0;
			while(true) {
				div = n / 10, mod = n % 10;
				n = div + m * mod;
				if(n == k) break;
				if(mod > 0 && n >= a && n <= b) cnt++;
			}
			ans += cnt;
		}
		ans >>= 1;
		printf("Case #%d: %d\n", cs, ans);
	}
	return 0;
}