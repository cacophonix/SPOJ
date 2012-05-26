/*
USER: zobayer
TASK: ANDROUND
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

const int MAX = 1 << 15;

int T[MAX << 1], a[MAX];

void build(int node, int i, int j) {
	if(i == j) {
		T[node] = a[i];
		return;
	}
	int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1;
	build(lt, i, mid);
	build(rt, mid + 1, j);
	T[node] = T[lt] & T[rt];
}

int query(int node, int i, int j, int s, int e) {
	if(i == s && j == e) return T[node];
	int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1;
	if(e <= mid) return query(lt, i, mid, s, e);
	else if(s > mid) return query(rt, mid + 1, j, s, e);
	else return query(lt, i, mid, s, mid) & query(rt, mid + 1, j, mid + 1, e);
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, cs, i, n, k, s, e, res;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &k);
		k = _min(k, n-1);
		for(i = 0; i < n; i++) scanf("%d", &a[i]);
		build(1, 0, n-1);
		for(i = 0; i < n; i++) {
			s = (i - k + n) % n;
			e = (i + k) % n;
			res = -1;
			if(s < i) res &= query(1, 0, n - 1, s, i);
			else res &= query(1, 0, n - 1, 0, i) & query(1, 0, n - 1, s, n - 1);
			if(e > i) res &= query(1, 0, n - 1, i, e);
			else res &= query(1, 0, n - 1, i, n - 1) & query(1, 0, n - 1, 0, e);
			if(i) printf(" "); printf("%d", res);
		}
		printf("\n");
	}
	return 0;
}
