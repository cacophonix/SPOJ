/*
USER: zobayer
TASK: BIRD
ALGO: ad-hoc
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
#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PAUSE system("pause")
#define SL(x, n) ((x)<<(n))
#define SR(x, n) ((x)>>(n))
#define ALL(c) c.begin(), c.end()
#define SIZE(c) c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 __int64
#define ld long double
#define pii pair< int, int >
#define debug if(0)

const double EPS = 1e-9;
const double BIG = 1e19;
const int INF = 0x7f7f7f7f;
const int MAX = 1000;

pii A[MAX], B[MAX], X;
int n, na, nb;

bool ok(int x1, int y1, int x2, int y2, int x, int y) {
	setmin(x1, x);
	setmin(y1, y);
	setmax(x2, x);
	setmax(y2, y);
	for(int i = 0; i < nb; i++)
		if(inside(x1, B[i].ff, x2) && inside(y1, B[i].ss, y2))
			return false;
	return true;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, cs = 1;
	int i, j, x, y, m;
	int x1, y1, x2, y2;
	bool f1, f2;
	char type[16];
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		na = nb = 0;
		for(i = 0; i < n; i++) {
			scanf("%d%d %[^\n]", &x, &y, type);
			if(type[0]=='B') A[na++] = MP(x, y);
			else B[nb++] = MP(x, y);
		}
		printf("Case #%d:\n", cs++);
		scanf("%d", &m);
		if(!na) {
			for(i = 0; i < m; i++) {
				scanf("%d%d", &x, &y);
				X = MP(x, y);
				for(j = 0; j < nb; j++)
					if(B[j]==X)
						break;
				if(j==nb) puts("UNKNOWN");
				else puts("NOT BIRD");
			}
		}
		else {
			x1 = x2 = A[0].ff, y1 = y2 = A[0].ss;
			for(i = 1; i < na; i++) {
				setmin(x1, A[i].ff);
				setmax(x2, A[i].ff);
				setmin(y1, A[i].ss);
				setmax(y2, A[i].ss);
			}
			for(i = 0; i < m; i++) {
				scanf("%d%d", &x, &y);
				f1 = inside(x1, x, x2) && inside(y1, y, y2);
				f2 = ok(x1, y1, x2, y2, x, y);
				if(f1 && f2) puts("BIRD");
				else if(!f1 && !f2) puts("NOT BIRD");
				else puts("UNKNOWN");
			}
		}
	}
	return 0;
}
