/*
USER: zobayer
TASK: DIVREL
ALGO: bipartite matching
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
const int MAX = 256;

vector < int > G[MAX];
bool visited[MAX];
int Left[MAX], Right[MAX];
int num[MAX], avail[MAX], store[MAX];

bool dfs(int u) {
	if(visited[u]) return false;
	visited[u] = true;
	int len = G[u].size(), i, v;
	for(i=0; i<len; i++) {
		v = G[u][i];
		if(avail[v]) continue;
		if(Right[v]==-1) {
			Right[v] = u, Left[u] = v;
			return true;
		}
	}
	for(i=0; i<len; i++) {
		v = G[u][i];
		if(avail[v]) continue;
		if(dfs(Right[v])) {
			Right[v] = u, Left[u] = v;
			return true;
		}
	}
	return false;
}

int match(int n) {
	int i, ret = 0;
	bool done;
	SET(Left); SET(Right);
	do {
		done = true; CLR(visited);
		for(i=0; i<n; i++) {
			if(avail[i]) continue;
			if(Left[i]==-1 && dfs(i)) {
				done = false;
			}
		}
	} while(!done);
	for(i=0; i<n; i++) {
		if(avail[i]) continue;
		ret += (Left[i]!=-1);
	}
	return ret;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int n, i, j, mc, nc, sz, cnt, out;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &num[i]);
	sort(num, num+n);
	n = unique(num, num+n) - num;
	for(i = 0; i < n; i++) {
		for(j = i+1; j < n; j++) {
			if(num[j]%num[i]==0) {
				G[i].PB(j);
			}
		}
	}
	mc = n - match(n);
	for(i = cnt = out = 0; i < n && cnt < mc; i++) {
		if(avail[i]) continue;
		sz = G[i].size();
		//avail[i] = 0;
		for(j = 0; j < sz; j++) {
			if(!avail[G[i][j]]) out++;
			avail[G[i][j]]++;
		}
		nc = n - out - match(n);
		if(mc == nc) store[cnt++] = i;
		else {
			//avail[i] = -1;
			for(j = 0; j < sz; j++) {
				avail[G[i][j]]--;
				if(!avail[G[i][j]]) out--;
			}
		}
	}
	printf("%d\n", mc);
	printf("%d", num[store[0]]);
	for(i = 1; i < mc; i++) printf(" %d", num[store[i]]);
	printf("\n");
	return 0;
}