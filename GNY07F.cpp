/*
USER: zobayer
TASK: GNY07F
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

#define SET(x) memset(x, -1, sizeof(x))
#define CLR(x) memset(x, 0, sizeof(x))
#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)

const double EPS = 1e-10;
const int INF = 1<<28;

typedef long long i64;
typedef unsigned long long u64;
typedef pair< int, int > pii;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (a > b ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }

int main() {
	char str[200];
	int t = atoi(gets(str)), i, n, x, m;
	for(x=1; x<=t; x++) {
		gets(str);
		for(i=n=m=0; str[i]; i++) {
			if(str[i]=='[') n++;
			else if(str[i]==']') n--;
			if(n > m) m = n;
		}
		printf("%d %d\n", x, (1<<m));
	}
	return 0;
}
