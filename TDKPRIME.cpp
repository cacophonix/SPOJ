/*
USER: zobayer
TASK: TDKPRIME
ALGO: math
*/

#include <stdio.h>
#include <stdlib.h>

const int MAX = 86044176;
const int LMT = 9267;
const int LEN = 5000000;

int flag[MAX>>6], primes[LEN+5];

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
	register int i, j, k;
	for(i = 3; i < LMT; i+=2)
		if(!ifc(i))
			for(j=i*i, k=i<<1; j < MAX; j+=k)
				isc(j);
	primes[1] = 2;
	for(i=3, j=2; i < MAX && j <= LEN; i+=2)
		if(!ifc(i))
			primes[j++] = i;
}

int main() {
	char buff[11];
	register int q = atoi(fgets(buff, 11, stdin));
	sieve();
	while(q--) printf("%d\n", primes[atoi(fgets(buff, 11, stdin))]);
	return 0;
}
