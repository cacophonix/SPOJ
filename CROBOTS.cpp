/*
USER: zobayer
TASK: CROBOTS
ALGO: simulation
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
const int MAX = 111;
struct ROBOT { int r, c, d; };

char grid[MAX][MAX];
ROBOT robots[MAX];
int dr[] = {0+0,0+1,0+0,0-1};
int dc[] = {0+1,0+0,0-1,0+0};

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	char dir[2];
	int R, C, r1, c1, test, n, q, p, stp, i, mishap;
	scanf("%d", &test);
	while(test--) {
		scanf("%d%d%d%d", &C, &R, &n, &q);
		CLR(grid);
		for(i = 1; i <= n; i++) {
			scanf("%d%d%s", &robots[i].c, &robots[i].r, dir);
			robots[i].r = R + 1 - robots[i].r;
			grid[robots[i].r][robots[i].c] = i;
			switch(dir[0]) {
				case 'E': robots[i].d = 0; break;
				case 'S': robots[i].d = 1; break;
				case 'W': robots[i].d = 2; break;
				case 'N': robots[i].d = 3; break;
			}
		}
		mishap = 0;
		while(q--) {
			scanf("%d%s%d", &p, dir, &stp);
			if(robots[p].d == -1 || mishap) continue;
			if(dir[0]=='F') {
				while(stp--) {
					r1 = robots[p].r + dr[robots[p].d];
					c1 = robots[p].c + dc[robots[p].d];
					if(r1 < 1 || r1 > R || c1 < 1 || c1 > C) {
						robots[p].d = -1;
						printf("Robot %d crashes into the wall\n", p);
						mishap = 1;
						break;
					}
					else if(grid[r1][c1]) {
						robots[p].d = -1;
						robots[grid[r1][c1]].d = -1;
						mishap = 1;
						printf("Robot %d crashes into robot %d\n", p, (int)grid[r1][c1]);
						break;
					}
					else {
						grid[robots[p].r][robots[p].c] = 0;
						grid[r1][c1] = p;
						robots[p].r = r1;
						robots[p].c = c1;
					}
				}
			}
			else {
				stp &= 3;
				while(stp--) robots[p].d = (robots[p].d+((dir[0]=='L')?3:1))&3;
			}
		}
		if(!mishap) printf("OK\n");
	}
	return 0;
}
