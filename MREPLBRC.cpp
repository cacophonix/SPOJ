/*
USER: zobayer
TASK: MREPLBRC
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
#define md 100000

char ln[300];

i64 dp[211][211];
bool vis[211][211],f;


bool chk1(int i,int j) {
	if(ln[i]=='(' && ln[j]==')') return 1;
	if(ln[i]=='?' && ln[j]==')') return 1;
	if(ln[i]=='(' && ln[j]=='?') return 1;

	
	if(ln[i]=='{' && ln[j]=='}') return 1;
	if(ln[i]=='?' && ln[j]=='}') return 1;
	if(ln[i]=='{' && ln[j]=='?') return 1;

	
	if(ln[i]=='[' && ln[j]==']') return 1;
	if(ln[i]=='?' && ln[j]==']') return 1;
	if(ln[i]=='[' && ln[j]=='?') return 1;

	return false;
}


i64 dfs(int st,int fn) {
	if(st>fn) return 1;
	if(vis[st][fn]) return dp[st][fn];
	vis[st][fn]=1;
	i64 r=0;
	int i;
	for(i=st+1;i<=fn;i+=2) if(chk1(st,i)) {
		r=(r+dfs(st+1,i-1)*dfs(i+1,fn));
		if(r>md) {
			f=1;
			r%=md;
		}
	}
	else if(ln[st]=='?' && ln[i]=='?') {
		r=(r+dfs(st+1,i-1)*dfs(i+1,fn)*3);
		if(r>md) {
			f=1;
			r%=md;
		}
	}
	return dp[st][fn]=r;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int n;
	scanf("%d %s",&n,ln);
	
	CLR(vis);
	i64 r=dfs(0,n-1);
	printf(f?"%05d\n":"%d\n",r);
	
	return 0;
}
