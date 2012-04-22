/*
USER: zobayer
TASK: HORRIBLE
ALGO: segment tree
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
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T abs(T n) { return (n < 0 ? -n : n); }
template< class T > T max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const double BIG = 1e19;
const int INF = 0x7f7f7f7f;
const int MAX = 1 << 18;

i64 Tree[MAX][2]; // 0 sum, 1 add

void update(int Node, int i, int j, int x, int y, int v) {
	if(i == x && j == y) {
		Tree[Node][1] += v;
		Tree[Node][0] += (i64)v * (y-x+1);
		return;
	}
	int m, l, r;
	m = (i + j) >> 1; l = Node << 1; r = l + 1;
	if(y <= m) update(l, i, m, x, y, v);
	else if(x > m) update(r, m+1, j, x, y, v);
	else {
		update(l, i, m, x, m, v);
		update(r, m+1, j, m+1, y, v);
	}
	Tree[Node][0] = Tree[l][0] + Tree[r][0] + Tree[Node][1] * (j-i+1);
}

i64 query(int Node, int i, int j, int x, int y, i64 v) {
	if(i == x && j == y) return Tree[Node][0] + v * (y-x+1);
	int m, l, r;
	m = (i + j) >> 1; l = Node << 1; r = l + 1;
	if(y <= m) return query(l, i, m, x, y, v + Tree[Node][1]);
	else if(x > m) return query(r, m+1, j, x, y, v + Tree[Node][1]);
	else {
		i64 ret = 0;
		ret += query(l, i, m, x, m, v + Tree[Node][1]);
		ret += query(r, m+1, j, m+1, y, v + Tree[Node][1]);
		return ret;
	}
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, n, q, c, x, y, a;
	scanf("%d", &test);
	while(test--) {
		scanf("%d%d", &n, &q);
		CLR(Tree);
		while(q--) {
			scanf("%d%d%d", &c, &x, &y);
			if(c) printf("%lld\n", query(1, 0, n-1, x-1, y-1, 0));
			else {
				scanf("%d", &a);
				update(1, 0, n-1, x-1, y-1, a);
			}
		}
	}
	return 0;
}