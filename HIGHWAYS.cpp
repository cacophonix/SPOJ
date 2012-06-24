/*
USER: zobayer
TASK: HIGHWAYS
ALGO: dijkstra
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <queue>
#include <ios>
#include <vector>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DEBUG if(0)
#define ALL(p) p.begin(), p.end()
#define pii pair< int, int >
#define MAX 100010
#define INF 2147483647
#define pb(x) push_back(x)

vector< pii > G[MAX];
int d[MAX], f[MAX];

int process(int n, int e, int start, int end) {
	int u, v, w, we, wn, size;
	
	REP(i,n+1) {
		G[i].clear();
		d[i] = INF;
		f[i] = 0;
	}

	REP(i,e) {
		scanf("%d %d %d", &u, &v, &w);
		G[u].pb(pii(w,v));
		G[v].pb(pii(w,u));
	}

	d[start] = 0;
	priority_queue< pii, vector< pii >, greater< pii > > Q;
	Q.push(pii(0, start));

	while(!Q.empty()) {
		u = Q.top().second;
		wn = Q.top().first;
		DEBUG printf("%d %d\n", u, wn);
		Q.pop();
		size = G[u].size();
		REP(i,size) {
			v = G[u][i].second;
			we = G[u][i].first;
			if(!f[v] && wn + we <= d[v]) {
				d[v] = wn+we;
				Q.push(pii(d[v], v));
			}
		}
		f[u] = 1;
		if(u==end) break;
	}

	return d[end];
}

int main() {
	int t, n, e, start, end, dist;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d %d", &n, &e, &start, &end);
		dist = process(n, e, start, end);
		if(dist==INF) printf("NONE\n");
		else printf("%d\n", dist);
	}
	return 0;
}
