/*
USER: zobayer
TASK: PTIME
ALGO: math, prime factorization
*/

#include <cstdio>

const int MAX = 10000;
const int LMT = 100;

int flag[157], cnt, primes[1230];

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
	int i, j, k;
	primes[0] = 2, cnt = 1;
	for(i = 3; i < LMT; i+=2) if(!ifc(i)) for(j = i*i, k = i << 1; j < MAX; j += k) isc(j);
	for(i = 3; i < MAX; i += 2) if(!ifc(i)) primes[cnt++] = i;
}

int main() {
	int n, i, x, pwr, flg;
	sieve();
	while(scanf("%d", &n) == 1) {
		for(i = flg = 0; i < cnt && primes[i] <= n; i++) {
			x = n, pwr = 0;
			while(x > 0) {
				pwr += x / primes[i];
				x /= primes[i];
			}
			if(pwr > 0) {
				if(flg) printf(" * ");
				printf("%d^%d", primes[i], pwr);
				flg++;
			}
		}
		printf("\n");
	}
	return 0;
}
