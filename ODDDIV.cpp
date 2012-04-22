/*
USER: zobayer
TASK: ODDDIV
ALGO: binary search
*/

#include <cstdio>

using namespace std;
typedef long long i64;

const int MAX = 100000;
int d[MAX+10], cnt[1500], start[1500];
i64 ans[MAX+10];

int divn(int n) {
	int res = 1, i, c;
	for(i=2; i*i<=n; i++) {
		if(n % i == 0) {
			c = 0;
			while(n % i == 0) {
				n /= i;
				c++;
			}
			res *= (2*c+1);
		}
	}
	if(n>1) res *= 3;
	return res;
}

void calc() {
	int n, k, i;
	for(n=2; n<100000; n++) {
		d[n] = divn(n);
		cnt[d[n]]++;
	}
	for(k=1, i=0; k<=1323; k+=2) {
		start[k] = i;
		if(!cnt[k]) continue;
		for(n=2; n<100000; n++)
			if(d[n]==k)
				ans[i++] = (i64)n*(i64)n;
	}
	start[k] = i;
}

int lower_bound(int k, i64 n) {
	int lo, hi, mi;
	if(!cnt[k] || ans[start[k]]>=n) return 0;
	lo = start[k]; hi = start[k+2];
	while(lo < hi-1) {
		mi = (lo + hi)/2;
		if(ans[mi] >= n) hi = mi;
		else lo = mi;
	}
	return lo - start[k] + 1;
}

int upper_bound(int k, i64 n) {
	int lo, hi, mi;
	if(!cnt[k] || ans[start[k]]>n) return 0;
	lo = start[k]; hi = start[k+2];
	while(lo < hi-1) {
		mi = (lo + hi)/2;
		if(ans[mi] > n) hi = mi;
		else lo = mi;
	}
	return lo - start[k] + 1;
}

int main() {
	int test, k, i;
	i64 from, to;
	calc();
	for(scanf("%d", &test); test; test--) {
		scanf("%d%lld%lld", &k, &from, &to);
		if(k>1323 || !cnt[k]) {
			printf("0\n");
			continue;
		}
		printf("%d\n", upper_bound(k, to) - lower_bound(k, from));
	}
	return 0;
}
