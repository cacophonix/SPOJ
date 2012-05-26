/*
USER: zobayer
TASK: HELPR2D2
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

const int MAX = 100000;

typedef struct { int max, min; } Node;

Node T[1 << 18];

void build(int node, int i, int j, int k) {
	if(i == j) {
		T[node].max = T[node].min = k;
		return;
	}
	int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1;
	build(lt, i, mid, k);
	build(rt, mid + 1, j, k);
	T[node].max = T[node].min = k;
}

int update(int node, int i, int j, int v) {
	if(v > T[node].max) return -1;
	if(i == j) {
		T[node].max -= v;
		T[node].min -= v;
		return i;
	}
	int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1, ret;
	ret = update(lt, i, mid, v);
	if(ret == -1) ret = update(rt, mid + 1, j, v);
	T[node].max = _max(T[lt].max, T[rt].max);
	T[node].min = _min(T[lt].min, T[rt].min);
	return ret;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, cs, i, r, v, ans, ret, j, w, n, k;
	char lead[16];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &k, &n);
		build(1, 0, MAX - 1, k);
		for(i = w = ans = 0; i < n; i += r) {
			scanf("%s", lead);
			if(lead[0] != 'b') {
				r = 1;
				v = atoi(lead);
			}
			else scanf("%d %d", &r, &v);
			for(j = 0; j < r; j++) {
				w += v;
				ret = update(1, 0, MAX - 1, v);
				ans = _max(ret, ans);
			}
		}
		printf("%d %d\n", ans + 1, k * ans - w + k);
	}
	return 0;
}