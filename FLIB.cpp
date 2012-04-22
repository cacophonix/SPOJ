/*
USER: zobayer
TASK: FLIB
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

#define UB(s, e, x) upper_bound(s, e, x)
#define LB(s, e, x) lower_bound(s, e, x)
#define NPER(s, e) next_permutation(s, e)
#define PPER(s, e) prev_permutation(s, e)
#define REV(s, e) reverse(s, e);
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PAUSE system("pause")
#define shl(x, n) ((x)<<(n))
#define shr(x, n) ((x)>>(n))
#define all(c) c.begin(), c.end()
#define sz(c) c.size()
#define pb(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define fs "%lld"
#define debug if(0)

const double EPS = 1e-9;
const double BIG = 1e19;
const int INF = 0x7f7f7f7f;
const int MOD = 1000000007;

i64 base[2][2] = {{1, 1},{1, 0}}, mat[2][2], unit[2][2] = {{1,0},{0,1}};

void mul(i64 a[2][2], i64 b[2][2]) {
	i64 temp[2][2] = {0};
	int i, j, k;
	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
			for(k = 0; k < 2; k++) {
				temp[i][j] += a[i][k] * b[k][j];
				temp[i][j] %= MOD;
			}
	CPY(a, temp);
}

void expo(i64 n) {
	if(n==0) CPY(mat, unit);
	else if(n&1) {
		expo(n-1);
		mul(mat, base);
	}
	else {
		expo(n>>1);
		mul(mat, mat);
	}
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int t;
	i64 n, res;
	scanf("%d", &t);
	while(t--) {
		scanf(fs, &n);
		n <<= 1;
		expo(n);
		res = mat[0][0]*mat[0][1];
		printf(fs, res % MOD); putchar('\n');
	}
	return 0;
}
