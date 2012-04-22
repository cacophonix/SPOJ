/*
USER: zobayer
TASK: TWENDS
ALGO: dynamic programming
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1024;
int a[MAX], dp[2][MAX][MAX], s[MAX];

int solve(int P, int L, int R) {
	if(L==R) return a[L];
	int &ret = dp[P][L][R], now;
	if(ret!=-1) return ret;
	now = s[R] - (L==0? 0 : s[L-1]);
	ret = 0;
	if(P) {
		if(a[L] >= a[R]) ret = now - solve(P^1, L+1, R);
		else ret = now - solve(P^1, L, R-1);
	}
	else ret = now - min(solve(P^1, L+1, R), solve(P^1, L, R-1));
	return ret;
}

int main() {
	int n, i, ans, test = 1;
	while(scanf("%d", &n)==1 && n) {
		for(i=0; i<n; i++) scanf("%d", &a[i]);
		for(i=1,s[0]=a[0]; i<n; i++) s[i] = s[i-1] + a[i];
		memset(dp, -1, sizeof dp);
		ans = solve(0, 0, n-1);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", test++, 2*ans - s[n-1]);
	}
	return 0;
}
