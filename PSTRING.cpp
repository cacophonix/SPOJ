/*
USER: zobayer
TASK: PSTRING
ALGO: dynamic programming
*/

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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
#include <limits>
#include <numeric>
#include <utility>
#include <valarray>
using namespace std;

#define DEBUG if(0)
#define PAUSE system("pause")
#define ALL(c) c.begin(), c.end()
#define PB(x) push_back(x)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define BIG(p) memset(p, 0x3f, sizeof(p))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) c.size()

typedef long long i64;
typedef unsigned long long u64;
typedef pair< int, int > pii;

template< class T > T _abs(const T &n) { return (n < 0 ? -n : n); }
template< class T > T _max(const T &a, const T &b) { return (a > b ? a : b); }
template< class T > T _min(const T &a, const T &b) { return (a < b ? a : b); }
template< class T > T gcd(const T a, const T b) { return (b ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(const T a, const T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inrange(const T &a, const T &b, const T &c) { return a<=b && b<=c; }
template< class T > T sq(const T &x) { return x * x; }

const double EPS = 1e-10;
const int INF = 0x3f3f3f3f;

const int XLEN = 10001, YLEN = 1001, MC = 256;
char X[XLEN], Y[YLEN];
int F[YLEN], prec[YLEN][MC], dp[YLEN], cp[YLEN];
bool P[MC];

int main() {
	int i, j, k, xlen, ylen, tmp;
	while(scanf("%s%s", X, Y)==2) {
		xlen = strlen(X), ylen = strlen(Y);
		CLR(F);
		for(i=2; i<ylen; i++) {
			for(j=F[i-1]; ; ) {
				if(Y[j]==Y[i-1]) {
					F[i] = j + 1;
					break;
				}
				else if(j > 0) j = F[j];
				else break;
			}
		}
		CLR(P);
		for(i=0; i<ylen; i++) P[Y[i]] = true;
		for(i=0; i<MC; i++) if(P[i]) {
			for(j=0; j<ylen; j++) {
				k = j, tmp = 0;
				while(1) {
					if(Y[k]==(char)i) {
						tmp = k + 1;
						break;
					}
					else if(k>0) k = F[k];
					else break;
				}
				prec[j][i] = tmp;
			}
		}
		CLR(dp);
		for(i=xlen-1; i>=0; i--) {
			for(j=0; j<=ylen; j++) {
				tmp = dp[j] + 1;
				if(prec[j][X[i]]!=ylen) tmp = min(tmp, dp[prec[j][X[i]]]);
				cp[j] = tmp;
			}
			for(j=0; j<=ylen; j++) dp[j] = cp[j];
		}
		printf("%d\n", dp[0]);
	}
	return 0;
}
