/*
USER: zobayer
TASK: BWHEELER
ALGO: sorting
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

const int MAX = 1024;

char sorted[MAX], str[MAX], num[8];
int cnt[26], next[MAX];

void countingSort(char *p, char *s, int &len) {
	int i; len = 0; CLR(cnt);
	for(i = 0; p[i]>='a'; i++) cnt[p[i]-'a']++;
	for(i = 0; i < 26; i++)
		while(cnt[i]--)
			s[len++] = i + 'a';
	s[len] = 0;
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int k, len, i, j;
	while(k=atoi(fgets(num, 8, stdin))) {
		fgets(str, MAX, stdin);
		countingSort(str, sorted, len);
		for(i = 0; i < len; i++) {
			if(!i || sorted[i]!=sorted[i-1]) j = 0;
			else j++;
			while(sorted[i]!=str[j]) j++;
			next[i] = j;
		}
		for(i = 0, k = next[k-1]; i < len; i++, k = next[k]) putchar(str[k]);
		putchar('\n');
	}
	//system("pause");
	return 0;
}
