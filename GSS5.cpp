/*
USER: zobayer
TASK: GSS5
ALGO: segment tree
*/

#define _CRT_SECURE_NO_WARNINGS 1
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

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }

#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const int MAX = 1 << 14;

typedef struct { int sum, suf, pre, max; } Node;

int a[MAX];
Node T[MAX << 1];

void init(int x, int i, int j) {
	if(i == j) {
		T[x].sum = T[x].pre = T[x].suf = T[x].max = a[i];
		return;
	}
	int m = (i + j) >> 1, lt = x << 1, rt = lt | 1;
	init(lt, i, m);
	init(rt, m+1, j);
	T[x].sum = T[lt].sum + T[rt].sum;
	T[x].pre = _max(T[lt].pre, T[lt].sum + T[rt].pre);
	T[x].suf = _max(T[lt].suf + T[rt].sum, T[rt].suf);
	T[x].max = _max(T[lt].suf + T[rt].pre, _max(T[lt].max, T[rt].max));
}

Node query(int x, int i, int j, int p, int q) {
	if(p > q) return T[0];
	if(i == p && j == q) return T[x];
	int m = (i + j) >> 1, lt = x << 1, rt = lt | 1;
	if(q <= m) return query(lt, i, m, p, q);
	else if(p > m) return query(rt, m+1, j, p, q);
	else {
		Node retl, retr, ret;
		retl = query(lt, i, m, p, m);
		retr = query(rt, m+1, j, m+1, q);
		ret.sum = retl.sum + retr.sum;
		ret.pre = _max(retl.pre, retl.sum + retr.pre);
		ret.suf = _max(retl.suf + retr.sum, retr.suf);
		ret.max = _max(retl.suf + retr.pre, _max(retl.max, retr.max));
		return ret;
	}
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, cs, n, q, i, x1, y1, x2, y2, res;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) scanf("%d", a + i);
		init(1, 0, n-1);
		scanf("%d", &q);
		while(q--) {
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			x1--, y1--, x2--, y2--;
			if(y1 < x2) {
				res = query(1, 0, n-1, x1, y1).suf;
				res += query(1, 0, n-1, y1+1, x2-1).sum;
				res += query(1, 0, n-1, x2, y2).pre;
			}
			else {
				res = query(1, 0, n-1, x2, y1).max;
				res = _max(res, _max(
					query(1, 0, n-1, x1, x2-1).suf + query(1, 0, n-1, x2, y2).pre,
					query(1, 0, n-1, x1, y1).suf + query(1, 0, n-1, y1+1, y2).pre
				));
			}
			printf("%d\n", res);
		}
	}
	return 0;
}