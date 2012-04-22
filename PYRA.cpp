/*
USER: zobayer
TASK: PYRA
ALGO: depth first search
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

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

#define UB(s, e, x) upper_bound(s, e, x)
#define LB(s, e, x) lower_bound(s, e, x)
#define NPER(s, e) next_permutation(s, e)
#define PPER(s, e) prev_permutation(s, e)
#define REV(s, e) reverse(s, e);
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PAUSE system("pause")
#define shl(x, n) ((x)<<(n))
#define shr(x, n) ((x)>>(n))
#define all(c) c.begin(), c.end()
#define sz(c) c.size()
#define pb(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define fs "%lld"
#define debug if(0)

const double EPS = 1e-9;
const double BIG = 1e19;
const int INF = 0x7f7f7f7f;
const int MAX = 10000;

vector< int > G[MAX];
int d[MAX];
bool flag[MAX];

int dfs(int u) {
	int i, v;
	for(i = 0; i < sz(G[u]); i++) {
		v = G[u][i];
		if(!flag[v]) {
			flag[v] = 1;
			d[u] += 1 + dfs(v);
		}
	}
	return d[u] = d[u] + 1;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int t, n, i, u, v, total;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			G[i].clear();
			d[i] = 0;
			flag[i] = false;
		}
		for(i = 1; i < n; i++) {
			scanf("%d%d", &u, &v);
			G[u].pb(v);
			G[v].pb(u);
		}
		flag[0] = true; dfs(0); total = 0;
		for(i = 0; i < n; i++) total += d[i];
		printf("%d\n", total);
	}
	return 0;
}
