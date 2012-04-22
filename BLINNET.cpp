/*
USER: zobayer
TASK: BLINNET
ALGO: kruskal
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair< int, int > pii;
typedef pair< int, pii > edge;
const int MAX = 10001;

vector< edge > edges;
int parent[MAX];

int find(int u) {
	if(u != parent[u]) parent[u] = find(parent[u]);
	return parent[u];
}

int main() {
	int t, i, n, e, u, v, w, cost, sz;
	char dump[20];
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	while(t--) {
		edges.clear();
		scanf("%d", &n);
		for(i = 1; i <= n; i++) {
			parent[i] = i;
			scanf("%s%d", dump, &e);
			while(e--) {
				scanf("%d%d", &v, &w);
				if(v > i) edges.push_back(edge(w, pii(i, v)));
			}
		}
		sort(edges.begin(), edges.end());
		sz = edges.size();
		for(cost=i=0; i < sz; i++) {
			u = find(edges[i].second.first);
			v = find(edges[i].second.second);
			w = edges[i].first;
			if(u != v) {
				cost += w;
				parent[u] = parent[v];
			}
		}
		printf("%d\n", cost);
	}
	return 0;
}
