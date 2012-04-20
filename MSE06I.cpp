/*
USER: zobayer
TASK: MSE06I
ALGO: mincost maxflow
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
#define OFF ios::sync_with_stdio(false)
#define ALL(c) c.begin(), c.end()
#define PB(x) push_back(x)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define REV(s, e) reverse(s, e);
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) c.size()
#define TBIT(c, n) !!(c & (1 << n))
#define SBIT(c, n) (c |= (1 << n))
#define CBIT(c, n) (c &= ~(1 << n))

template< class T > T abst(const T &n) { return (n < 0 ? -n : n); }
template< class T > T max2(const T &a, const T &b) { return (!(a < b) ? a : b); }
template< class T > T min2(const T &a, const T &b) { return (a < b ? a : b); }
template< class T > T max3(const T &a, const T &b, const T &c) { return max2(a, max2(b, c)); }
template< class T > T min3(const T &a, const T &b, const T &c) { return min2(a, min2(b, c)); }
template< class T > T gcd(const T a, const T b) { return (b ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(const T a, const T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T mod(const T &a, const T &b) { return (a < b ? a : a % b); }
template< class T > bool inrange(const T &a, const T &b, const T &c) { return a<=b && b<=c; }
template< class T > T sq(const T &x) { return x * x; }

typedef long long i64;
typedef unsigned long long u64;
typedef pair< int, int > pii;

const int INF = 0x7f7f7f7f, MAXN = 50, MAXE = 1000;
int src, snk, nNode, nEdge;
int fin[MAXN], pre[MAXN], dist[MAXN];
int cap[MAXE], cost[MAXE], next[MAXE], to[MAXE], from[MAXE];

inline void addEdge(int u, int v, int c, int e) {
	from[nEdge] = u, to[nEdge] = v, cap[nEdge] = c, cost[nEdge] = e, next[nEdge] = fin[u], fin[u] = nEdge++;
	from[nEdge] = v, to[nEdge] = u, cap[nEdge] = 0, cost[nEdge] =-e, next[nEdge] = fin[v], fin[v] = nEdge++;
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
	int n, m, i, u, v, w, flow, fcost, test = 1;
	while(scanf("%d%d", &n, &m)==2 && n+m) {
		SET(fin);
		nEdge = 0;
		for(i = 1; i < n - 1; i++) {
			addEdge(i*2-1, i*2, 1, 0);
		}
		addEdge(i*2-1, i*2, 2, 0);
		src = 0, snk = i*2, nNode = snk + 1;
		for(i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			addEdge(2*u, 2*v-1, 1, w);
		}
		flow = mcmf(fcost);
		printf("Instance #%d:  ", test++);
		if(flow == 2) printf("%d\n", fcost);
		else printf("Not possible\n");
	}
	return 0;
}
