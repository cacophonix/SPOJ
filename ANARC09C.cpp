/*
USER: zobayer
TASK: ANARC09C
ALGO: math
*/

#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAX = 1024;
const int LMT = 32;
const int LEN = 180;
const int INF = 0x7f7f7f7f;

int flag[MAX>>6], primes[LEN], total;

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))
#define sq(x) ((x)*(x))

void sieve() {
	int i, j, k;
	for(i=3; i<LMT; i+=2)
		if(!ifc(i))
			for(j=i*i, k=i<<1; j<MAX; j+=k)
				isc(j);
	primes[0] = 2;
	for(i=3, j=1; i<MAX; i+=2)
		if(!ifc(i))
			primes[j++] = i;
	total = j;
}

void factor(int n, int *fact, int *cnt, int &len) {
	len = 0;
	for(int i=0; i<total && sq(primes[i])<=n; i++) {
		if(n % primes[i] == 0) {
			cnt[len] = 0;
			while(n % primes[i] == 0) {
				cnt[len]++;
				n /= primes[i];
			}
			fact[len++] = primes[i];
		}
	}
	if(n>1) {
		cnt[len] = 1;
		fact[len++] = n;
	}
}

int main() {
	int fa[40], fb[40], ca[40], cb[40];
	int a, b, la, lb, i, j, tot, mn, cs = 1;
	sieve();
	while(scanf("%d%d", &a, &b)==2 && (a+b)) {
		factor(a, fa, ca, la);
		factor(b, fb, cb, lb);
		fa[la] = fb[lb] = INF;
		for(i=j=tot=mn=0; i<la || j<lb; mn++) {
			if(i<la && j<lb && fa[i]==fb[j]) tot += abs(ca[i++]-cb[j++]);
			else if(i>=la || fa[i] > fb[j]) tot += cb[j++];
			else if(j>=lb || fa[i] < fb[j]) tot += ca[i++];
		}
		printf("%d. %d:%d\n", cs++, mn, tot);
	}
	return 0;
}
