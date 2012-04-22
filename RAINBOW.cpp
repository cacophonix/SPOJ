/*
USER: zobayer
TASK: RAINBOW
ALGO: dynamic programming
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 1001;

int weight[MAX];
int root[MAX], rank[MAX];
int size[MAX], mass[MAX];
int dp[MAX][MAX];

int find(int u) {
	if(u != root[u]) root[u] = find(root[u]);
	return root[u];
}

void link(int u, int v) {
	u = find(u);
	v = find(v);
	if(rank[u] > rank[v]) root[v] = u;
	else root[u] = v;
	if(rank[u]==rank[v]) rank[v]++;
}

int solve(int sz, int w) {
	int i, j, ans;
	memset(dp, -1, sizeof dp);
	dp[0][0] = ans = 0;
	for(i = 1; i <= sz; i++) {
		for(j = 0; j <= w; j++) {
			dp[i][j] = dp[i-1][j];
			if(mass[i-1] <= j && dp[i-1][j-mass[i-1]] != -1) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-mass[i-1]] + size[i-1]);
			}
		}
	}
	for(i = 0; i <= w; i++) ans = max(ans, dp[sz][i]);
	return ans;
}

int main() {
	int n, e, c, i, per, res;
	while(scanf("%d%d", &n, &c)==2) {
		if(!n && !c) break;
		for(i = 1; i <= n; i++) {
			scanf("%d", &weight[i]);
			root[i] = i; rank[i] = 0;
			size[i] = mass[i] = 0;
		}
		for(i = 1; i <= n; i++) {
			scanf("%d", &e);
			while(e--) {
				scanf("%d", &per);
				link(i, per);
			}
		}
		for(i = 1; i <= n; i++) {
			per = find(i);
			size[per]++;
			mass[per] += weight[i];
		}
		e = 0;
		for(i = 1; i <= n; i++) {
			if(size[i]) {
				size[e] = size[i];
				mass[e++] = mass[i];
			}
		}
		res = solve(e, c);
		printf("%d\n", res);
	}
	return 0;
}
