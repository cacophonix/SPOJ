/*
USER: zobayer
TASK: TETRAVEX
ALGO: backtrack
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

const int MAX = 9;

struct Piece {
	int U, D, R, L;
};

Piece P[MAX];
bool used[MAX], done;
int grid[MAX];
int up[] = {-1, -1, -1, 0, 1, 2, 3, 4, 5};
int lt[] = {-1, 0, 1, -1, 3, 4, -1, 6, 7};

void solve(int pos) {
	if(pos == 9) {
		done = true;
		return;
	}
	int upval = up[pos] >= 0? P[grid[up[pos]]].D : -1;
	int ltval = lt[pos] >= 0? P[grid[lt[pos]]].R : -1;
	for(int i = 0; i < 9; i++) {
		if(!used[i] && (upval==P[i].U || upval==-1) && (ltval==P[i].L || ltval==-1)) {
			used[i] = true;
			grid[pos] = i;
			solve(pos+1);
			if(done) return;
			used[i] = false;
		}
	}
	grid[pos] = -1;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int t, i, cs = 1;
	scanf("%d", &t);
	while(t--) {
		done = false;
		CLR(used); SET(grid);
		for(i = 0; i < 9; i++) scanf("%d%d%d%d", &P[i].U, &P[i].R, &P[i].D, &P[i].L);
		solve(0);
		if(done) printf("Case %d: YES\n", cs++);
		else printf("Case %d: NO\n", cs++);
		if(t) printf("\n");
		//printf("\n");
	}
	//system("pause");
	return 0;
}
