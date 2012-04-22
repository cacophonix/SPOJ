/*
USER: zobayer
TASK: ANARC08I
ALGO: divide and conquer
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

i64 solve(int n, i64 r, i64 i, i64 j, i64 s, i64 e) {
	if(i == s && j == e) {
		if(!r) return j - i + 1;
		return 0;
	}
	i64 m, c, k;
	m = (i + j) >> 1; c = 1; c <<= n; k = 1;
	if(r >= (c>>1)) r -= (c>>1), k = -1;
	if(e <= m) return solve(n-1, r, i, m, s, e);
	else if(s > m) return solve(n-1, r, m+1, j, s, e) * k;
	return solve(n-1, r, i, m, s, m) + solve(n-1, r, m+1, j, m+1, e) * k;
}

int main() {
	i64 r, s, e, k;
	int n;
	while(scanf("%d %lld %lld %lld", &n, &r, &s, &e)==4 && n > -1) {
		k = 1; k <<= n;
		printf("%lld\n", solve(n, r, 0, k-1, s, e));
	}
	return 0;
}
