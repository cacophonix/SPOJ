/*
USER: zobayer
TASK: NDIVPHI2
ALGO: math
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int flag[61504>>6], primes[6186], total;

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

bool lt(char *r, int rl, char *s, int sl) {
	if(rl != sl) return rl < sl;
	for(int i = rl-1, j = sl-1; i >= 0; i--, j--) {
		if(r[i] != s[j]) return r[i] < s[j];
	}
	return false;
}

typedef struct {
	int len;
	char *s;
} Data;

Data d[74];
int nd;

void precalc() {
	char R[25009] = "1";
	int slen = 1, rlen, i;
	d[0].len = 1;
	d[0].s = "1";
	nd = 1;
	for(i = 0; i < total && nd < 74; i++) {
		slen = multi(primes[i], R, slen, R, rlen);
		if((i+1)%80 == 0) {
			d[nd].s = new char[slen+1];
			strcpy(d[nd].s, R);
			d[nd++].len = slen;
		}
	}
}

int upperbound(char *num, int len, int st, int en) {
	int cnt = en - st, stp, idx;
	while(cnt > 0) {
		stp = cnt >> 1, idx = st + stp;
		if(!lt(num, len, d[idx].s, d[idx].len)) st = ++idx, cnt -= stp+1;
		else cnt = stp;
	}
	return st;
}

int main() {
	int test, i, len, pos, slen, rlen;
	char N[25009], R[2][25009];
	sieve();
	precalc();
	test=atoi(gets(N));
	while(test--) {
		gets(N);
		len = strlen(N);
		reverse(N, N+len);
		pos = upperbound(N, len, 0, nd) - 1;
		strcpy(R[0], d[pos].s);
		slen = d[pos].len;
		for(i = pos*80; i < total; i++) {
			multi(primes[i], R[i&1], slen, R[(i+1)&1], rlen);
			if(lt(N, len, R[(i+1)&1], rlen)) break;
			slen = rlen;
		}
		reverse(R[i&1], R[i&1]+slen);
		puts(R[i&1]);
	}
	return 0;
}