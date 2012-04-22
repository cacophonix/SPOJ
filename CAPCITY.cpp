/*
USER: zobayer
TASK: CAPCITY
ALGO: strongly connected component
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

typedef pair< int, int > pii;

const double EPS = 1e-9;
const double BIG = 1e15;
const int NIL = 0;
const int INF = 0x3f3f3f3f;
const int MAX = 100032;

vector< int > G[MAX], R[MAX], res;
vector< pii > E;
int compo[MAX], flag[MAX], S[MAX], top, curr, outdeg[MAX], ncompo;

void dfs(int u) {
	if(flag[u]==1) return;
	flag[u] = 1;
	for(int i = 0; i < SZ(G[u]); i++) dfs(G[u][i]);
	S[top++] = u;
}

void mark(int u) {
	compo[u] = curr;
	for(int i = 0; i < SZ(R[u]); i++) {
		if(flag[R[u][i]]==1) {
			flag[R[u][i]] = 0;
			mark(R[u][i]);
		}
	}
}

int find0() {
	int ans = -1, i;
	for(i = 1; i <= ncompo; i++) {
		if(!outdeg[i]) {
			if(ans!=-1) return -1;
			else ans = i;
		}
	}
	return ans;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, e, u, v;
	scanf("%d%d", &n, &e);
	while(e--) {
		scanf("%d%d", &u, &v);
		G[u].PB(v);
		R[v].PB(u);
		E.PB(pii(u,v));
	}
	top = 0, curr = 0;
	for(u = 1; u <= n; u++) dfs(u);
	for(e = top-1; e >= 0; e--) if(flag[S[e]]==1) {
		ncompo = ++curr;
		flag[S[e]] = 0;
		mark(S[e]);
	}
	for(e = 0; e < SZ(E); e++)
		if(compo[E[e].ff] != compo[E[e].ss])
			outdeg[compo[E[e].ff]]++;
	curr = find0();
	if(curr == -1) {
		printf("0\n");
		return 0;
	}
	for(u = 1; u <= n; u++)
		if(compo[u]==curr)
			res.PB(u);
	printf("%d\n%d", SZ(res), res[0]);
	for(e = 1; e < SZ(res); e++) printf(" %d", res[e]);
	printf("\n");
	return 0;
}
