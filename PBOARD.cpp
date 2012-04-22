/*
USER: zobayer
TASK: PBOARD
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
#define i64 long long
#define ff first
#define ss second
#define DEBUG if(0)

const double EPS = 1e-9;
const double BIG = 1e15;
const int NIL = 0;
const int INF = 0x3f3f3f3f;
const int MOD = 10007;

int base[4][4] = {{2, 2, 1, 0}, {1, 0, 0, 0}, {0, 0, 2, 2}, {0, 0, 1, 0}};
int m[4][4];

void mul(int m1[4][4], int m2[4][4]) {
	int res[4][4] = {0}, i, j, k;
	for(i = 0; i < 4; i++) {
		for(j = 0; j < 4; j++) {
			for(k = 0; k < 4; k++) {
				res[i][j] += m1[i][k] * m2[k][j];
				res[i][j] %= MOD;
			}
		}
	}
	memcpy(m, res, sizeof(res));
}

void exponent(int n) {
	if(n==0) {
		CLR(m);
		for(int i = 0; i < 4; i++) m[i][i] = 1;
	}
	else if(n & 1) {
		exponent(n-1);
		mul(base, m);
	}
	else {
		exponent(n>>1);
		mul(m, m);
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	while(scanf("%d", &n)==1 && n >= 0) {
		if(n == 0) printf("1\n");
		else {
			exponent(n-1);
			printf("%d\n", (4*m[0][0]+m[0][1]+6*m[0][2]+2*m[0][3])%MOD);
		}
	}
	//system("pause");
	return 0;
}
