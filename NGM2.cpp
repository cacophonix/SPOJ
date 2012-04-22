/*
USER: zobayer
TASK: NGM2
ALGO: inclusion exclusion
*/

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>
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
#include <limits>
#include <numeric>
#include <utility>
#include <valarray>
using namespace std;

#define DEBUG if(0)
#define PAUSE system("pause")
#define OFF ios::sync_with_stdio(false)
#define ALL(c) c.begin(), c.end()
#define PB(x) push_back(x)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define BIG(p) memset(p, 0x3f, sizeof(p))
#define REV(s, e) reverse(s, e);
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) c.size()
#define TBIT(c, n) !!(c & (1 << n))
#define SBIT(c, n) (c |= (1 << n))
#define CBIT(c, n) (c &= ~(1 << n))

template< class T > T abst(const T &n) { return (n < 0 ? -n : n); }
template< class T > T max2(const T &a, const T &b) { return (!(a < b) ? a : b); }
template< class T > T min2(const T &a, const T &b) { return (a < b ? a : b); }
template< class T > T max3(const T &a, const T &b, const T &c) { return max2(a, max2(b, c)); }
template< class T > T min3(const T &a, const T &b, const T &c) { return min2(a, min2(b, c)); }
template< class T > T gcd(const T a, const T b) { return (b ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(const T a, const T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T mod(const T &a, const T &b) { return (a < b ? a : a % b); }
template< class T > bool inrange(const T &a, const T &b, const T &c) { return a<=b && b<=c; }
template< class T > T sq(const T &x) { return x * x; }

const int MAX = 16;

int main() {
	int i, j, k, tot, nb;
	i64 d, val, n, a[MAX];
	cin >> n >> k;
	for(i = 0; i < k; i++) cin >> a[i];
	tot = (1 << k), d = n;
	for(i = 1; i < tot; i++) {
		nb = 0, val = 1;
		for(j=0; j < k; j++) {
			if(i & (1<<j)) {
				nb++;
				val = lcm(val, a[j]);
			}
		}
		if(nb & 1) n -= d / val;
		else n += d / val;
	}
	printf("%lld\n", n);
	return 0;
}
