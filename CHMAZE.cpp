/*
USER: zobayer
TASK: CHMAZE
ALGO: breadth first search
*/

#include <cstdio>
#include <queue>
using namespace std;

typedef pair< int, int > pii;
typedef pair< int, pii > pip;
const int ROW = 25, COL = 25, PAT = 15;
char grid[PAT][ROW][COL];
int R, C, P, dist[PAT][ROW][COL];
int dr[5] = {0, 0, 0, 1,-1};
int dc[5] = {0, 1,-1, 0, 0};

int bfs(pip start) {
	int i, r1, r2, c1, c2, p1, p2;
	queue< pip > Q;
	p1 = start.first;
	r1 = start.second.first;
	c1 = start.second.second;
	if(r1==R-1 && c1==C-1) return 0;
	grid[p1][r1][c1] = '1';
	dist[p1][r1][c1] = 0;
	Q.push(start);
	while(!Q.empty()) {
		p1 = Q.front().first;
		r1 = Q.front().second.first;
		c1 = Q.front().second.second;
		Q.pop();
		for(i=0; i<5; i++) {
			p2 = (p1+1) % P;
			r2 = r1+dr[i];
			c2 = c1+dc[i];
			if(grid[p2][r2][c2]=='0') {
				grid[p2][r2][c2] = '1';
				dist[p2][r2][c2] = dist[p1][r1][c1]+1;
				if(r2==R-1 && c2==C-1) return dist[p2][r2][c2];
				Q.push(pip(p2, pii(r2, c2)));
			}
		}
	}
	return -1;
}

int main() {
	int k, i, d, cs = 1;
	//freopen("C:\\in.txt", "r", stdin);
	while(scanf("%d%d%d", &R, &C, &P)==3 && (R+C+P)) {
		for(k=0; k<P; k++)
			for(i=0; i<R; i++)
				scanf("%s", grid[k][i]);
		d = bfs(pip(0, pii(0, 0)));
		if(d>=0) printf("Case %d: Luke and Leia can escape in %d steps.\n", cs++, d);
		else printf("Case %d: Luke and Leia cannot escape.\n", cs++);
	}
	return 0;
}
