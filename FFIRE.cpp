/*
USER: zobayer
TASK: FFIRE
ALGO: bfs
*/

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX = 16;
const int SZ = 10;

typedef pair< int, int > pii;

int d[MAX][MAX];
int dr[] = {1, 0, 0, -1}, dc[] = {0, -1, 1, 0};
char grid[MAX][MAX];
vector< pii > F, T;

inline bool inside(int a, int b, int c) {
	return a <= b && b < c;
}

int bfs() {
	int i, k, ret;
	pii u, v;
	queue< pii > Q;
	for(i = 0; i < F.size(); i++) {
		Q.push(F[i]);
		d[F[i].first][F[i].second] = 0;
	}
	while(!Q.empty()) {
		u = Q.front(); Q.pop();
		for(k = 0; k < 4; k++) {
			v.first = u.first + dr[k];
			v.second = u.second + dc[k];
			if(inside(0, v.first, SZ) && inside(0, v.second, SZ) && grid[v.first][v.second] == 'T') {
				grid[v.first][v.second] = 'F';
				d[v.first][v.second] = d[u.first][u.second] + 1;
				Q.push(v);
			}
		}
	}
	for(ret = -1, i = 0; i < T.size(); i++) {
		if(grid[T[i].first][T[i].second] != 'F') {
			ret = -1;
			break;
		}
		else ret = max(ret, d[T[i].first][T[i].second]);
	}
	return ret;
}

int main() {
	int i, j;
	for(i = 0; i < SZ; i++) {
		scanf("%s", grid[i]);
		for(j = 0; j < SZ; j++) {
			if(grid[i][j] == 'T') T.push_back(pii(i, j));
			else if(grid[i][j] == 'F') F.push_back(pii(i, j));
		}
	}
	printf("%d\n", bfs());
	return 0;
}
