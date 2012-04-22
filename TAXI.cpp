/*
USER: zobayer
TASK: TAXI
ALGO: bipartite matching
*/

#include <vector>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define point pair< int, int >
#define MAX 410

vector< int > edges[MAX];
point P[MAX], T[MAX];
int right[MAX], left[MAX], p, t;
bool vis[MAX];

bool dfs(int x) {
	if(vis[x]) return false;
	vis[x] = true;
	int len = edges[x].size(), i, v;
	for(i=0; i<len; i++) {
		v = edges[x][i];
		if(right[v]==-1) {
			right[v] = x, left[x] = v;
			return true;
		}
	}
	for(i=0; i<len; i++) {
		v = edges[x][i];
		if(dfs(right[v])) {
			right[v] = x, left[x] = v;
			return true;
		}
	}
	return false;
}

int match() {
	memset(right, -1, sizeof(right));
	memset(left, -1, sizeof(left));
	int ret = 0, i;
	bool done;
	do {
		done = true;
		memset(vis, 0, sizeof(vis));
		for(i=0; i<p; i++) {
			if(left[i]==-1 && dfs(i)) {
				done = false;
			}
		}
	} while(!done);
	for(i=0; i<p; i++) ret += (left[i]!=-1);
	return ret;
}

inline int dist(point a, point b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	int k, x, y, i, j, s, c;
	scanf("%d", &k);
	while(k--) {
		scanf("%d%d%d%d", &p, &t, &s, &c);
		for(i=0; i<p; i++) edges[i].clear();
		for(i=0; i<p; i++) {
			scanf("%d%d", &x, &y);
			P[i] = point(x, y);
		}
		for(i=0; i<t; i++) {
			scanf("%d%d", &x, &y);
			T[i] = point(x, y);
		}
		for(i=0; i<p; i++) {
			for(j=0; j<t; j++) {
				if(dist(P[i],T[j]) <= s*c/200) {
					edges[i].push_back(j);
				}
			}
		}
		printf("%d\n", match());
	}
	return 0;
}
