/*
USER: zobayer
TASK: CRYPTON
ALGO: math
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

const double EPS = 1e-9;
const double BIG = 1e15;
const int NIL = 0;
const int INF = 0x3f3f3f3f;

const int MAX = 1000000;
const int LMT = 1000;
const int LEN = 78500;

int flag[MAX>>6];
int primes[LEN], total;

#define chk(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define bad(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
	int i, j, k;
	primes[0] = 2, total = 1;
	for(i = 3; i < MAX; i+=2) {
		if(chk(i)) continue;
		primes[total++] = i;
		if(i >= LMT) continue;
		for(j=i*i, k=i<<1; j < MAX; j+=k) bad(j);
	}
	primes[total] = INF;
}

int mod(char *n, int d) {
	int i, mod;
	for(i = mod = 0; n[i]; i++)
		mod = (mod * 10 + n[i] - '0') % d;
	return mod;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	sieve();
	char num1[128];
	int N, L, i;
	while(scanf("%s%d", num1, &L)==2 && L) {
		for(i = 0; primes[i] < L; i++)
			if(!mod(num1, primes[i]))
				break;
		if(primes[i] >= L) printf("GOOD\n");
		else printf("BAD %d\n", primes[i]);
	}
	//system("pause");
	return 0;
}
