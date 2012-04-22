/*
USER: zobayer
TASK: MAXSUB
ALGO: ad-hoc
*/

#include <cstdio>
using namespace std;

#define M 1000000009

int modxp(int p) {
	long long r = 1, b = 2;
	while(p>0) {
		if(p&1) r = (r*b)%M;
		p >>= 1;
		b = (b*b)%M;
	}
	return (int)r;
}

int main() {
	int t, n, i, z, m, a, s;
	long long p;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		m = -2147483648, p = z = 0, s = 1;
		for(i = 0; i < n; i++) {
			scanf("%d", &a);
			if(a > m) {
				m = a;
				s = 1;
			}
			else if(a == m) s++;
			if(!a) z++;
			if(a > 0) p += a;
		}
		if(m < 0) printf("%d %d\n", m, s);
		else if(m==0) printf("0 %d\n", modxp(z)-1);
		else printf("%lld %d\n", p, modxp(z));
	}
	return 0;
}