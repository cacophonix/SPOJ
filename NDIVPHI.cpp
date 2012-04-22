/*
USER: zobayer
TASK: NDIVPHI
ALGO: math
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int flag[61504>>6], primes[6186], total;

char N[32000], R[32000], S[32000];
int L;

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
	int i, j, k;
	for(i = 3; i < 248; i+=2)
		if(!ifc(i))
			for(j = i*i, k=i<<1; j<61504; j+=k)
				isc(j);
	primes[0] = 2, total = 1;
	for(i = 3; i < 61504; i+=2) if(!ifc(i)) primes[total++] = i;
}

int multi(int n, char *num, int slen, char *res, int &rlen) {
	int carry = 0, a, i;
	rlen = 0;
	for(i = 0; i < slen || carry; i++) {
		a = n * ((i < slen)? num[i]-'0' : 0) + carry;
		res[rlen++] = a % 10 + '0';
		carry = a / 10;
	}
	res[rlen] = 0;
	return rlen;
}

bool gt(char *r, int rl, char *s, int sl) {
	if(rl != sl) return rl > sl;
	for(int i = rl-1, j = sl-1; i >= 0; i--, j--) {
		if(r[i] != s[j]) return r[i] > s[j];
	}
	return false;
}

int main() {
	sieve();
	int slen, rlen, i, test = 20, save;
	while(test--) {
		gets(N);
		if(!strcmp("1", N)) {
			puts("1");
			continue;
		}
		reverse(N, N + (L=strlen(N)));
		R[0] = '1';
		slen = 1;
		for(i = 0; i < total; i++) {
			slen = multi(primes[i], R, slen, R, rlen);
			if(gt(R, rlen, N, L)) break;
			else {
				strcpy(S, R);
				save = rlen;
			}
		}
		reverse(S, S + save);
		puts(S);
	}
	return 0;
}