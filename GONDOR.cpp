/*
USER: zobayer
TASK: GONDOR
ALGO: dijkstra
*/

#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
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

template< class T > T sq(T x) { return x * x; }
template< class T > T abs(T n) { return (n < 0 ? -n : n); }
template< class T > T max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T min(T a, T b) { return (a < b ? a : b); }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T mod(T a, T b) { return (a < b ? a : a % b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const int MAX = 128;
typedef pair< double, double > pdd;
typedef pair< double, int > pdi;

int G[MAX][MAX];
priority_queue< pdi, vector< pdi >, greater< pdi > > Q;
double d[MAX];
pdd city[MAX];
int lmt[MAX], n;
bool f[MAX];

inline double dist(pdd &a, pdd &b) {
	return hypot(a.ff-b.ff, a.ss-b.ss);
}

void dijkstra() {
	int u, v, i, cnt;
	double dd;
	Q.push(pdi(0.0, 1)); d[1] = 0.0;
	while(!Q.empty()) {
		u = Q.top().ss; Q.pop();
		if(f[u]) continue;
		cnt = lmt[u];
		for(i = 0; i < n-1 && cnt; i++) {
			v = G[u][i];
			if(!f[v]) {
				cnt--; dd = dist(city[u], city[v]);
				if(d[v] > d[u] + dd) {
					d[v] = d[u] + dd;
					Q.push(pdi(d[v], v));
				}
			}
		}
		f[u] = true;
	}
}

int main() {
	int i, j;
	double x, y;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		scanf("%lf%lf%d", &x, &y, &lmt[i]);
		city[i] = pdd(x, y);
		for(j = 0; j < n-1; j++) scanf("%d", &G[i][j]);
		d[i] = 1e15; f[i] = false;
	}
	dijkstra();
	for(i = 1; i <= n; i++) printf("%lf\n", d[i]);
	return 0;
}
