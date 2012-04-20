/*
USER: zobayer
TASK: QUEST5
ALGO: sorting
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
const int MAX = 10101;

typedef long long i64;
typedef unsigned long long u64;
typedef pair< int, int > pii;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (a > b ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }

struct bar {
	int x, y;
} b[MAX];

bool comp(const bar &a, const bar &b) {
	return (a.y < b.y);
}

int main() {
	int t, i, n, nail, last;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i=0; i<n; i++) {
			scanf("%d%d", &b[i].x, &b[i].y);
		}
		sort(b, b+n, comp);
		DEBUG for(i=0; i<n; i++) {
			printf("%d %d\n", b[i].x, b[i].y);
		}
		nail = 0;
		last = -1;
		for(i=0; i<n; i++) {
			if(b[i].x > last) {
				nail++;
				last = b[i].y;
			}
		}
		printf("%d\n", nail);
	}
	return 0;
}
