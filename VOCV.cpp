/*
USER: zobayer
TASK: VOCV
ALGO: dynamic programming
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

#define MP(x, y) make_pair(x, y)
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

#define md 10007
#define mx 100019

pii dp[mx][2];
bool vis[mx][2];

vector < int > g[mx];

pii dfs(int p,int s,int pr) {
	if(vis[p][s]) return dp[p][s];
	vis[p][s]=1;
	int i,j=g[p].size();
	pii t,r(s,1);
	bool f=1;
	for(i=0;i<j;i++) if(g[p][i]!=pr) {
		f=0;
		pii q(mx+10,0);
		if(s) {
			t=dfs(g[p][i],0,p);
			if(t.first<q.first) q=t;
			else if(t.first==q.first) q.second=(q.second+t.second)%md;
		}
		
		t=dfs(g[p][i],1,p);
		if(t.first<q.first) q=t;
		else if(t.first==q.first) q.second=(q.second+t.second)%md;
		r.first+=q.first;
		r.second=(r.second*q.second)%md;
	}
	if(f) return dp[p][s]=pii(s,1);
	return dp[p][s]=r;
}


int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int T,n,i,u,v;
	cin>>T;
	while(T--) {
		cin>>n;
		for(i=1;i<=n;i++) g[i].clear();
		for(i=1;i<n;i++) {
			scanf("%d %d",&u,&v);
			g[u].PB(v);
			g[v].PB(u);
		}
		CLR(vis);
		pii q=dfs(1,0,-1),t=dfs(1,1,-1);
		if(q.first>t.first) q=t;
		else if(q.first==t.first) q.second=(q.second+t.second)%md;
		cout<<q.first<<' '<<q.second<<'\n';
	}
	return 0;
}
