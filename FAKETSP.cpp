/*
USER: zobayer
TASK: FAKETSP
ALGO: geometry
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
typedef double ld;
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

struct point {
	ld x, y;
};

inline ld dist(point a, point b) {
	return sqrt(sq(a.x-b.x) + sq(a.y-b.y));
}

int main() {
	point p, q;
	ld res = 0.0;
	//READ("in.txt");
	//WRITE("out.txt");
	scanf("%*[^(](%lf, %lf).", &p.x, &p.y);
	while(scanf("%*[^(](%lf, %lf).", &q.x, &q.y)==2) {
		res += dist(p, q);
		printf("The salesman has traveled a total of %.3lf kilometers.\n", res);
		p = q;
	}
	return 0;
}
