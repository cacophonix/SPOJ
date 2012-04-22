/*
USER: zobayer
TASK: MATCHING
ALGO: bipartite matching
*/

#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 100001
#define NIL 0
#define INF (1<<28)
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

vector< int > G[MAX];

int n, m, p, match[MAX], dist[MAX];
// G = NIL[0] U G1[G[1---n]] U G2[G[n+1---n+m]]

bool bfs() {
	int i, u, v, len;
	queue< int > Q;
	for(i=1; i<=n; i++) {
		if(match[i]==NIL) {
			dist[i] = 0;
			Q.push(i);
		}
		else dist[i] = INF;
	}
	dist[NIL] = INF;
	while(!Q.empty()) {
		u = Q.front(); Q.pop();
		if(u!=NIL) {
			len = G[u].size();
			for(i=0; i<len; i++) {
				v = G[u][i];
				if(dist[match[v]]==INF) {
					dist[match[v]] = dist[u] + 1;
					Q.push(match[v]);
				}
			}
		}
	}
	return (dist[NIL]!=INF);
}

bool dfs(int u) {
	int i, v, len;
	if(u!=NIL) {
		len = G[u].size();
		for(i=0; i<len; i++) {
			v = G[u][i];
			if(dist[match[v]]==dist[u]+1) {
				if(dfs(match[v])) {
					match[v] = u;
					match[u] = v;
					return true;
				}
			}
		}
		dist[u] = INF;
		return false;
	}
	return true;
}

int hopcroft_karp() {
	int matching = 0, i;
	while(bfs())
		for(i=1; i<=n; i++)
			if(match[i]==NIL && dfs(i))
				matching++;
	return matching;
}

int main() {
	int i, u, v;
	scanf("%d%d%d", &n, &m, &p);
	for(i=0; i<p; i++) {
		scanf("%d%d", &u, &v);
		// u in G1, v in G2
		v += n;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	printf("%d\n", hopcroft_karp());
	return 0;
}
