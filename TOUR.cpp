/*
USER: zobayer
TASK: TOUR
ALGO: strongly connected component
*/

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define SZ(p) p.size()
#define PB(x) push_back(x)
#define pii pair< int, int >
#define ff first
#define ss second

const int MAX = 1024;
int Stack[MAX], top;
int Index[MAX], Lowlink[MAX], Onstack[MAX];
int Component[MAX], Indeg[MAX];
int idx, components;
vector< int > G[MAX];
vector< pii > edges;

void tarjan(int u) {
	int v, i;
	Index[u] = Lowlink[u] = idx++;
	Stack[top++] = u;
	Onstack[u] = 1;
	for(i = 0; i < SZ(G[u]); i++) {
		v = G[u][i];
		if(Index[v]==-1) {
			tarjan(v);
			Lowlink[u] = min(Lowlink[u], Lowlink[v]);
		}
		else if(Onstack[v]) Lowlink[u] = min(Lowlink[u], Index[v]);
	}
	if(Lowlink[u] == Index[u]) {
		components++;
		do {
			v = Stack[--top];
			Onstack[v] = 0;
			Component[v] = components;
		} while(u != v);
	}
}

void findSCC(int n) {
	components = top = idx = 0;
	SET(Index); CLR(Onstack); MEM(Lowlink, 0x7f);
	for(int i = 1; i <= n; i++) if(Index[i]==-1) tarjan(i);
}

int findWinners(int n) {
	int i, lead, cid;
	CLR(Indeg);
	for(i = 0; i < SZ(edges); i++)
		if(Component[edges[i].ff] != Component[edges[i].ss])
			Indeg[Component[edges[i].ss]]++;
	for(i = 1, lead = cid = 0; i <= components; i++) {
		if(!Indeg[i]) {
			lead++;
			if(lead > 1) return 0;
			cid = i;
		}
	}
	if(lead != 1) return 0;
	for(i = 1, lead = 0; i <= n; i++) if(Component[i]==cid) lead++;
	return lead;
}

int main() {
	int t, n, e, i, j;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i = 1; i <= n; i++) G[i].clear();
		edges.clear();
		for(i = 1; i <= n; i++) {
			scanf("%d", &e);
			while(e--) {
				scanf("%d", &j);
				G[j].PB(i);
				edges.PB(pii(j, i));
			}
		}
		findSCC(n);
		printf("%d\n", findWinners(n));
	}
	return 0;
}
