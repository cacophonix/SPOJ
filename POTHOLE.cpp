/*
USER: zobayer
TASK: POTHOLE
ALGO: maxflow
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
const int INF = 0x3f3f3f3f;
const int MAXN = 400;
const int MAXE = 40000;


int src, snk, nNode, nEdge;
int Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];
int flow[MAXE], cap[MAXE], next[MAXE], to[MAXE];

inline void init(int _src, int _snk, int _n) {
	src = _src, snk = _snk, nNode = _n, nEdge = 0;
	SET(fin);
}

inline void add(int u, int v, int _cap) {
	to[nEdge] = v, cap[nEdge] = _cap, flow[nEdge] = 0;
	next[nEdge] = fin[u], fin[u] = nEdge++;
	to[nEdge] = u, cap[nEdge] = 0, flow[nEdge] = 0;
	next[nEdge] = fin[v], fin[v] = nEdge++;
}

bool bfs() {
	int st, en, i, u, v;
	SET(dist);
	dist[src] = st = en = 0;
	Q[en++] = src;
	while(st < en) {
		u = Q[st++];
		for(i=fin[u]; i>=0; i=next[i]) {
			v = to[i];
			if(flow[i] < cap[i] && dist[v]==-1) {
				dist[v] = dist[u]+1;
				Q[en++] = v;
			}
		}
	}
	return dist[snk]!=-1;
}

int dfs(int u, int fl) {
	if(u==snk) return fl;
	for(int &e=pro[u], v, df; e>=0; e=next[e]) {
		v = to[e];
		if(flow[e] < cap[e] && dist[v]==dist[u]+1) {
			df = dfs(v, min(cap[e]-flow[e], fl));
			if(df>0) {
				flow[e] += df;
				flow[e^1] -= df;
				return df;
			}
		}
	}
	return 0;
}

int dinitz() {
	int ret = 0, df;
	while(bfs()) {
		for(int i=1; i<=nNode; i++) pro[i] = fin[i];
		while(true) {
			df = dfs(src, INF);
			if(df) ret += df;
			else break;
		}
	}
	return ret;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, u, v, i, n;
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		init(1, n, n);
		for(u = 1; u < n; u++) {
			scanf("%d", &i);
			while(i--) {
				scanf("%d", &v);
				add(u, v, (u == 1 || v == n) ? 1 : INF);
			}
		}
		printf("%d\n", dinitz());
	}
	return 0;
}


