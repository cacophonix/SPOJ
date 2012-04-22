/*
USER: zobayer
TASK: PIZZALOC
ALGO: subset generation
*/

#include <cstdio>
#include <cstring>
using namespace std;

struct Loc { int x, y; } loc[20];
struct Sol { int x, y, p; } sol[100];

char used[100], take[20], deg[20], adj[20][100];

inline int sq(int n) { return n * n; }

int main() {
	int k, r, m, n, i, j, t, cnt, d, pep, mpep = 0;
	//freopen("C:\\in.txt", "r", stdin);
	scanf("%d%d%d", &k, &r, &m);
	for(i = 0; i < m; i++) scanf("%d%d", &loc[i].x, &loc[i].y);
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d%d%d", &sol[i].x, &sol[i].y, &sol[i].p);
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			if(sq(sol[j].x-loc[i].x)+sq(sol[j].y-loc[i].y) <= r*r)
				adj[i][deg[i]++] = j;
	for(i = (1<<k)-1, t = k; i < (1 << m); t += (i++ == (1 << t) - 1)) {
		for(j = cnt = 0; j < t; j++) {
			if(i & (1 << j)) take[cnt++] = j;
			if(cnt > k) break;
		}
		if(cnt != k) continue;
		memset(used, 0, sizeof(used));
		for(j = pep = 0; j < cnt; j++) {
			for(d = 0; d < deg[take[j]]; d++) {
				if(!used[adj[take[j]][d]]) {
					used[adj[take[j]][d]] = 1;
					pep += sol[adj[take[j]][d]].p;
				}
			}
		}
		if(pep > mpep) mpep = pep;
	}
	printf("%d\n", mpep);
	return 0;
}