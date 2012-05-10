/*
USER: zobayer
TASK: CHAIN
ALGO: disjoint set
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
const int MAX = 50001;

int root[MAX], d[MAX];

int find(int u) {
	if(u == root[u]) return u;
	int tmp = root[u];
	root[u] = find(root[u]);
	d[u] = d[tmp] + d[u];
	return root[u];
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, cs, n, k, i, t, x, y, px, py, ans, tmp;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &k);
		for(i = 1; i <= n; i++) {
			root[i] = i;
			d[i] = 0;
		}
		ans = 0;
		while(k--) {
			scanf("%d %d %d", &t, &x, &y);
			if(x > n || y > n) { ans++; continue; }
			px = find(x);
			py = find(y);
			t--;
			if(px == py) {
				tmp = (d[x] - d[y]) % 3; if(tmp < 0) tmp += 3;
				if(tmp != t) ans++;
			}
			else {
				root[px] = py;
				i = (d[x] - d[y] - t) % 3;
				d[px] = i < 0? -i : -i+3;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
