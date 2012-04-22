/*
USER: zobayer
TASK: GCJ101C
ALGO: math
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
#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PAUSE system("pause")
#define SL(x, n) ((x)<<(n))
#define SR(x, n) ((x)>>(n))
#define ALL(c) c.begin(), c.end()
#define SIZE(c) c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >
#define debug if(1)

const double EPS = 1e-9;
const double BIG = 1e19;
const int INF = 0x7f7f7f7f;

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, cs = 1, k, i;
	i64 l, p, c, x;
	scanf("%d", &test);
	while(test--) {
		scanf("%lld%lld%lld", &l, &p, &c);
		k = i = 0; x = l;
		while(x < p) {
			x *= c;
			k++;
		}
		while(SL(1, i) < k) i++;
		printf("Case #%d: %d\n", cs++, i);
	}
	return 0;
}
