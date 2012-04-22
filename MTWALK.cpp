/*
USER: zobayer
TASK: MTWALK
ALGO: breadth first search
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
#define i64 long long
#define ff first
#define ss second
#define DEBUG if(0)

const double EPS = 1e-9;
const double BIG = 1e15;
const int NIL = 0;
const int INF = 0x3f3f3f3f;
const int MAX = 128;

int d[MAX][MAX][MAX], grid[MAX][MAX], n;
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int bfs() {
	int r1, c1, r2, c2, h1, h2, w1, w2, i;
	queue< int > Q;
	Q.push(0), Q.push(0), Q.push(grid[0][0]);
	d[0][0][grid[0][0]] = 0;
	while(!Q.empty()) {
		r1 = Q.front(); Q.pop();
		c1 = Q.front(); Q.pop();
		h1 = Q.front(); Q.pop();
		w1 = d[r1][c1][h1];
		for(i = 0; i < 4; i++) {
			r2 = r1 + dr[i];
			c2 = c1 + dc[i];
			if(inside(0, r2, n-1) && inside(0, c2, n-1)) {
				if(h1 > grid[r2][c2]) h2 = grid[r2][c2], w2 = w1 + h1 - h2;
				else h2 = h1, w2 = max(w1, grid[r2][c2] - h1);
				if(d[r2][c2][h2] > w2) {
					d[r2][c2][h2] = w2;
					if(r2==n-1 && c2==n-1) continue;
					Q.push(r2), Q.push(c2), Q.push(h2);
				}
			}
		}
	}
	for(i = 0, w1 = INF; i < MAX; i++) setmin(w1, d[n-1][n-1][i]);
	return w1;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int i, j;
	scanf("%d", &n);
	MEM(d, 0x3f);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf("%d", &grid[i][j]);
	printf("%d\n", bfs());	
	//system("pause");
	return 0;
}
