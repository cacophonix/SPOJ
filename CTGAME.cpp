/*
USER: zobayer
TASK: CTGAME
ALGO: stack
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
const int MAX = 1009;

int calc(int *ht, int n) {
	int ret = 0, top = 1, st[MAX], i;
	ht[0] = st[0] = ht[++n] = 0;
	for(i = 1; i <= n; i++) {
		while(top > 1 && ht[st[top-1]] >= ht[i]) {
			ret = _max(ret, ht[st[top-1]]*(i - st[top-2]-1));
			top--;
		}
		st[top++] = i;
	}
	return ret;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, i, j, k, ret, R, C, row[2][MAX];
	char str[2048];
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d", &R, &C);
		fgets(str, 2048, stdin);
		memset(row[0], 0, sizeof(int)*(C+1));
		for(ret = 0, i = 1; i <= R; i++) {
			fgets(str, 2048, stdin);
			for(j = 0, k = 1; str[j]; j++) {
				if(str[j]=='F') { row[i&1][k] = 1 + row[(i-1)&1][k]; k++; }
				else if(str[j]=='R') row[i&1][k++] = 0;
			}
			ret = _max(ret, calc(row[i&1], C));
		}
		printf("%d\n", 3*ret);
	}
	return 0;
}
