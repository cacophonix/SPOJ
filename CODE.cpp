/*
USER: zobayer
TASK: CODE
ALGO: euler cycle
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

int s[1000032];
int state[100032];
char digit[1000032];

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int i, node, pwr, sp, norm, digits;
	while(scanf("%d", &pwr)==1 && pwr) {
		for(norm=i=1; i < pwr; i++, norm*=10);
		for(node=0; node < norm; node++) state[node] = 0;
		sp = node = digits = 0;
		while(true) {
			if(state[node] < 10) {
				s[sp++] = (node<<4) + state[node];
				node = (10 * node + state[node]++) % norm;
			}
			else if(sp) {
				digit[digits++] = (s[--sp]&15) + '0';
				node = s[sp]>>4;
			}
			else break;
		}
		for(i = 0; i < pwr-1; i++) digit[digits++] = digit[i];
		//while(digits--) putchar(digit[digits]); putchar('\n');
		digit[digits] = 0; puts(digit);
	}
	//system("pause");
	return 0;
}
