/*
USER: zobayer
TASK: MTOTALF
ALGO: maxflow
*/

#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(c) c.begin(), c.end()
#define PB(x) push_back(x)
#define UB(s, e, x) upper_bound(s, e, x)
#define LB(s, e, x) lower_bound(s, e, x)
#define REV(s, e) reverse(s, e);
#define SZ(c) c.size()
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define i64 long long
#define ff first
#define ss second
#define DEBUG if(0)

const int MAXN = 60, MAXE = 1500, INF = 0x3f3f3f3f;

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

inline int conv(char c) {
	if(isupper(c)) return c - 'A' + 1;
	return c - 'a' + 27;
}

int main() {
	int e, u, v, c, i;
	char su[3], sv[3];
	scanf("%d", &e);
	init(1, 26, 52);
	for(i=0; i<e; i++) {
		scanf("%s%s%d", su, sv, &c);
		u = conv(su[0]); v = conv(sv[0]);
		if(u!=v) add(u, v, c);
	}
	printf("%lld\n", dinitz());
	return 0;
}
