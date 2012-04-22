/*
USER: zobayer
TASK: STEAD
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

typedef long long i64;
typedef unsigned long long u64;
typedef pair< int, int > pii;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (a > b ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }

const int NCOWS = 1500;
const int NBARN = 30;

vector< int > edges[NCOWS];
int L[NCOWS], R[NCOWS];
bool visited[NCOWS];
int pref[NCOWS][NBARN], cap[NBARN];
int ncows, nbarn;

bool dfs(int u) {
	if(visited[u]) return false;
	visited[u] = true;
	int len = edges[u].size(), i, v;
	for(i=0; i<len; i++) {
		v = edges[u][i];
		if(R[v]==-1) {
			R[v] = u, L[u] = v;
			return true;
		}
	}
	for(i=0; i<len; i++) {
		v = edges[u][i];
		if(dfs(R[v])) {
			R[v] = u, L[u] = v;
			return true;
		}
	}
	return false;
}


bool match() {
	SET(L);
	SET(R);
	bool done;
	int i, ret = 0;
	do {
		done = true;
		CLR(visited);
		for(i=0; i<ncows; i++) {
			if(L[i]==-1 && dfs(i)) {
				done = false;
			}
		}
	} while(!done);
	for(i=0; i<ncows; i++) ret += (L[i]!=-1);
	return (ret == ncows);
}

bool isok(int rng) {
	int i, j, c, p, b, ii, jj, k;
	for(i=0; i<nbarn; i++) {
		j = i+rng-1;
		if(j>=nbarn) break;
		for(c=0; c<ncows; c++) {
			edges[c].clear();
			for(p=i; p<=j; p++) {
				b = pref[c][p] - 1;
				ii = (b? cap[b-1] : 0);
				jj = cap[b]-1;
				for(k=ii; k<=jj; k++) {
					edges[c].push_back(k);
				}
			}
		}
		if(match()) return true;
	}
	return false;
}

int main() {
	int i, j, l, r, m;
	scanf("%d %d", &ncows, &nbarn);
	for(i=0; i<ncows; i++)
		for(j=0; j<nbarn; j++)
			scanf("%d", &pref[i][j]);
	for(i=0; i<nbarn; i++) {
		scanf("%d", ?[i]);
		if(i) cap[i] += cap[i-1];
	}
	l = 1; r = nbarn;
	while(l <= r) {
		m = (l+r)>>1;
		if(isok(m)) r = m-1;
		else l = m+1;
	}
	printf("%d\n", r+1);
	return 0;
}
