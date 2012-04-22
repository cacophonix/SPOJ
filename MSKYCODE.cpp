/*
USER: zobayer
TASK: MSKYCODE
ALGO: inclusion exclusion
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

#define UB(s, e, x) upper_bound(s, e, x)
#define LB(s, e, x) lower_bound(s, e, x)
#define NPER(s, e) next_permutation(s, e)
#define PPER(s, e) prev_permutation(s, e)
#define REV(s, e) reverse(s, e);
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define PAUSE system("pause")
#define shl(x, n) ((x)<<(n))
#define shr(x, n) ((x)>>(n))
#define all(c) c.begin(), c.end()
#define sz(c) c.size()
#define pb(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define fs "%lld"
#define debug if(0)

const double EPS = 1e-9;
const double BIG = 1e19;
const int INF = 0x7f7f7f7f;
const int MAX = 10000;
const int LEN = 1230;

int primes[LEN], total;
int flag[(MAX+64)>>6];
int cnt[MAX+1], maxval;
i64 nc4[MAX+1];

#define cp(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define sp(x) (flag[x>>6]|=(1<<((x>>1)&31)))

void sieve() {
	int i, j, k;
	primes[0] = 2, total = 1;
	for(i = 3; i < MAX; i+=2) {
		if(!cp(i)) {
			primes[total++] = i;
			k = i << 1;
			for(j = i * i; j < MAX; j += k) sp(j);
		}
	}
}

void init() {
	nc4[4] = 1;
	for(int i = 5; i <= MAX; i++) nc4[i] = (nc4[i-1]*i)/(i-4);
}

i64 solve(int num, int idx) {
	i64 res;
	int i, present = 0, next;
	for(i = num; i <= maxval; i += num) present += cnt[i];
	res = nc4[present];
	if(present >= 4) {
		for(i = idx; i < total; i++) {
			next = num * primes[i];
			if(next > (maxval >> 2)) break;
			res -= solve(next, i + 1);
		}
	}
	return res;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int n, a, i;
	sieve();
	init();
	while(scanf("%d", &n)==1) {
		CLR(cnt);
		maxval = 0;
		for(i = 0; i < n; i++) {
			scanf("%d", &a);
			setmax(maxval, a);
			cnt[a]++;
		}
		printf("%lld\n", solve(1, 0));
	}
	return 0;
}
