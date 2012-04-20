/*
USER: zobayer
TASK: SHOP
ALGO: dijkstra
*/

#include <cstdio>
#include <queue>
#include <cstring>
#include <cctype>
using namespace std;

#define MAX 30
#define cell pair< int, int >
#define edge pair< int, cell >

char grid[MAX][MAX];
cell dir[4] = {cell(0,1), cell(1,0), cell(0,-1), cell(-1,0)};
int d[MAX][MAX], R, C;

bool isValid(cell u) {
	int i = u.first, j = u.second;
	return (i>=0 && j>=0 && i<R && j<C);
}

int dijkstra(cell start, cell dest) {
	if(!isValid(start) || !isValid(dest)) return -1;
	priority_queue< edge, vector< edge >, greater< edge > > Q;
	int we, ui, uj, vi, vj;
	Q.push(edge(0,start));
	grid[start.first][start.second] = '0';
	memset(d, 64, sizeof(d));
	d[start.first][start.second] = 0;
	while(!Q.empty()) {
		ui = Q.top().second.first;
		uj = Q.top().second.second;
		Q.pop();
		for(int i=0; i<4; i++) {
			vi = ui + dir[i].first;
			vj = uj + dir[i].second;
			if(isValid(cell(vi,vj)) && grid[vi][vj]!='X') {
				if(grid[vi][vj]=='D') we = 0;
				else we = grid[vi][vj] - '0';
				if(d[ui][uj]+we < d[vi][vj]) {
					d[vi][vj] = d[ui][uj] + we;
					Q.push(edge(d[vi][vj], cell(vi,vj)));
				}
			}
		}
		grid[ui][uj] = 'X';
		if(ui==dest.first && uj==dest.second) return d[ui][uj];
	}
	return -1;
}

cell findStart() {
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			if(grid[i][j]=='S')
				return cell(i,j);
	return cell(-1,-1);
}

cell findDest() {
	for(int i=R-1; i>=0; i--)
		for(int j=0; j<C; j++)
			if(grid[i][j]=='D')
				return cell(i,j);
	return cell(-1,-1);
}

int main() {
	while(scanf("%d%d", &C, &R)==2 && (R||C)) {
		for(int i=0; i<R; i++) scanf("%s", grid[i]);
		printf("%d\n", dijkstra(findStart(), findDest()));
	}
	return 0;
}
