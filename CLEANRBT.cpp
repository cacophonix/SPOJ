/*
USER: zobayer
TASK: CLEANRBT
LANG: breadth first search
*/

#include <cstdio>
#include <queue>
#include <cctype>
#include <algorithm>
using namespace std;

const int dr[4] = {-1, 0, 0, 1}, dc[4] = { 0,-1, 1, 0};
const int MAX = 20, STATE = 1<<10, INF = 0x3f3f3f3f;
int dist[STATE][MAX][MAX], R, C, tot;
char grid[MAX][MAX+5];

int bfs(int ui, int uj) {
	int i, um, vi, vj, vm, mn = INF;
	queue< int > Q;
	dist[um=0][ui][uj] = 0;
	Q.push(ui), Q.push(uj), Q.push(um);
	while(!Q.empty()) {
		ui = Q.front(); Q.pop();
		uj = Q.front(); Q.pop();
		um = Q.front(); Q.pop();
		for(i=0; i<4; i++) {
			vi = ui + dr[i], vj = uj + dc[i], vm = um;
			if(vi>=0 && vi<R && vj>=0 && vj<C && grid[vi][vj]!='x') {
				if(isupper(grid[vi][vj])) vm |= 1<<(grid[vi][vj]-'A');
				if(dist[vm][vi][vj] > dist[um][ui][uj]+1) {
					dist[vm][vi][vj] = dist[um][ui][uj] + 1;
					if(vm==(1<<tot)-1) mn = min(mn, dist[vm][vi][vj]);
					Q.push(vi), Q.push(vj), Q.push(vm);
				}
			}
		}
	}
	return ((mn < INF) ? mn : -1);
}

int main() {
	int i, j, k, si, sj;
	//freopen("C:\\in.txt", "r", stdin);
	while(scanf("%d%d", &C, &R)==2 &&(R+C)) {
		for(i=tot=0; i<R; i++) {
			scanf("%s", grid[i]);
			for(j=0; j<C; j++) {
				if(grid[i][j]=='o') si = i, sj = j;
				else if(grid[i][j]=='*') grid[i][j] = 'A' + tot++;
			}
		}
		for(k=0; k<(1<<tot); k++)
			for(i=0; i<R; i++)
				for(j=0; j<C; j++)
					dist[k][i][j] = INF;
		printf("%d\n", bfs(si, sj));
	}
	return 0;
}
