/*
USER: zobayer
TASK: ZIGZAG
ALGO: math
*/

#include <cstdio>
using namespace std;

typedef long long i64;
const int LEN = 300003;
char buff[LEN];

inline i64 getlevel(i64 p, i64 n) {
	if(p <= n) return ((p+1) * p) >> 1;
	p = n + n - p - 1;
	return n * n - ((p * (p+1)) >> 1);
}

inline i64 getval(i64 x, i64 y, i64 n) {
	i64 en, p = x + y - 1;
	en = getlevel(p, n);
	if(p > n) x -= p - n, y -= p - n;
	if(p&1) return en - x + 1;
	else return en - y + 1;
}

int main() {
	int i, n, len, r, c;
	i64 total;
	scanf("%d%d%s", &n, &len, buff);
	for(i=0, total=r=c=1; i < len; i++) {
		switch(buff[i]) {
			case 'U': total += getval(--r, c, n); break;
			case 'D': total += getval(++r, c, n); break;
			case 'L': total += getval(r, --c, n); break;
			case 'R': total += getval(r, ++c, n); break;
		}
	}
	printf("%lld\n", total);
	return 0;
}
