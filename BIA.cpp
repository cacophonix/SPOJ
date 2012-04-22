/*
USER: zobayer
TASK: BIA
ALGO: lenguar tarjan
*/

#include <cstdio>
#include <set>
#include <vector>
using namespace std;

#define MAX 5005
#define pb(x) push_back(x)

vector<int> adj[MAX], pred[MAX], bucket[MAX];
bool vi[MAX];
int n, cnt, num[MAX], par[MAX], ancestor[MAX], best[MAX], semi[MAX], idom[MAX], rnum[MAX];

void dfs(int x,int p) {
	vi[x] = 1;
	num[x] = cnt++;
	rnum[cnt - 1] = x;
	par[num[x]] = num[p];
	int sz = adj[x].size(), i, y;
	for(i = 0; i < sz; i++){
		y = adj[x][i];
		if(!vi[y]) dfs(y, x);
	}
}

void compress(int x) {
	int a = ancestor[x];
	if(ancestor[a] == 0) return;
	compress(a);
	if(semi[best[x]] > semi[best[a]]) best[x] = best[a];
	ancestor[x] = ancestor[a];
}

int eval(int x) {
	if(ancestor[x] == 0) return x;
	compress(x);
	return best[x];
}

int main() {
	int i, x, y, m, j, p;
	while(scanf("%d %d", &n, &m)==2) {
		for(i = 1; i <= n; i++) {
			adj[i].clear(), pred[i].clear(), bucket[i].clear();
			ancestor[i] = idom[i] = vi[i] = 0;
			semi[i] = best[i] = i;
		}
		for(i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			adj[x].pb(y);
			pred[y].pb(x);
		}
		cnt = 1, num[0] = 0;
		dfs(1, 0);
		set<int> s;
		set<int>::iterator it;
		for(i = n; i > 1; i--) {
			p = par[i];
			int sz = pred[rnum[i]].size();
			for(j = 0; j < sz; j++){
				x = num[pred[rnum[i]][j]];
				y = eval(x);
				if(semi[i] > semi[y]) semi[i] = semi[y];
			}
			bucket[semi[i]].pb(i);
			ancestor[i] = p;
			sz = bucket[p].size();
			for(j = 0; j < sz; j++) {
				x = bucket[p][j];
				y = eval(x);
				if(semi[y] < p) idom[x] = y;
				else idom[x] = p;
			}
		}
		s.insert(1);
		for(i = 2;i <= n;i++) {
			if(idom[i] != semi[i]) idom[i] = idom[idom[i]];
			s.insert(rnum[idom[i]]);
		}
		it = s.begin();
		printf("%d\n%d", s.size(), *it);
		for(it++; it != s.end(); it++) printf(" %d", *it);
		puts("");
	}
	return 0;
}
