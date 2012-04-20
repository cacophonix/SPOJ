/*
USER: zobayer
TASK: DISUBSTR
ALGO: suffix array
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct entry { int nr[2], p; };
const int MAXN = 1024, MAXLG = 12;

entry L[MAXN];
int P[MAXLG][MAXN], N, stp, cnt, S[MAXN];
char A[MAXN];

int cmp(struct entry a, struct entry b) {
	return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}

int lcp(int x, int y) {
	int k, ret = 0;
	if(x < 0 || y < 0) return 0;
	if(x == y) return N - x;
	for(k = stp - 1; k >= 0 && x < N && y < N; k--)
		if(P[k][x] == P[k][y])
			x += 1 << k, y += 1 << k, ret += 1 << k;
	return ret;
}

int main() {
	int i, t, tot;
	char mn;
	t = atoi(gets(A));
	while(t--) {
		gets(A);
		mn = 256;
		for(i = 0; A[i]; i++) mn = min(mn, A[i]);
		for(i = 0; A[i]; i++) P[0][i] = A[i] - mn;
		N = i;
		for(stp = 1, cnt = 1; (cnt >> 1) < N; stp++, cnt <<= 1) {
			for(i = 0; i < N; i++) {
				L[i].nr[0] = P[stp - 1][i];
				L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
				L[i].p = i;
			}
			sort(L, L + N, cmp);
			for(i = 0; i < N; i++) {
				P[stp][L[i].p] = (i>0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1]==L[i-1].nr[1])? P[stp][L[i-1].p] : i;
			}
		}
		for(i = 0; i < N; i++) S[P[stp-1][i]] = i;
		tot = N - L[0].p;
		for(i = 1; i < N; i++) {
			tot += N - L[i].p - lcp(S[i-1], S[i]);
		}
		printf("%d\n", tot);
	}
    return 0;
}
