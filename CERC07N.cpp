/*
USER: zobayer
TASK: CERC07N
ALGO: ad-hoc
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

int from(char *val, int base) {
	int i, ret = 0;
	for(i=0; val[i]; i++) {
		ret += val[i]-'0';
		ret *= base;
	}
	ret /= base;
	return ret;
}

string to(char *valstr, int base) {
	int val, tmp;
	string ret = "";
	sscanf(valstr, "%d", &val);
	while(val) {
		tmp = val % base;
		val /= base;
		if(tmp < 0) {
			tmp += (-base);
			val++;
		}
		ret.push_back(tmp + '0');
	}
	if(ret.length()==0) ret.push_back('0');
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	char sbase[40], value[40];
	int base;
	while(scanf("%s", sbase)==1) {
		if(sbase[0]=='e') break;
		scanf("%s", value);
		if(sbase[0]=='f') {
			sscanf(&sbase[4], "%d", &base);
			printf("%d\n", from(value, base));
		}
		else if(sbase[0]=='t') {
			sscanf(&sbase[2], "%d", &base);
			printf("%s\n", to(value, base).c_str());
		}
	}
	return 0;
}
