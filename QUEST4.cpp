/*
USER: zobayer
TASK: QUEST4
ALGO: bipartite matching
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
const int MAX = 120;

typedef long long i64;
typedef unsigned long long u64;
typedef pair< int, int > pii;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (a > b ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }

vector < int > edges[MAX];
bool visited[MAX];
int Left[MAX], Right[MAX];

bool dfs(int u) {
	if(visited[u]) return false;
	visited[u] = true;
	int len = edges[u].size(), i, v;
	for(i=0; i<len; i++) {
		v = edges[u][i];
		if(Right[v]==-1) {
			Right[v] = u, Left[u] = v;
			return true;
		}
	}
	for(i=0; i<len; i++) {
		v = edges[u][i];
		if(dfs(Right[v])) {
			Right[v] = u, Left[u] = v;
			return true;
		}
	}
	return false;
}

int match() {
	SET(Left);
	SET(Right);
	int i, ret = 0;
	bool done;
	do {
		done = true;
		CLR(visited);
		for(i=0; i<MAX; i++) {
			if(Left[i]==-1 && dfs(i)) {
				done = false;
			}
		}
	} while(!done);
	for(i=0; i<MAX; i++) ret += (Left[i]!=-1);
	return ret;
}

int main() {
	int t, n, i, x, y;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i=0; i<MAX; i++) edges[i].clear();
		for(i=0; i<n; i++) {
			scanf("%d%d", &x, &y);
			edges[x].push_back(y);
		}
		printf("%d\n", match());
	}
	return 0;
}
