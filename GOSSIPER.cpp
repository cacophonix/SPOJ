/*
USER: zobayer
TASK: GOSSIPER
ALGO: ad-hoc
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
#define BIG(p) memset(p, 0x3f, sizeof(p))
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
typedef pair< string, int > psi;

const int MAX = 2112;
int graph[MAX][70];
map< string, int > M;
char A[101], B[101];

#define setb(u,v) (graph[u][v>>5]|=(1<<(v&31)))
#define chkb(u,v) (graph[u][v>>5]&(1<<(v&31)))

int main() {
	int i, j, k, n, e, u, v;
	while(scanf("%d%d", &n, &e)==2 && (n+e)) {
		M.clear();
		for(i=0; i<n; i++) {
			CLR(graph[i]);
			setb(i,i);
			scanf("%s", A);
			M.insert(psi(A,i));
		}
		for(i=0; i<e; i++) {
			scanf("%s%s", A, B);
			u = M[A], v = M[B];
			setb(u,v); setb(v,u);
			for(j=0, k=n>>5; j<=k; j++) {
				graph[u][j] |= graph[v][j];
				graph[v][j] |= graph[u][j];
			}
		}
		for(i=0; i<n; i++) {
			for(j=0; j<n; j++)
				if(!chkb(i,j))
					break;
			if(j<n) break;
		}
		if(i<n) puts("NO");
		else puts("YES");
	}
	return 0;
}
