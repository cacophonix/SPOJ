/*
USER: zobayer
TASK: EN
ALGO: breadth first search
*/

#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 30012;

vector< int > G[MAX];
int p[MAX], res, Q[MAX];
bool visited[MAX], found;

bool bfs(int s, int t) {
	int u, v, i, sz, qh, qt;
	if(visited[t]) return false;
	qh = qt = 0;
	Q[qt++] = s;
	visited[s] = 1;
	p[s] = -1;
	while(qh < qt) {
		u = Q[qh++];
		sz = G[u].size();
		for(i=0; i<sz; i++) {
			v = G[u][i];
			if(!visited[v]) {
				p[v] = u;
				visited[v] = 1;
				if(v==t) return true;
				Q[qt++] = v;
			}
		}
	}
	return false;
}

void walk(int u, int s, int t) {
	if(u==s) return;
	walk(p[u], s, t);
	for(int i=s; i<=t; i++) visited[i] = 0;
	visited[u] = 1;
	if(!found) {
		found = !bfs(s, t);
		res = u;
	}
}

int main() {
	int t, n, e, i, u, v;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &e);
		for(i=0; i<n; i++) G[i].clear();
		for(i=0; i<e; i++) {
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
		}
		for(i=1; i<=n; i++) visited[i] = 0;
		found = 0;
		bfs(1, n);
		walk(n, 1, n);
		printf("%d\n", res);
	}
}
