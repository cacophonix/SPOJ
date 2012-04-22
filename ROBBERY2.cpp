/*
USER: zobayer
TASK: ROBBERY2
ALGO: ad-hoc
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

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }

#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, i, k;
	i64 a, n, p, s, each[100];
	scanf("%d", &test);
	while(test--) {
		scanf("%lld %d", &a, &k);
		n = (i64)(0.5 * (sqrt(1.0 + 8.0 * a) - 1.0));
		p = n / k; n = p * k;
		for(i = 1; i <= k; i++) each[i-1] = (2*i + (p-1)*k) * p / 2;
		s = n + 1; a -= n*(n+1)/2;
		for(i = 0; i < k && a > 0; i++) {
			if(s <= a) {
				each[i] += s;
				a -= s++;
			}
			else {
				each[i] += a;
				a = 0;
			}
		}
		printf("%lld", each[0]);
		for(i = 1; i < k; i++) printf(" %lld", each[i]);
		printf("\n");
	}
	return 0;
}
