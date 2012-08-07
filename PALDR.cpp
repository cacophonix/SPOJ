/*
USER: zobayer
TASK: PALDR
ALGO: hashing
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
#define i64 unsigned long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const int MAX = 1000009;

char str[MAX];

void rtrim(char *s, int &len) {
	while(len > 0) {
		if(s[len-1] < 33) len--;
		else break;
	}
	s[len] = 0;
}

bool isreallypalin(int p, int q) {
	for(int i = p, j = q; i <= j; i++, j--) {
		if(str[i] != str[j]) return false;
	}
	return true;
}

int main() {
	//READ("test.in");
	//WRITE("out.txt");
	int test, cs, len, i, j;
	i64 h, hr, p, h1, hr1, p1;
	test = atoi(gets(str));
	for(cs = 1; cs <= test; cs++) {
		gets(str);
		len = strlen(str);
		rtrim(str, len);
		if(len == 0) puts("YES");
		else if(len & 1) puts("NO");
		else {
			for(i = 0; i < len; i++) {
				h = hr = 0; p = 1;
				h1 = hr1 = 0; p1 = 1;
				for(j = i; j < len; j++) {
					h = (31 * h + str[j]); // forward hash
					hr = (hr + p * str[j]); // reverse hash
					p = (p * 31);

					h1 = (37 * h1 + str[j]);
					hr1 = (hr1 + p1 * str[j]);
					p1 = (p1 * 37);
					if(((j-i+1)&1) == 0 && h == hr && h1 == hr1) {
						i = j;
						break;
					}
				}
				if(j == len) break;
			}
			if(i == len) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
