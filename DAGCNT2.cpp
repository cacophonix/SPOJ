/*
USER: zobayer
TASK: DAGCNT2
ALGO: topological sort
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 20001;

vector< int > G[MAX], R[MAX], D[MAX], F[MAX];
int cost[MAX], outdeg[MAX], res[MAX];
int fmap[MAX], rmap[MAX];
bool visited[MAX];

void dfs(int u) {
	int i, j, v, sz = D[u].size();
	visited[u] = true;
	F[u][u >> 5] |= (1 << (u & 31));
	for(i = 0; i < sz; i++) {
		v = D[u][i];
		if(!(F[u][v>>5] & (1 << (v & 31)))) {
			if(!visited[v]) dfs(v);
			for(j = 0; j <= (v>>5); j++) {
				F[u][j] |= F[v][j];
			}
		}
	}
	for(j = 0; j <= (u >> 5); j++) {
		for(i = 0; i < 32; i++) {
			if(F[u][j] & (1 << i)) {
				res[rmap[u]] += cost[rmap[(j << 5) + i]];
			}
		}
	}
}

int main() {
	int test, n, e, i, u, v;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d", &n, &e);
		for(i = 1; i <= n; i++) {
			scanf("%d", &cost[i]);
			G[i].clear();
			R[i].clear();
			D[i].clear();
			F[i].clear();
		}
		memset(outdeg, 0, sizeof outdeg);
		memset(res, 0, sizeof res);
		for(i = 0; i < e; i++) {
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			R[v].push_back(u);
			outdeg[u]++;
		}
		stack< int > S;
		for(i = 1; i <= n; i++) {
			if(!outdeg[i]) S.push(i);
		}
		i = 1;
		while(!S.empty()) {
			u = S.top(); S.pop();
			fmap[u] = i; rmap[i] = u; i++;
			for(e = 0; e < R[u].size(); e++) {
				v = R[u][e];
				outdeg[v]--;
				if(!outdeg[v]) S.push(v);
			}
		}
		//for(i = 1; i <= n; i++) printf("%d %d\n", i, fmap[i]);
		for(u = 1; u <= n; u++) {
			for(e = 0; e < G[u].size(); e++) {
				v = G[u][e];
				D[fmap[u]].push_back(fmap[v]);
			}
		}
		for(u = 1; u <= n; u++) {
			sort(D[u].begin(), D[u].end(), greater< int >());
			F[u] = vector< int >((u >> 5) + 1, 0);
		}
		memset(visited, 0, sizeof visited);
		for(u = n; u > 0; u--) {
			if(!visited[u]) {
				dfs(u);
			}
		}
		printf("%d", res[1]);
		for(i = 2; i <= n; i++) printf(" %d", res[i]);
		printf("\n");
	}
	return 0;
}