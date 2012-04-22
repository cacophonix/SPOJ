/*
USER: zobayer
TASK: HISTOGRA
ALGO: stack
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

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }

#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
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
const int MAX = 100009;

i64 calc(int *ht, int n) {
	i64 ret = 0;
	int top = 1, st[MAX], i;
	ht[0] = st[0] = ht[++n] = 0;
	for(i = 1; i <= n; i++) {
		while(top > 1 && ht[st[top-1]] >= ht[i]) {
			ret = _max(ret, (i64)ht[st[top-1]]*(i64)(i - st[top-2]-1));
			top--;
		}
		st[top++] = i;
	}
	return ret;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int n, i, ht[MAX];
	while(scanf("%d", &n)==1 && n) {
		for(i = 1; i <= n; i++) scanf("%d", &ht[i]);
		printf("%lld\n", calc(ht, n));
	}
	return 0;
}
