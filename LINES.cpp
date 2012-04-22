/*
USER: zobayer
TASK: LINES
ALGO: geometry
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

template< class T > T abs(T n) { return (n < 0 ? -n : n); }
template< class T > T max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const double BIG = 1e19;
const int INF = 0x7f7f7f7f;

struct Point { int x, y; };
struct Slope { int dx, dy; };

Point points[200];
Slope slopes[40000];

bool comp(const Slope &a, const Slope &b) {
	return a.dx * b.dy < b.dx * a. dy;
}

bool equal(const Slope &a, const Slope &b) {
	return a.dx * b.dy == b.dx * a. dy;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int n, i, j, k;
	while(scanf("%d", &n) == 1 && n) {
		for(i = 0; i < n; i++) scanf("%d%d", &points[i].x, &points[i].y);
		for(i = k = 0; i < n-1; i++) {
			for(j = i + 1; j < n; j++, k++) {
				slopes[k].dx = points[i].x - points[j].x;
				slopes[k].dy = points[i].y - points[j].y;
				if(slopes[k].dy < 0) slopes[k].dy *= -1, slopes[k].dx *= -1;
				if(!slopes[k].dy) slopes[k].dx = abs(slopes[k].dx);
			}
		}
		sort(slopes, slopes + k, comp);
		for(i = j = 1; i < k; i++) j += !equal(slopes[i-1], slopes[i]);
		printf("%d\n", j);
	}
	return 0;
}