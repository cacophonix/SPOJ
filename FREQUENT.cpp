/*
USER: zobayer
TASK: FREQUENT
ALGO: segment tree
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
template< class T > T mod(T a, T b) { return (a < b ? a : a % b); }
template< class T > bool inside(T &a, T &b, T &c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

const int INF = 0x3f3f3f3f;
const double EPS = 1e-10;
const int MAX = 1<<17;

struct NODE { int mfreq, lfreq, rfreq; };

int a[MAX];
struct NODE Tree[MAX<<1];

void init(int Node, int i, int j) {
	if(i==j) {
		Tree[Node].lfreq = Tree[Node].rfreq = Tree[Node].mfreq = 1;
		return;
	}
	int m = (i + j)>>1;
	init(Node<<1, i, m);
	init((Node<<1)+1, m+1, j);
	if(a[m]==a[m+1]) {
		Tree[Node].lfreq = Tree[Node<<1].lfreq + Tree[(Node<<1)+1].lfreq * (a[i]==a[m]);
		Tree[Node].rfreq = Tree[(Node<<1)+1].rfreq + Tree[Node<<1].rfreq * (a[j]==a[m+1]);
		int temp = Tree[Node<<1].rfreq + Tree[(Node<<1)+1].lfreq;
		Tree[Node].mfreq = max(temp, max(Tree[Node<<1].mfreq, Tree[(Node<<1)+1].mfreq));
	}
	else {
		Tree[Node].lfreq = Tree[Node<<1].lfreq;
		Tree[Node].rfreq = Tree[(Node<<1)+1].rfreq;
		Tree[Node].mfreq = max(Tree[Node<<1].mfreq, Tree[(Node<<1)+1].mfreq);
	}
}

int query(int Node, int i, int j, int u, int v) {
	if(u==i && v==j) return Tree[Node].mfreq;
	int m = (i+j)>>1;
	if(v <= m) return query(Node<<1, i, m, u, v);
	if(u > m) return query((Node<<1)+1, m+1, j, u, v);
	int leftv = query(Node<<1, i, m, u, m);
	int rightv = query((Node<<1)+1, m+1, j, m+1, v);
	if(a[m]==a[m+1]) {
		int temp = min(Tree[Node<<1].rfreq, m-u+1) + min(Tree[(Node<<1)+1].lfreq, v-m);
		return max(temp, max(rightv, leftv));
	}
	else return max(leftv, rightv);
}

int main() {
	int n, q, i, u, v;
	while(scanf("%d", &n)==1 && n) {
		scanf("%d", &q);
		for(i = 0; i < n; i++) scanf("%d", &a[i]);
		init(1, 0, n-1);
		for(i = 0; i < q; i++) {
			scanf("%d%d", &u, &v);
			if(u==v) printf("1\n");
			else printf("%d\n", query(1, 0, n-1, --u, --v));
		}
	}
	return 0;
}
