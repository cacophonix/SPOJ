/*
USER: zobayer
TASK: FASTFLOW
ALGO: maxflow
*/

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <limits>
#include <numeric>
#include <utility>
#include <valarray>
using namespace std;

#define DEBUG if(0)
#define PAUSE system("pause")
#define ALL(c) c.begin(), c.end()
#define PB(x) push_back(x)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define BIG(p) memset(p, 0x3f, sizeof(p))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) c.size()

typedef long long i64;
typedef unsigned long long u64;
typedef pair< int, int > pii;

template< class T > T _abs(const T &n) { return (n < 0 ? -n : n); }
template< class T > T _max(const T &a, const T &b) { return (a > b ? a : b); }
template< class T > T _min(const T &a, const T &b) { return (a < b ? a : b); }
template< class T > T gcd(const T a, const T b) { return (b ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(const T a, const T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inrange(const T &a, const T &b, const T &c) { return a<=b && b<=c; }
template< class T > T sq(const T &x) { return x * x; }

const double EPS = 1e-10;
const int INF = 0x7fffffff;
const int MAXN = 5005, MAXE = 60006;

int src, snk, nNode, nEdge;
int Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];
int flow[MAXE], cap[MAXE], next[MAXE], to[MAXE];

inline void init(int _src, int _snk, int _n) {
	src = _src, snk = _snk, nNode = _n, nEdge = 0;
	SET(fin);
}

inline void add(int u, int v, int c) {
	to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, next[nEdge] = fin[u], fin[u] = nEdge++;
	to[nEdge] = u, cap[nEdge] = c, flow[nEdge] = 0, next[nEdge] = fin[v], fin[v] = nEdge++;
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

i64 dinitz() {
	i64 ret = 0;
	int df;
	while(bfs()) {
		for(int i=1; i<=nNode; i++) pro[i] = fin[i];
		while(true) {
			df = dfs(src, INF);
			if(df) ret += (i64)df;
			else break;
		}
	}
	return ret;
}

int main() {
	int n, e, u, v, c, i;
	scanf("%d%d", &n, &e);
	init(1, n, n);
	for(i=0; i<e; i++) {
		scanf("%d%d%d", &u, &v, &c);
		if(u!=v) add(u, v, c);
	}
	printf("%lld\n", dinitz());
	return 0;
}
