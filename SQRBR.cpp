/*
USER: zobayer
TASK: SQRBR
ALGO: dynamic programming
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
const int MAX = 40;

bool f[MAX];
int dp[MAX][MAX], n;

i64 solve(int pos, int open) {
	if(open < 0) return 0; // invalid
	if(pos == n) return open == 0; // must for being valid
	int &ret = dp[pos][open];
	if(ret != -1) return ret;
	if(f[pos]) return ret = solve(pos+1, open+1); // must put a [ here
	return ret = solve(pos+1, open+1) + solve(pos+1, open-1); // try [ and ] both
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t, k, m, i;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &k);
		n <<= 1;
		CLR(f); SET(dp);
		for(i = 0; i < k; i++) {
			scanf("%d", &m);
			f[m-1] = 1;
		}
		printf("%lld\n", solve(0, 0));
	}
	//system("pause");
	return 0;
}
