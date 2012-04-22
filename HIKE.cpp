/*
USER: zobayer
TASK: HIKE
ALGO: breadth first search
*/

#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 55, INF = 0x7f7f7f7f;
int d[MAX][MAX][MAX];
char grid[MAX][MAX][2];

int main() {
	int n, a, b, c, i, j;
	while(scanf("%d", &n)==1 && n) {
		scanf("%d%d%d", &a, &b, &c);
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				scanf("%s", grid[i][j]);
		queue< int > Q;
		Q.push(a), Q.push(b), Q.push(c);
		memset(d, 0x7f, sizeof d);
		d[a][b][c] = 0;
		while(!Q.empty()) {
			a = Q.front(); Q.pop();
			b = Q.front(); Q.pop();
			c = Q.front(); Q.pop();
			for(i=1; i<=n; i++) {
				if(grid[a][i][0]==grid[b][c][0] && d[i][b][c] > d[a][b][c] + 1) {
					Q.push(i), Q.push(b), Q.push(c);
					d[i][b][c] = d[a][b][c] + 1;
				}
				if(grid[b][i][0]==grid[c][a][0] && d[a][i][c] > d[a][b][c] + 1) {
					Q.push(a), Q.push(i), Q.push(c);
					d[a][i][c] = d[a][b][c] + 1;
				}
				if(grid[c][i][0]==grid[a][b][0] && d[a][b][i] > d[a][b][c] + 1) {
					Q.push(a), Q.push(b), Q.push(i);
					d[a][b][i] = d[a][b][c] + 1;
				}
			}
		}
		for(i=1, j=INF; i<=n; i++) j = min(j, d[i][i][i]);
		if(j==INF) printf("impossible\n");
		else printf("%d\n", j);
	}
	return 0;
}
