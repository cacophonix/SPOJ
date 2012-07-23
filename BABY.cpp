/*
USER: zobayer
TASK: BABY
ALGO: mincost maxflow
*/

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }

#define ALL(p) p.begin(),p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

const int MAXN = 40;
const int MAXE = 580;

int src, snk, nNode, nEdge;
int fin[MAXN], pre[MAXN], dist[MAXN];
int cap[MAXE], cost[MAXE], next[MAXE], to[MAXE], from[MAXE];

inline void init(int _src, int _snk, int nodes) {
	SET(fin);
	nNode = nodes, nEdge = 0;
	src = _src, snk = _snk;
}

inline void addEdge(int u, int v, int _cap, int _cost) {
	from[nEdge] = u, to[nEdge] = v, cap[nEdge] = _cap, cost[nEdge] = _cost;
	next[nEdge] = fin[u], fin[u] = nEdge++;
	from[nEdge] = v, to[nEdge] = u, cap[nEdge] = 0, cost[nEdge] = -(_cost);
	next[nEdge] = fin[v], fin[v] = nEdge++;
}

bool bellman() {
	int iter, u, v, i;
	bool flag = true;
	MEM(dist, 0x7f);
	SET(pre);
	dist[src] = 0;
	for(iter = 1; iter < nNode && flag; iter++) {
		flag = false;
		for(u = 0; u < nNode; u++) {
			for(i = fin[u]; i >= 0; i = next[i]) {
				v = to[i];
				if(cap[i] && dist[v] > dist[u] + cost[i]) {
					dist[v] = dist[u] + cost[i];
					pre[v] = i;
					flag = true;
				}
			}
		}
	}
	return (dist[snk] < INF);
}

int mcmf(int &fcost) {
	int netflow, i, bot, u;
	netflow = fcost = 0;
	while(bellman()) {
		bot = INF;
		for(u = pre[snk]; u >= 0; u = pre[from[u]]) bot = min(bot, cap[u]);
		for(u = pre[snk]; u >= 0; u = pre[from[u]]) {
			cap[u] -= bot;
			cap[u^1] += bot;
			fcost += bot * cost[u];
		}
		netflow += bot;
	}
	return netflow;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int n, i, j, baby[16], given[16], fl, cs;
	while(scanf("%d", &n) == 1 && n) {
		for(i = 0; i < n; i++) scanf("%d", &baby[i]);
		for(i = 0; i < n; i++) scanf("%d", &given[i]);
		init(0, n + n + 1, n + n + 2);
		for(i = 0; i < n; i++) {
			addEdge(0, i + 1, 1, 0);
			addEdge(n + i + 1, n + n + 1, 1, 0);
		}
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				addEdge(i + 1, n + j + 1, INF, _abs(i-j) + _abs(baby[i] - given[j]));
			}
		}
		fl = mcmf(cs);
		printf("%d\n", cs);
	}
	return 0;
}
