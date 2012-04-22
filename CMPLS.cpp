/*
USER: zobayer
TASK: CMPLS
ALGO: math
*/

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
#include <numeric>
#include <utility>
using namespace std;

#define DEBUG if(0)
#define PAUSE system("pause")
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

template< class T > T sq(T &x) { return x * x; }
template< class T > T abs(T &n) { return (n < 0 ? -n : n); }
template< class T > T max(T &a, T &b) { return (!(a < b) ? a : b); }
template< class T > T min(T &a, T &b) { return (a < b ? a : b); }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T mod(T &a, T &b) { return (a < b ? a : a % b); }
template< class T > bool inside(T &a, T &b, T &c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const int MAX = 101;

int seq[MAX][MAX];

int main() {
	int t, given, asked, i, j;
	//READ("in.txt");
	//WRITE("out.txt");
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &given, &asked);
		for(i = 0; i < given; i++) scanf("%d", &seq[0][i]);
		for(i = 1; i < given; i++)
			for(j = 0; j < given-i; j++)
				seq[i][j] = seq[i-1][j+1] - seq[i-1][j];
		for(i = 1; i <= asked; i++) seq[given-1][i] = seq[given-1][i-1];
		for(i = given-2; i >= 0; i--)
			for(j = given-i; j < given-i+asked; j++)
				seq[i][j] = seq[i+1][j-1] + seq[i][j-1];
		printf("%d", seq[0][given]);
		for(i = 1; i < asked; i++) printf(" %d", seq[0][given+i]);
		printf("\n");
	}
	return 0;
}
