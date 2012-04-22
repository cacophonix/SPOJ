/*
USER: zobayer
TASK: SEQ
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
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define i64 long long
#define ff first
#define ss second
#define DEBUG if(0)

const double EPS = 1e-9;
const double BIG = 1e15;
const int NIL = 0;
const int INF = 0x3f3f3f3f;
const int MAX = 11, MOD = 1000000000;

int mat[MAX][MAX], m[MAX][MAX], a[MAX];

void multi(int x[MAX][MAX], int y[MAX][MAX], int n) {
	int r[MAX][MAX] = {0}, i, j, k;
	i64 temp;
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++) {
			for(k = 1; k <= n; k++) {
				temp = x[i][k];
				temp *= y[k][j];
				temp += r[i][j];
				temp %= MOD;
				r[i][j] = temp;
			}
		}
	}
	CPY(x, r);
}

void expo(int p, int n) {
	if(!p) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) m[i][j] = 0;
			m[i][i] = 1;
		}
	}
	else if(p & 1) {
		expo(p-1, n);
		multi(m, mat, n);
	}
	else {
		expo(p >> 1, n);
		multi(m, m, n);
	}
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t, i, j, k, n;
	i64 sum, temp;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &k);
		for(i = k; i; i--) scanf("%d", &a[i]);
		for(j = 1; j <= k; j++) scanf("%d", &mat[1][j]);
		scanf("%d", &n);
		if(n <= k) printf("%d\n", a[k-n+1] % MOD);
		else {
			for(i = 2; i <= k; i++) {
				for(j = 1; j <= k; j++) mat[i][j] = 0;
				mat[i][i-1] = 1;
			}
			expo(n-k, k);
			sum = 0;
			for(i = 1; i <= k; i++) {
				temp = m[1][i];
				temp *= a[i];
				sum += temp;
				sum %= MOD;
			}
			printf("%d\n", (int)sum);
		}
	}
	return 0;
}
