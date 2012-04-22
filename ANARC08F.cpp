/*
USER: zobayer
TASK: ANARC08F
ALGO: warshall
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
const int INF = 0x3f3f3f3f;

map< string, int > M;
map< string, int >::iterator it;
int grid[100][100];
int broken[1000];

int hash(char *s, int &n) {
	int r; it = M.find(s);
	if(it == M.end()) M.insert(pair< string, int >(s, r=n++));
	else r = it->ss;
	return r;
}

int main() {
	//READ("one.in");
	//WRITE("out.txt");
	int n, c, r, cs = 1, gar, k, i, j, l, w, u, v, tot;
	char name1[32], name2[32], dir[32], temp[32];
	while(scanf("%d %d %d", &n, &c, &r)==3 && n) {
		M.clear(); k = 0; MEM(grid, 0x3f);
		for(i = 0; i < n; i++) grid[i][i] = 0;
		scanf("%s", name1); gar = hash(name1, k);
		for(i = 0; i < c; i++) {
			scanf("%s", name1);
			broken[i] = hash(name1, k);
		}
		for(i = 0; i < r; i++) {
			scanf("%s %s %s", name1, temp, name2);
			u = hash(name1, k); v = hash(name2, k);
			for(w = j = l = 0; temp[j]; j++) {
				if(isdigit(temp[j])) w = w * 10 + temp[j] - '0';
				else dir[l++] = temp[j];
			}
			if(dir[0] == '<') grid[v][u] = _min(w, grid[v][u]);
			if(dir[3] == '>') grid[u][v] = _min(w, grid[u][v]);
		}
		for(k = 0; k < n; k++) {
			for(i = 0; i < n; i++) {
				for(j = 0; j < n; j++) {
					grid[i][j] = _min(grid[i][j], grid[i][k] + grid[k][j]);
				}
			}
		}
		for(tot = i = 0; i < c; i++) {
			tot += grid[gar][broken[i]];
			tot += grid[broken[i]][gar];
		}
		printf("%d. %d\n", cs++, tot);
	}
	return 0;
}
