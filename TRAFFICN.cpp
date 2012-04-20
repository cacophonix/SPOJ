/*
USER: zobayer
TASK: TRAFFICN
ALGO: dijkstra
*/

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#include <numeric>
#include <utility>
using namespace std;

#define DEBUG if(0)
#define PAUSE system("pause")
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

template< class T > T sq(T &x) { return x * x; }
template< class T > T abs(T &n) { return (n < 0 ? -n : n); }
template< class T > T max(T &a, T &b) { return (!(a < b) ? a : b); }
template< class T > T min(T &a, T &b) { return (a < b ? a : b); }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T mod(T &a, T &b) { return (a < b ? a : a % b); }
template< class T > bool inside(T &a, T &b, T &c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const int MAX = 10001;
typedef pair< int, int > pii;

vector< pii > G[MAX], R[MAX];
int fromS[MAX], toT[MAX];
bool flagG[MAX], flagR[MAX];

void dijkstra(int s, vector< pii > *graph, int *dist, bool *flag) {
	priority_queue< pii, vector< pii >, greater< pii > > Q;
	Q.push(pii(0,s));
	int u, v, w, i, sz;
	dist[s] = 0;
	while(!Q.empty()) {
		u = Q.top().second;
		Q.pop();
		if(flag[u]) continue;
		sz = graph[u].size();
		for(i = 0; i < sz; i++) {
			v = graph[u][i].second;
			w = graph[u][i].first;
			if(!flag[v] && dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				Q.push(pii(dist[v], v));
			}
		}
		flag[u] = true;
	}
}

int main() {
	int t, n, e, u, v, w, i, k, s, f, best;
	//READ("in.txt");
	//WRITE("out.txt");
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &e);
		for(i = 1; i <= n; i++) {
			G[i].clear();
			R[i].clear();
			fromS[i] = toT[i] = INF;
			flagG[i] = flagR[i] = false;
		}
		scanf("%d%d%d", &k, &s, &f);
		for(i = 0; i < e; i++) {
			scanf("%d%d%d", &u, &v, &w);
			G[u].PB(pii(w,v));
			R[v].PB(pii(w,u));
		}
		dijkstra(s, G, fromS, flagG);
		dijkstra(f, R, toT, flagR);
		//for(i = 1; i <= n; i++) printf("%d ", fromS[i]); printf("\n");
		//for(i = 1; i <= n; i++) printf("%d ", toT[i]); printf("\n");
		best = INF;
		while(k--) {
			scanf("%d%d%d", &u, &v, &w);
			best = min(best, min(fromS[f], min(fromS[u] + w + toT[v], fromS[v] + w + toT[u])));
		}
		if(best < INF) printf("%d\n", best);
		else printf("-1\n");
	}
	return 0;
}
