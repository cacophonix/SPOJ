/*
USER: zobayer
TASK: MIXTURES
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
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define i64 long long
#define ff first
#define ss second
#define DEBUG if(0)

const double EPS = 1e-9;
const double BIG = 1e15;
const int NIL = 0;
const int INF = 0x7f7f7f7f;
const int MAX = 128;

int dp[MAX][MAX], mix[MAX][MAX], color[MAX];

int solve(int s, int e) {
	if(dp[s][e] > -1) return dp[s][e];
	int ret = INF, smoke;
	for(int i = s; i < e; i++) {
		smoke = mix[s][i] * mix[i+1][e];
		smoke += solve(s, i);
		smoke += solve(i+1, e);
		ret = smoke < ret? smoke : ret;
	}
	return dp[s][e] = ret;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, i, j;
	while(scanf("%d", &n)==1) {
		for(i = 0; i < n; i++) scanf("%d", &color[i]);
		for(i = 0; i < n; i++) {
			mix[i][i] = color[i];
			dp[i][i] = 0;
			for(j = i + 1; j < n; j++) {
				mix[i][j] = mix[i][j-1] + color[j];
				dp[i][j] = -1;
				if(mix[i][j] >= 100) mix[i][j] -= 100;
			}
		}
		printf("%d\n", solve(0, n-1));
	}
	//system("pause");
	return 0;
}
