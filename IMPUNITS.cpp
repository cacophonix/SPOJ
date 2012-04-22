/*
USER: zobayer
TASK: IMPUNITS
ALGO: math
*/

#include <cstdio>
using namespace std;

typedef long long i64;

inline i64 gcd(i64 a, i64 b) {
	while(b) b ^= a ^= b ^= a %= b;
	return a;
}

inline i64 lcm(i64 a, i64 b) {
	return a / gcd(a, b) * b;
}

int main() {
	int n, i, a, b;
	i64 mul, back, fwrd, metric[10][2];
	while(scanf("%d", &n)==1 && n > 1) {
		for(--n, i = 0; i < n; i++) {
			scanf("%d%d", &a, &b);
			metric[i][0] = a, metric[i][1] = b;
		}
		for(fwrd = back = i = 1; i < n; i++) {
			mul = lcm(metric[i-1][1], metric[i][0]);
			back *= mul / metric[i-1][1];
			fwrd *= mul / metric[i][0];
		}
		metric[0][0]*=back, metric[n-1][1]*=fwrd;
		mul = gcd(metric[0][0], metric[n-1][1]);
		printf("%lld %lld\n", metric[0][0] / mul, metric[n-1][1] / mul);
	}
	return 0;
}
