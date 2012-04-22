/*
USER: zobayer
TASK: SPP
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

i64 base[16][16], X[16], mod;
int d, n;

void mul(i64 a[16][16], i64 b[16][16]) {
	int i, j, k;
	i64 r[16][16];
	for(i = 0; i < d; i++) {
		for(j = 0; j < d; j++) {
			r[i][j] = 0;
			for(k = 0; k < d; k++) {
				r[i][j] += a[i][k]*b[k][j];
				if(r[i][j] >= mod) r[i][j] %= mod;
			}
		}
	}
	CPY(a, r);
}

void pwr(i64 r[16][16], i64 e) {
	i64 b[16][16];
	for(int i = 0; i < d; i++) {
		for(int j = 0; j < d; j++) {
			r[i][j] = 0;
			b[i][j] = base[i][j];
		}
		r[i][i] = 1;
	}
	while(e > 0) {
		if(e & 1) mul(r, b);
		e >>= 1;
		mul(b, b);
	}
}

i64 sum(i64 x) {
	i64 ret = 0;
	if(x <= n) {
		for(int i = 1; i <= x; i++) {
			ret += X[n-i];
			if(ret >= mod) ret %= mod;
		}
	}
	else {
		i64 r[16][16];
		pwr(r, x-n);
		for(int i = 0; i < d; i++) {
			ret += r[n][i] * X[i];
			if(ret >= mod) ret %= mod;
		}
	}
	return ret;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, i;
	i64 a, b, tot;
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		d = n + 1;
		
		X[n] = 0;
		for(i = n - 1; i >= 0; i--) {
			scanf("%lld", &X[i]);
			X[n] += X[i];
		}
		
		CLR(base);
		for(i = 1; i < n; i++) base[i][i-1] = 1;
		for(i = 0; i < n; i++) {
			scanf("%lld", &base[0][i]);
			base[n][i] = base[0][i];
		}
		base[n][n] = 1;
		
		scanf("%lld%lld%lld", &a, &b, &mod);
		tot = ( sum(b) - sum(a - 1) ) % mod;
		if(tot < 0) tot += mod;
		printf("%lld\n", tot);
	}
	return 0;
}