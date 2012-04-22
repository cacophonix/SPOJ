/*
USER: zobayer
TASK: ANARC08G
ALGO: ad-hoc
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

#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
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

int mat[1000][1000];
int rsum[1000], csum[1000];

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int n, i, j, sum, diff, cs = 1;
	while(scanf("%d", &n)==1 && n) {
		for(i = sum = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				scanf("%d", &mat[i][j]);
				sum += mat[i][j];
			}
		}
		for(i = 0; i < n; i++) {
			for(rsum[i] = csum[i] = j = 0; j < n; j++) {
				rsum[i] += mat[i][j];
				csum[i] += mat[j][i];
			}
		}
		for(i = diff = 0; i < n; i++)
			if(rsum[i] > csum[i])
				diff += rsum[i] - csum[i];
		printf("%d. %d %d\n", cs++, sum, diff);
	}
	return 0;
}
