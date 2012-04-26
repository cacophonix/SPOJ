/*
USER: zobayer
TASK: GSS2
ALGO: segment tree
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <cassert>
#include <cctype>
#include <climits>
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

template< class T > inline T _abs(const T n) { return (n < 0 ? -n : n); }
template< class T > inline T _max(const T a, const T b) { return (!(a < b) ? a : b); }
template< class T > inline T _min(const T a, const T b) { return (a < b ? a : b); }
template< class T > inline void _setmax(T &a, const T b) { if(a < b) a = b; }
template< class T > inline void _setmin(T &a, const T b) { if(b < a) a = b; }
template< class T > inline T _sqr(const T x) { return x * x; }

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
const double PI = acos(-1.0);
const int INF = 0x7f7f7f7f;
const int TMAX = 1 << 18;
const int MAX = 100001;

typedef struct { int a, b, p; } Query;
typedef struct { i64 d, ed, em, mx; } Node;

int A[MAX], lastq[MAX], lastp[MAX<<1];
i64 res[MAX];
Query q[MAX];
Node T[TMAX];

void update(int node, int i, int j, int a, int b, int val) {
	if(a <= i && j <= b) T[node].d += val, _setmax(T[node].ed, T[node].d);
	else {
		int m = (i + j) >> 1, lt = node << 1, rt = lt | 1;
		_setmax(T[lt].ed, T[lt].d + T[node].ed);
		_setmax(T[rt].ed, T[rt].d + T[node].ed);
		T[lt].d += T[node].d, T[rt].d += T[node].d;
		T[node].ed = -INF, T[node].d = 0;
		if(a <= m) update(lt, i, m, a, b, val);
		if(m < b) update(rt, m+1, j, a, b, val);
		T[node].mx = _max(_max(T[lt].mx, T[lt].em + T[lt].ed), _max(T[rt].mx, T[rt].em + T[rt].ed));
		T[node].em = _max(T[lt].em + T[lt].d, T[rt].em + T[rt].d);
	}
}

i64 query(int node, int i, int j, int a, int b) {
	if(a <= i && j <= b) return _max(T[node].mx, T[node].em + T[node].ed);
	else {
		int m = (i + j) >> 1, lt = node << 1, rt = lt | 1;
		_setmax(T[lt].ed, T[lt].d + T[node].ed);
		_setmax(T[rt].ed, T[rt].d + T[node].ed);
		T[lt].d += T[node].d, T[rt].d += T[node].d;
		T[node].ed = -INF, T[node].d = 0;
		T[node].mx = _max(_max(T[lt].mx, T[lt].em + T[lt].ed), _max(T[rt].mx, T[rt].em + T[rt].ed));
		T[node].em = _max(T[lt].em + T[lt].d, T[rt].em + T[rt].d);
		return _max((a <= m ? query(lt, i, m, a, b) : -INF), (m < b ? query(rt, m+1, j, a, b) : -INF));
	}
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int n, i, j, m;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) scanf("%d", &A[i]);
	scanf("%d", &m);
	for(i = 1; i <= m; i++) {
		scanf("%d %d", &q[i].a, &q[i].b);
		q[i].p = lastq[q[i].b], lastq[q[i].b] = i;
	}
	for(i = 1; i <= n; i++) {
		update(1, 1, n, lastp[A[i]+100000] + 1, i, A[i]);
		lastp[A[i]+100000] = i;
		for(j = lastq[i]; j; j = q[j].p) res[j] = query(1, 1, n, q[j].a, q[j].b);
	}
	for(i = 1; i <= m; i++) printf("%lld\n", res[i]);
	return 0;
}