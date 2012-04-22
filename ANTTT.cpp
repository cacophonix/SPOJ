/*
USER: zobayer
TASK: ANTTT
ALGO: geometry
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

#define ALL(c) c.begin(), c.end()
#define PB(x) push_back(x)
#define UB(s, e, x) upper_bound(s, e, x)
#define LB(s, e, x) lower_bound(s, e, x)
#define REV(s, e) reverse(s, e);
#define SZ(c) c.size()
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define i64 long long
#define ff first
#define ss second
#define DEBUG if(0)

const double EPS = 1e-9;
const double BIG = 1e15;
const int NIL = 0;
const int INF = 0x3f3f3f3f;

const int MAX = 1024;

struct Point { int x, y; };
struct Segment { Point a, b; };

Segment seg[MAX];
int root[MAX];

int find(int u) {
	if(u!=root[u]) root[u] = find(root[u]);
	return root[u];
}

inline void link(int u, int v) {
	root[u] = root[v];
}

inline int direction(Point &pi, Point &pj, Point &pk) {
	return (pk.x-pi.x)*(pj.y-pi.y)-(pj.x-pi.x)*(pk.y-pi.y);
}

inline bool onsegment(Point &pi, Point &pj, Point &pk) {
	return (inside(min(pi.x,pj.x),pk.x,max(pi.x,pj.x)) && inside(min(pi.y,pj.y),pk.y,max(pi.y,pj.y)));
}

inline bool intersect(Point &p1, Point &p2, Point &p3, Point &p4) {
	int d1, d2, d3, d4;
	d1 = direction(p3, p4, p1);
	d2 = direction(p3, p4, p2);
	d3 = direction(p1, p2, p3);
	d4 = direction(p1, p2, p4);
	if(((d1>0 && d2<0)||(d1<0 && d2>0)) && ((d3>0 && d4<0)||(d3<0 && d4>0))) return true;
	if(!d1 && onsegment(p3, p4, p1)) return true;
	if(!d2 && onsegment(p3, p4, p2)) return true;
	if(!d3 && onsegment(p1, p2, p3)) return true;
	if(!d4 && onsegment(p1, p2, p4)) return true;
	return false;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t, m, n, i, j, u, v;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &m);
		for(i = 1; i <= n; i++) {
			root[i] = i;
			scanf("%d%d%d%d", &seg[i].a.x, &seg[i].a.y, &seg[i].b.x, &seg[i].b.y);
		}
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) {
				u = find(i);
				v = find(j);
				if(u != v && intersect(seg[i].a, seg[i].b, seg[j].a, seg[j].b)) link(u, v);
			}
		}
		while(m--) {
			scanf("%d%d", &i, &j);
			u = find(i);
			v = find(j);
			if(u==v) printf("YES\n");
			else printf("NO\n");
		}
	}
	//system("pause");
	return 0;
}
