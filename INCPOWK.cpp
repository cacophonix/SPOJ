/*
USER: zobayer
TASK: INCPOWK
ALGO: math
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
#define ALL(x) x.begin(), x.end()
#define PB(v) push_back(v)
#define SET(x) memset(x, -1, sizeof(x))
#define CLR(x) memset(x, 0, sizeof(x))
#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)
#define SZ(x) x.size()

const double EPS = 1e-10;
const int INF = 1<<28;
const int MAX = 665;

typedef long long i64;
typedef unsigned long long u64;
typedef pair< int, int > pii;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (a > b ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T _gcd(T a, T b) { return (b ? _gcd(b, a%b) : a); }
template< class T > T _lcm(T a, T b) { return a / _gcd(a, b) * b; }

struct bignum {
	char n[222];
	int len;
	bignum() { n[0]='0', n[1]=0, len=1; }
	bignum(char *s) { int i; for(i=0; s[i]; i++) n[i]=s[i]; n[len=i]=0; }
	void shr1() {
		int i, a, mod, div, k, f, bk;
		for(i=k=mod=f=bk=0; i<len; i++) {
			a = mod * 10 + n[i]-'0';
			div = a >> 1;
			mod = a & 1;
			if(div) f = 1;
			if(f) n[k++] = div+'0';
		}
		if(k==0) n[k++] = '0';
		n[len=k] = 0;
	}
	bool and1() {
		return (n[len-1]-'0') & 1;
	}
	bool is0() {
		return (len==1 && n[0]=='0');
	}
};

char bit[777];
int bitlen;
char table[10][MAX][MAX];

void mul(char *d, char *s, int n) {
	int i, c, a;
	for(i=c=0; s[i]; i++) {
		a = s[i] - '0';
		d[i] = (a * n + c) % 10 + '0';
		c = (a * n + c) / 10;
	}
	while(c) {
		d[i++] = c % 10 + '0';
		c /= 10;
	}
}

void preCalc() {
	int i, j;
	for(i=3; i<10; i++) {
		table[i][0][0] = '1';
		for(j=1; j<MAX; j++) {
			mul(table[i][j], table[i][j-1], i);
		}
	}
}

char res[MAX<<1];

void add(char *c, char *a, char *b, int &rl) {
	int i, j, k, carry, t;
	for(i=j=k=carry=0; a[i] && b[i]; i++, j++, k++) {
		t = a[i]+b[i]+carry-96;
		c[k] = t % 10 + 48;
		carry = t / 10;
	}
	if(a[i]) for(; a[i]; i++, k++) {
		t = a[i]+carry-48;
		c[k] = t % 10 + 48;
		carry = t / 10;
	}
	if(b[j]) for(; b[j]; j++, k++) {
		t = b[j]+carry-48;
		c[k] = t % 10 + 48;
		carry = t / 10;
	}
	if(carry) c[k++] = carry+48;
	c[rl = k] = 0;
}

int main() {
	bignum b;
	int t, k, i, len;
	preCalc();
	scanf("%d", &t);
	while(t--) {
		scanf("%d %s", &k, b.n);
		b.len = strlen(b.n);
		len = bitlen = 0;
		while(!b.is0()) {
			bit[bitlen++] = b.and1();
			b.shr1();
		}
		res[len++] = '0', res[len] = 0;
		for(i=0; i<bitlen; i++) if(bit[i]) {
			add(res, res, table[k][i], len);
		}
		reverse(res, res+len);
		puts(res);
	}
	return 0;
}
