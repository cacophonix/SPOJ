/*
USER: zobayer
TASK: GCPC11D
ALGO: backtrack
*/

#include <cstdio>
#include <cstring>
#include <cassert>

typedef struct { int x, y; } P;

P points[12];
P lines[12];
char grid[8][16], out[8][16], flag[12], done;
int sum[6];

int find(int i, int j) {
	for(int k = 0; k < 12; k++) {
		if(points[k].x == i && points[k].y == j) return k;
	}
	return -1;
}

void recur(int id) {
	int i, a, b, tmp;
	if(id == 12) {
		for(i = 0; i < 5; i++) fputs(out[i], stdout);
		done = 1;
		return;
	}
	if(grid[points[id].x][points[id].y] != 'x') {
		recur(id + 1);
		return;
	}
	for(i = 0; i < 12; i++) {
		if(!flag[i]) {
			a = lines[id].x;
			b = lines[id].y;
			if(sum[a] < i + 1 || sum[b] < i + 1) break;
			sum[a] -= i + 1;
			sum[b] -= i + 1;
			flag[i] = 1;
			tmp = out[points[id].x][points[id].y];
			out[points[id].x][points[id].y] = 'A' + i;
			recur(id + 1);
			if(done) return;
			out[points[id].x][points[id].y] = tmp;
			flag[i] = 0;
			sum[a] += i + 1;
			sum[b] += i + 1;
		}
	}
}

int main() {
	int i, j, k, a, b;
	points[0] = (P){0,4}; points[1] = (P){1,1}; points[2] = (P){1,3};
	points[3] = (P){1,5}; points[4] = (P){1,7}; points[5] = (P){2,2};
	points[6] = (P){2,6}; points[7] = (P){3,1}; points[8] = (P){3,3};
	points[9] = (P){3,5}; points[10] = (P){3,7}; points[11] = (P){4,4};
	lines[0] = (P){0,1}, lines[1] = (P){2,3}, lines[2] = (P){0,2};
	lines[3] = (P){1,2}, lines[4] = (P){2,4}, lines[5] = (P){0,3};
	lines[6] = (P){1,4}, lines[7] = (P){0,5}, lines[8] = (P){3,5};
	lines[9] = (P){4,5}, lines[10] = (P){1,5}, lines[11] = (P){3,4};
	for(i = 0; i < 5; i++) {
		fgets(grid[i], 16, stdin);
	}
	memcpy(out, grid, sizeof grid);
	for(i = 0; i < 6; i++) sum[i] = 26;
	memset(flag, 0, sizeof flag);
	for(i = 0; i < 5; i++) {
		for(j = 0; j < 9; j++) {
			if(grid[i][j] != '.') {
				if(grid[i][j] != 'x') {
					k = find(i, j);
					a = lines[k].x;
					b = lines[k].y;
					sum[a] -= (grid[i][j]-'A'+1);
					sum[b] -= (grid[i][j]-'A'+1);
					flag[grid[i][j]-'A'] = 1;
				}
			}
		}
	}
	done = 0;
	recur(0);
	assert(done == 1);
	return 0;
}
