/*
USER: zobayer
TASK: DAGCNT2
ALGO: topological sort
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 20001;

vector< int > G[MAX], R[MAX], D[MAX];
int F[MAX][626], stck[MAX], top;
int cost[MAX], outdeg[MAX], res[MAX];
int fmap[MAX], rmap[MAX];
char visited[MAX];

void dfs(int u) {
	int i, j, v, sz = D[u].size();
	visited[u] = 1;
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
		}
		memset(outdeg, 0, sizeof(int) * (n + 1));
		memset(res, 0, sizeof(int) * (n + 1));
		for(i = 0; i < e; i++) {
			scanf("%d %d", &u, &v);
			G[u].push_back(v);
			R[v].push_back(u);
			outdeg[u]++;
		}
		for(top = 0, i = 1; i <= n; i++) {
			if(!outdeg[i]) stck[top++] = i;
		}
		i = 1;
		while(top > 0) {
			u = stck[--top];
			fmap[u] = i; rmap[i] = u; i++;
			for(e = 0; e < R[u].size(); e++) {
				v = R[u][e];
				outdeg[v]--;
				if(!outdeg[v]) stck[top++] = v;
			}
		}
		for(u = 1; u <= n; u++) {
			for(e = 0; e < G[u].size(); e++) {
				v = G[u][e];
				D[fmap[u]].push_back(fmap[v]);
			}
		}
		for(u = 1; u <= n; u++) {
			sort(D[u].begin(), D[u].end(), greater< int >());
			memset(F[u], 0, sizeof(int) * ((u >> 5)+1));
		}
		memset(visited, 0, sizeof(char) * (n + 1));
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