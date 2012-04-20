/*
USER: zobayer
TASK: COMDIV
ALGO: math
*/

#include <stdio.h>
#include <math.h>

char buff[14000000], *ptr = buff;
int flag[1000000>>6], primes[78500], total;

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

inline void sieve() {
	register int i, j, k;
	for(i = 3; i < 1000; i+=2) if(!ifc(i))
		for(j = i*i, k = i<<1; j < 1000000; j += k) isc(j);
	primes[0] = 2, total = 1;
	for(i = 3; i < 1000000; i+=2) if(!ifc(i)) primes[total++] = i;
}

inline int nextint() {
	register int ret = 0;
	while(*ptr < '0') ptr++;
	do { ret = ret*10 + *ptr++ - '0'; } while(*ptr >= '0');
	return ret;
}

inline int gcd(int a, int b) {
	while(b) b^=a^=b^=a%=b;
	return a;
}

inline int cntdiv(int n) {
	int rt = (int)sqrt(n), i, ret = 1, cnt;
	for(i = 0; i < total && primes[i] <= rt; i++) {
		if(n % primes[i] == 0) {
			cnt = 0;
			while(n % primes[i] == 0) {
				n /= primes[i];
				cnt++;
			}
			ret *= ++cnt;
			rt = (int)sqrt(n);
		}
	}
	if(n > 1) ret <<= 1;
	return ret;
}

int main() {
	int test, a, b, g;
	fread(buff, 1, 14000000, stdin);
	sieve();
	test = nextint();
	while(test--) {
		a = nextint(), b = nextint();
		g = gcd(a, b);
		printf("%d\n", cntdiv(g));
	}
	return 0;
}
