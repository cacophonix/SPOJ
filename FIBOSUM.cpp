/*
USER: zobayer
TASK: FIBOSUM
ALGO: matrix exponentiation
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
#define ALL(c) c.begin(), c.end()
#define SIZE(c) c.size()
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
const i64 MOD = 1000000007;
const i64 base[2][2] = {{1, 1}, {1, 0}};
const i64 unit[2][2] = {{1, 0}, {0, 1}};

// a = a * b
inline void mul(i64 a[2][2], i64 b[2][2]) {
	i64 r[2][2];
	r[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % MOD;
	r[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % MOD;
	r[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % MOD;
	r[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % MOD;
	CPY(a, r);
}

// r = base ^ n
inline void pwr(i64 r[2][2], int n) {
	i64 b[2][2];
	CPY(r, unit);
	CPY(b, base);
	while(n > 0) {
		if(n & 1) mul(r, b);
		n >>= 1;
		mul(b, b);
	}
}

// nth fib % MOD
inline i64 fibo(int n) {
	i64 r[2][2];
	if(!n) return 0;
	pwr(r, n-1);
	return r[0][0];
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int b, a, t;
	i64 sa, sb, ans;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &a, &b);
		sa = fibo(a + 1); // 0 to a-1
		sb = fibo(b + 2); // 0 to b
		ans = (sb - sa) % MOD;
		if(ans < 0) ans += MOD;
		printf("%lld\n", ans);
	}
	return 0;
}
