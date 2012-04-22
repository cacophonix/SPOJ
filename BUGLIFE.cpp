/*
USER: zobayer
TASK: BUGLIFE
ALGO: bi-coloring
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

const int INF = 0x3f3f3f3f;
const double EPS = 1e-10;
const int MAX = 2002;

vector< int > G[MAX];
int color[MAX];

bool bfs(int u) {
	int i, v, sz;
	queue< int > Q;
	Q.push(u);
	color[u] = 1;
	while(!Q.empty()) {
		u = Q.front(); Q.pop();
		sz = SZ(G[u]);
		for(i = 0; i < sz; i++) {
			v = G[u][i];
			if(color[v]==color[u]) return false;
			if(!color[v]) {
				color[v] = 3 - color[u];
				Q.push(v);
			}
		}
	}
	return true;
}

int main() {
	int t, x, N, E, u, v, i;
	scanf("%d", &t);
	for(x = 1; x <= t; x++) {
		scanf("%d%d", &N, &E);
		for(i = 1; i <= N; i++) {
			G[i].clear();
			color[i] = 0;
		}
		for(i = 0; i < E; i++) {
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		for(i = 1; i <= N; i++) {
			if(!color[i]) {
				if(bfs(i)) continue;
				else break;
			}
		}
		printf("Scenario #%d:\n", x);
		if(i>N) printf("No suspicious bugs found!\n");
		else printf("Suspicious bugs found!\n");
	}
	return 0;
}
