/*
USER: zobayer
TASK: NWERC10H
ALGO: heap
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

priority_queue< pii, vector< pii >, less< pii > > BID;
priority_queue< pii, vector< pii >, greater< pii > > ASK;

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, n, i, q, v, last;
	char buff[8], ord[8];
	pii A, B;
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		while(!BID.empty()) BID.pop();
		while(!ASK.empty()) ASK.pop();
		last = -1;
		while(n--) {
			scanf("%s %d %s %s %d", ord, &q, buff, buff, &v);
			if(ord[0]=='s') ASK.push(pii(v, q));
			else BID.push(pii(v, q));
			while(!ASK.empty() && !BID.empty() && BID.top().first >= ASK.top().first) {
				A = ASK.top(); ASK.pop();
				B = BID.top(); BID.pop();
				q = min(B.second, A.second);
				last = A.first;
				B.second -= q; if(B.second) BID.push(B);
				A.second -= q; if(A.second) ASK.push(A);
			}
			if(ASK.empty()) printf("- "); else printf("%d ", ASK.top().first);
			if(BID.empty()) printf("- "); else printf("%d ", BID.top().first);
			if(last == -1) printf("-\n"); else printf("%d\n", last);
		}
	}
	return 0;
}