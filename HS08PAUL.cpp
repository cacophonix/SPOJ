/*
USER: zobayer
TASK: HS08PAUL
ALGO: math
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
#define ALL(c) c.begin(), c.end()
#define PB(x) push_back(x)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define BIG(p) memset(p, 0x3f, sizeof(p))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) c.size()

typedef long long i64;
typedef unsigned long long u64;
typedef pair< int, int > pii;

template< class T > T _abs(const T &n) { return (n < 0 ? -n : n); }
template< class T > T _max(const T &a, const T &b) { return (a > b ? a : b); }
template< class T > T _min(const T &a, const T &b) { return (a < b ? a : b); }
template< class T > T gcd(const T a, const T b) { return (b ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(const T a, const T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inrange(const T &a, const T &b, const T &c) { return a<=b && b<=c; }
template< class T > T sq(const T &x) { return x * x; }

const double EPS = 1e-10;
const int INF = 0x3f3f3f3f;

const int MAX = 10010896;
const int LMT = 3164;
int flag[MAX>>6], mark[MAX];

#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
	int i, j, k;
	for(i=3; i<LMT; i+=2)
		if(!ifc(i))
			for(j=i*i, k=i<<1; j<MAX; j+=k)
				isc(j);
}

inline bool isprime(int n) {
	if(n<2) return false;
	if(n==2) return true;
	if(n&1 && !ifc(n)) return true;
	return false;
}

void gen() {
	int x, y, p, q, n;
	for(x=0; (p=x*x) < MAX; x++) {
		for(y=0; (q=y*y*y*y) < MAX; y++) {
			n = p + q;
			if(n < MAX && isprime(n)) {
				mark[n] = 1;
			}
		}
	}
	for(n=1; n<MAX; n++) mark[n] += mark[n-1];
}

int main() {
	sieve();
	gen();
	int t, n;
	for(scanf("%d", &t); t--; ) {
		scanf("%d", &n);
		printf("%d\n", mark[n]);
	}
	return 0;
}
