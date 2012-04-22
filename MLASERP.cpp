/*
USER: zobayer
TASK: MLASERP
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

const double EPS = 1e-9;
const double BIG = 1e15;
const int NIL = 0;
const int INF = 0x3f3f3f3f;
const int MAX = 128;

char grid[MAX][MAX];
int d[MAX][MAX];
int R, C, sr, sc, er, ec;
int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

bool valid(int r, int c) {
	return (inside(0, r, R-1) && inside(0, c, C-1));
}

int bfs() {
	int r1, c1, r2, c2, i, dir;
	queue< int > Q;
	MEM(d, 0x3f);
	d[sr][sc] = -1;
	Q.push(sr); Q.push(sc);
	while(!Q.empty()) {
		r1 = Q.front(); Q.pop();
		c1 = Q.front(); Q.pop();
		for(i = 0; i < 4; i++) {
			r2 = r1 + dr[i];
			c2 = c1 + dc[i];
			while(valid(r2, c2) && grid[r2][c2] != '*') {
				if(d[r2][c2] > d[r1][c1] + 1) {
					d[r2][c2] = d[r1][c1] + 1;
					if(r2==er && c2==ec) return d[r2][c2];
					Q.push(r2); Q.push(c2);
				}
				r2 += dr[i];
				c2 += dc[i];
			}
		}
	}
	return d[er][ec];
}

int main() {
	DEBUG READ("in.txt");
	DEBUG WRITE("out.txt");
	int i, j, cnt = 0;
	scanf("%d%d", &C, &R);
	for(i = 0; i < R; i++) {
		scanf("%s", grid[i]);
		for(j = 0; j < C && cnt < 2; j++) {
			if(grid[i][j]=='C') {
				if(cnt==0) sr = i, sc = j, cnt++;
				else er = i, ec = j, cnt++;
			}
		}
	}
	printf("%d\n", bfs());
	return 0;
}
