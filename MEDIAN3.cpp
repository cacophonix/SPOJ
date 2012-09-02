/*
USER: zobayer
TASK: MEDIAN3
ALGO: segment tree
*/

//#pragma warning (disable: 4786)
//#pragma comment (linker, "/STACK:0x800000")
//#define _CRT_SECURE_NO_WARNINGS 1

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
const int MAX = 1 << 17;
const int TMAX = 1 << 18;

int a[MAX];
vector< int > T[TMAX];

void clear(int node, int i, int j) {
    T[node].clear();
    if(i == j) return;
    int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1;
    clear(lt, i, mid);
    clear(rt, mid + 1, j);
}

void init(int node, int i, int j) {
    if(i == j) {
        T[node].PB(a[i]);
        return;
    }
    int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1;
    init(lt, i, mid);
    init(rt, mid + 1, j);
    int p = 0, q = 0;
    while(p < T[lt].size() && q < T[rt].size()) {
        if(T[lt][p] < T[rt][q]) T[node].PB(T[lt][p]), p++;
        else T[node].PB(T[rt][q]), q++;
    }
    while(p < T[lt].size()) {
        T[node].PB(T[lt][p]);
        p++;
    }
    while(q < T[rt].size()) {
        T[node].PB(T[rt][q]);
        q++;
    }
}

int query(int node, int i, int j, int ri, int rj, int p) {
    if(i == ri && j == rj) {
        int x = upper_bound(ALL(T[node]), p) - T[node].begin();
        return x;
    }
    int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1;
    if(rj <= mid) return query(lt, i, mid, ri, rj, p);
    else if(ri > mid) return query(rt, mid + 1, j, ri, rj, p);
    return query(lt, i, mid, ri, mid, p) + query(rt, mid + 1, j, mid + 1, rj, p);
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int n, q, i, j, r, lo, hi, mid, res, cs = 1;
	while(scanf("%d", &n) == 1) {
	    for(i = 0; i < n; i++) scanf("%d", &a[i]);
	    clear(1, 0, n-1);
	    init(1, 0, n-1);
	    scanf("%d", &q);
	    printf("Case %d:\n", cs++);
	    while(q--) {
	        scanf("%d %d", &i, &j);
	        i--, j--;
	        lo = 0, hi = n - 1;
	        while(lo <= hi) {
	            mid = (lo + hi) >> 1;
	            r = query(1, 0, n-1, i, j, T[1][mid]);
	            if(r >= (j - i + 3) / 2) {
	                res = T[1][mid];
	                hi = mid - 1;
	            }
	            else {
	                lo = mid + 1;
	            }
	        }
	        printf("%d\n", res);
	    }
	}
	return 0;
}
