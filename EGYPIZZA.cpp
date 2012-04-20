/*
USER: zobayer
TASK: EGYPIZZA
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

#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
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

template< class T > T sq(T x) { return x * x; }
template< class T > T abs(T n) { return (n < 0 ? -n : n); }
template< class T > T max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T min(T a, T b) { return (a < b ? a : b); }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T mod(T a, T b) { return (a < b ? a : a % b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

const int MAX = 10001;

int main() {
	DEBUG READ("in.txt");
	DEBUG WRITE("out.txt");
	
	int n, i, cnt14 = 0, cnt12 = 0, cnt34 = 0, ans = 1, a, b;
	
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d/%d", &a, &b);
		switch(a+b) {
			case 3: cnt12++; break;
			case 5: cnt14++; break;
			case 7: cnt34++; break;
		}
	}	
	
	// for 3/4
	ans += cnt34;
	cnt14 -= cnt34;
	setmax(cnt14, 0);
	
	// for 1/2
	ans += (cnt12 >> 1);
	cnt12 &= 1;
	if(cnt12) ans++, cnt14 -= 2, setmax(cnt14, 0);
	
	// for 1/4
	ans += ((cnt14 + 3) >> 2);
	
	printf("%d\n", ans);
	return 0;
}
