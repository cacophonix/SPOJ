/*
USER: zobayer
TASK: CT25C
ALGO: warshall
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

const double EPS = 1e-10;
const int INF = 0x3f3f3f3f;
const int MAX = 303;

int a[MAX][MAX];

void warshall(int n) {
	int i, j, k;
	for(k = 0; k < n; k++)
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}

void myfunc(int n, int u, int v) {
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			a[i][j] = a[j][i] = min(a[i][u] + a[u][v] + a[v][j], a[i][j]);
}

int main() {
	int i, j, u, v, w, tot;
	int n, q;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	warshall(n);
	scanf("%d", &q);
	while(q--) {
		scanf("%d%d%d", &u, &v, &w);
		u--; v--; tot = 0;
		a[v][u] = a[u][v] = min(a[u][v], w);
		myfunc(n, u, v);
		for(i = 1; i < n; i++)
			for(j = 0; j < i; j++)
				tot += a[i][j];
		printf("%d\n", tot);
	}
	return 0;
}
