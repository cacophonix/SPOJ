/*
USER: zobayer
TASK: RENT
ALGO: dynamic programming
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define _max(a,b) (a>b?a:b)

struct data {int st, en, pr;} d[10009];

static int dp[2000009];
static char buff[8000000], *ptr = buff;

inline bool comp(const data &a, const data &b) {
	return (a.st==b.st)? a.en < b.en : a.st < b.st;
}

inline int nextint() {
	int ret = 0;
	while(*ptr < '0') ptr++;
	do { ret = ret * 10 + *ptr++ - '0'; } while(*ptr >= '0');
	return ret;
}

int main() {
	int test, cs = 1, i, k, n, mx;
	fread(buff, 8000000, 1, stdin);
	test = nextint();
	while(test--) {
		memset(dp, 0, sizeof dp);
		n = nextint();
		mx = 0;
		for(i = 0; i < n; i++) {
			d[i].st = nextint(); d[i].en = nextint(); d[i].pr = nextint();
			d[i].en += d[i].st;
			mx = _max(mx, d[i].en);
		}
		sort(d, d + n, comp);
		for(i = k = 0; i < mx; i++) {
			while(k < n && d[k].st == i) {
				dp[d[k].en] = _max(dp[d[k].st] + d[k].pr, dp[d[k].en]);
				k++;
			}
			dp[i + 1] = _max(dp[i + 1], dp[i]);
		}
		printf("%d\n", dp[mx]); cs++;
	}
	return 0;
}
