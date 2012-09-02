/*
USER: zobayer
TASK: STONE2
ALGO: dynamic programming
*/

#include <cassert>
#include <cctype>
#include <climits>
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

#define ALL(p) p.begin(),p.end()
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
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define cllft lft,st,mid
#define clrgt rgt,mid+1,ed
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >
#define md 1000000007

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

bool vis[103][10009];
i64 dp[103][10009],fc[10009],ifc[10009];
int d[110],n;

i64 dfs(int p,int r) {

    if(p==n) return r?fc[r]:0;
    if(vis[p][r]) return dp[p][r];
    vis[p][r]=1;
    i64 q=0;
    int i;
    for(i=0;i<=d[p];i++) q=(q+(dfs(p+1,r+i)*ifc[i])%md)%md;
    return dp[p][r]=q;
}


i64 pw(i64 b) {
    i64 r=1;
    int p=md-2;
    while(p) {
        if(p&1) r=(r*b)%md;
        b=(b*b)%md;
        p>>=1;
    }
    return r;
}


int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int i,I=1;
	fc[0]=ifc[0]=1;
	for(i=1;i<=10000;i++) {
	    fc[i]=(fc[i-1]*i)%md;
	    ifc[i]=pw(fc[i]);
	}
	while(cin>>n) {
	    for(i=0;i<n;i++) scanf("%d",&d[i]);
	    CLR(vis);
	    cout<<"Case "<<I<<": "<<dfs(0,0)<<'\n';
	    I++;
	}
	return 0;
}
