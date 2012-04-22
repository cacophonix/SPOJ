/*
USER: zobayer
TASK: PFDEP
ALGO: topological sort
*/

#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

#define PB(x) push_back(x)
#define READ(f) freopen(f, "r", stdin)
#define SZ(c) c.size()

const int MAX = 111;
int M, N, indeg[MAX];
set< int > g[MAX], nextNode;
vector< int > order;

void topology() {
	int u, v;
	set< int >::iterator it;
	while(!nextNode.empty()) {
		u = *nextNode.begin();
		nextNode.erase(nextNode.begin());
		order.PB(u);
		for(it=g[u].begin(); it!=g[u].end(); it++) {
			v = *it;
			indeg[v]--;
			if(!indeg[v]) nextNode.insert(v);
		}
	}
}

int main() {
	int i, j, k, u, v;
	//READ("c:\\in2.txt");
	scanf("%d%d", &N, &M);
	for(i=0; i<M; i++) {
		scanf("%d%d", &u, &k);
		for(j=0; j<k; j++) {
			scanf("%d", &v);
			g[v].insert(u);
		}
		indeg[u] += k;
	}
	for(i=1; i<=N; i++)
		if(!indeg[i])
			nextNode.insert(i);
	topology();
	printf("%d", order[0]);
	for(i=1; i<N; i++) printf(" %d", order[i]);
	printf("\n");
	return 0;
}
