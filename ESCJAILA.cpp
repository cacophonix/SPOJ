/*
USER: zobayer
TASK: ESCJAILA
ALGO: breadth first search
*/

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 101;

char grid[MAX][MAX];
int d[MAX][MAX][3], R, C;
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};

void findstart(int &r, int &c) {
	int i, j;
	r = c = -1;
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			if(grid[i][j]=='H') {
				r = i, c = j;
				return;
			}
		}
	}
}

bool inside(int a, int b, int c) {
	return (a <= b && b <= c);
}

int bfs(int r, int c) {
	if(r==R-1 || r==0 || c==0 || c==C-1) return 0;
	int i, rr, cc, fl, now;
	queue< int > Q;
	Q.push(r), Q.push(c), Q.push(0);
	d[r][c][0] = 0;
	while(!Q.empty()) {
		r = Q.front(); Q.pop();
		c = Q.front(); Q.pop();
		fl = Q.front(); Q.pop();
		for(i = 0; i < 4; i++) {
			rr = r + dr[i];
			cc = c + dc[i];
			if(inside(0,rr,R-1) && inside(0,cc,C-1) && grid[rr][cc] != 'W') {
				if(fl != 1 && grid[rr][cc]=='D') continue;
				if(rr==0 || rr==R-1 || cc==0 || cc==C-1) return d[r][c][fl] + 1;
				if(grid[rr][cc] == 'O') now = 1;
				else if(grid[rr][cc] == 'C') now = 2;
				else now = fl;
				if(d[rr][cc][now] > d[r][c][fl] + 1) {
					Q.push(rr), Q.push(cc), Q.push(now);
					d[rr][cc][now] = d[r][c][fl] + 1;
				}
			}
		}
	}
	return -2;
}

int main() {
	int i, r, c, ret;
	while(scanf("%d%d", &R, &C)==2 && (R>0 && C>0)) {
		for(i = 0; i < R; i++) scanf("%s", grid[i]);
		memset(d, 0x7f, sizeof(d));
		findstart(r, c);
		printf("%d\n", bfs(r, c) + 1);
	}
	return 0;
}