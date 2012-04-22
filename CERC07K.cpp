/*
USER: zobayer
TASK: CERC07K
ALGO: breadth first search
*/

#include <cstdio>
#include <queue>
#include <cctype>
using namespace std;

typedef pair< int, int > pii;
typedef pair< pii, int > ppi;
const int MAX = 101;
char grid[MAX][MAX];
int d[MAX][MAX][16], R, C;
int dr[4] = {0, 0, 1,-1};
int dc[4] = {1,-1, 0, 0};

inline bool ingrid(const pii &p) {
	return (p.first>=0 && p.first<R && p.second>=0 && p.second<C);
};

int bfs(const pii &s) {
	pii u, v;
	int umask, vmask, i;
	queue< ppi > Q;
	Q.push(ppi(s,0));
	d[s.first][s.second][0] = 0;
	while(!Q.empty()) {
		u = Q.front().first;
		umask = Q.front().second;
		Q.pop();
		for(i=0; i<4; i++) {
			v = pii(u.first+dr[i], u.second+dc[i]);
			if(ingrid(v) && grid[v.first][v.second]!='#') {
				if(grid[v.first][v.second]=='X') return d[u.first][u.second][umask]+1;
				if(d[v.first][v.second][umask]==-1) {
					vmask = umask;
					if(islower(grid[v.first][v.second])) {
						switch(grid[v.first][v.second]) {
							case 'b': vmask |= 0x1; break;
							case 'y': vmask |= 0x2; break;
							case 'r': vmask |= 0x4; break;
							case 'g': vmask |= 0x8; break;
						}
						Q.push(ppi(v, vmask));
						d[v.first][v.second][umask] = d[u.first][u.second][umask]+1;
						d[v.first][v.second][vmask] = d[v.first][v.second][umask];
					}
					else if(isupper(grid[v.first][v.second])) {
						switch(grid[v.first][v.second]) {
							case 'B': if(umask & 0x1) Q.push(ppi(v, umask)); break;
							case 'Y': if(umask & 0x2) Q.push(ppi(v, umask)); break;
							case 'R': if(umask & 0x4) Q.push(ppi(v, umask)); break;
							case 'G': if(umask & 0x8) Q.push(ppi(v, umask)); break;
						}
						d[v.first][v.second][umask] = d[u.first][u.second][umask]+1;
					}
					else {
						Q.push(ppi(v, umask));
						d[v.first][v.second][umask] = d[u.first][u.second][umask]+1;
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	int i, j, k, dis;
	pii start;
	//freopen("C:\\in.txt", "r", stdin);
	while(scanf("%d%d", &R, &C)==2) {
		if(!R && !C) break;
		for(i=0; i<R; i++) {
			scanf("%s", grid[i]);
			for(j=0; j<C; j++) {
				if(grid[i][j]=='*') start = pii(i, j);
				for(k=0; k<16; k++) d[i][j][k] = -1;
			}
		}
		dis = bfs(start);
		if(dis<0) printf("The poor student is trapped!\n");
		else printf("Escape possible in %d steps.\n", dis);
	}
	return 0;
}
