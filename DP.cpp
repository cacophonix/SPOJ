/*
USER: zobayer
TASK: DP
ALGO: breadth first search
*/

#include <cstdio>
#include <cstring>
#include <queue>
#include <cctype>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

char grid[50][51];
int d[50][50], R, C;
int dr[] = {-1, 0, 0, 1};
int dc[] = {0, -1, 1, 0};
vector< int > dist;

bool inside(int r, int c) {
	return (0<=r && r<R && 0<=c && c<C);
}

void find(int &r, int &c) {
	int i, j;
	for(i = 0; i < R; i++) for(j = 0; j < C; j++)
		if(grid[i][j]=='X') { r = i, c = j; return; }
	r = j = -1;
}

void bfs(int r, int c) {
	int i, ur, uc, vr, vc, cc;
	queue< int > Q;
	d[r][c] = 0;
	Q.push(r);
	Q.push(c);
	while(!Q.empty()) {
		ur = Q.front(); Q.pop();
		uc = Q.front(); Q.pop();
		for(i = 0; i < 4; i++) {
			vr = ur + dr[i];
			vc = uc + dc[i];
			if(inside(vr, vc)) {
				if(!isdigit(grid[vr][vc]) || !isdigit(grid[ur][uc])) cc = 2;
				else if(abs(grid[ur][uc] - grid[vr][vc])==0) cc = 1;
				else if(abs(grid[ur][uc] - grid[vr][vc])==1) cc = 3;
				else continue;
				if(d[ur][uc] + cc < d[vr][vc]) {
					d[vr][vc] = cc + d[ur][uc];
					Q.push(vr); Q.push(vc);
				}
			}
		}
	}
}

bool calcDist() {
	int i, j;
	dist.clear();
	for(i = 0; i < R; i++) for(j = 0; j < C; j++) if(grid[i][j]=='$') {
		if(d[i][j] == INF) return false;
		dist.push_back(d[i][j]);
	}
	return true;
}

int main() {
	int test, r, c, i, j, k, sz, best, total[2];
	vector< int > F[2];
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d", &R, &C);
		for(i = 0; i < R; i++) scanf("%s", grid[i]);
		memset(d, 0x3f, sizeof d);
		find(r, c);
		bfs(r, c);
		if(!calcDist()) puts("-1");
		else {
			sz = dist.size();
			sort(dist.begin(), dist.end());
			best = INF;
			for(i = 0; i < (1 << sz); i++) {
				F[0].clear(); F[1].clear();
				total[0] = total[1] = 0;
				for(j = 0; j < sz; j++) {
					F[(i & (1<<j))!=0].push_back(dist[j]);
				}
				for(j = 0; j < 2; j++) {
					for(k = 0; k < F[j].size(); k++) {
						total[j] += (F[j][k]<<1);
					}
					if(k) total[j] -= F[j][k-1];
				}
				best = min(best, max(total[0], total[1]));
			}
			printf("%d\n", best);
		}
	}
	return 0;
}

