/*
USER: zobayer
TASK: SPIRALGR
ALGO: bfs
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

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

const int MAX = 128;

int grid[MAX][MAX];
int isp[MAX][MAX];
map< int, pii > M;

bool isprime(int n) {
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;
    int rt = (int)sqrt(n);
    for(int i = 3; i <= rt; i+=2) {
        if(n % i == 0) return false;
    }
    return true;
}

void genGrid(int n) {
    int k = n, p = n * n, i, r = 0, c = 0, t = 0;
    while(k > 0) {
        for(i = 0; i < k; i++) grid[r][c++] = p--, M[p+1] = pii(r, c-1), isp[r][c-1] = isprime(p+1);
        c--, r++;
        if((t & 1) == 0) k--; t++; if(k <= 0) break;
        for(i = 0; i < k; i++) grid[r++][c] = p--, M[p+1] = pii(r-1, c), isp[r-1][c] = isprime(p+1);
        r--, c--;
        if((t & 1) == 0) k--; t++; if(k <= 0) break;
        for(i = 0; i < k; i++) grid[r][c--] = p--, M[p+1] = pii(r, c+1), isp[r][c+1] = isprime(p+1);
        c++, r--;
        if((t & 1) == 0) k--; t++; if(k <= 0) break;
        for(i = 0; i < k; i++) grid[r--][c] = p--, M[p+1] = pii(r+1, c), isp[r+1][c] = isprime(p+1);
        r++, c++;
        if((t & 1) == 0) k--; t++; if(k <= 0) break;
    }
}

int d[MAX][MAX];
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool valid(pii x) {
    int r = x.ff, c = x.ss;
    return 0 <= x.ff && x.ff < MAX && 0 <= x.ss && x.ss < MAX;
}

int dist(pii st, pii en) {
    queue< pii > Q;
    Q.push(st);
    MEM(d, 0x7f);
    d[st.ff][st.ss] = 0;
    while(!Q.empty()) {
        pii u = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++) {
            pii v = pii(u.ff + dr[i], u.ss + dc[i]);
            if(valid(v) && isp[v.ff][v.ss] == false && d[v.ff][v.ss] > d[u.ff][u.ss] + 1) {
                d[v.ff][v.ss] = d[u.ff][u.ss] + 1;
                Q.push(v);
                if(v == en) return d[v.ff][v.ss];
            }
        }
    }
    return d[en.ff][en.ss];
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int a, b, cs = 1, dt;
	pii ap, bp;
	genGrid(MAX);
	while(scanf("%d %d", &a, &b) == 2) {
	    ap = M[a];
	    bp = M[b];
	    dt = dist(ap, bp);
	    if(dt == INF) printf("Case %d: impossible\n", cs++);
	    else printf("Case %d: %d\n", cs++, dt);
	}
	return 0;
}
