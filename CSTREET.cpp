/*
USER: zobayer
TASK: CSTREET
ALGO: kruskal
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define F first
#define S second
#define pii pair< int, int >
#define pip pair< int, pii >
#define MAX 10001
#define i64 long long

vector< pip > GRAPH;
int parent[MAX];

int findset(int x) {
	if(x!=parent[x]) parent[x] = findset(parent[x]);
	return parent[x];
}

int main()
{
	int i, u, v, w, N, E, t;
	i64 total, price;
	scanf("%d", &t);
	while(t--) {
		scanf("%lld%d%d", &price, &N, &E);
		for(i=1; i<=N; i++) parent[i] = i;
		GRAPH.resize(E);
		for(i=0; i<E; i++) {
			scanf("%d%d%d", &u, &v, &w);
			GRAPH[i] = pip(w, pii(u, v));
		}
		sort(GRAPH.begin(), GRAPH.end());
		for(total=i=0; i<E; i++) {
			u = findset(GRAPH[i].S.F);
			v = findset(GRAPH[i].S.S);
			if(u != v) {
				total += (i64)GRAPH[i].F;
				parent[u] = parent[v];
			}
		}
		printf("%lld\n", total*price);
	}
	return 0;
}
