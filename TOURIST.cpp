/*
USER: zobayer
TASK: TOURIST
ALGO: dynamic programming
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int dp[200][100][100], f[200][100][100];
int test, cs, R, C;
int dr[] = {0, 1}, dc[] = {1, 0};
char grid[100][101];

int solve(int stp, int r1, int r2) {
	if(stp == R + C - 2) {
		if(stp-r1==C-1 && r1==R-1 && r1==r2) return grid[r1][stp-r1]=='*';
		else return -1;
	}
	if(f[stp][r1][r2] == cs) return dp[stp][r1][r2];
	f[stp][r1][r2] = cs;
	int &ret = dp[stp][r1][r2]; ret = -1;
	int c1 = stp - r1, c2 = stp - r2;
	if(c1 < C && c2 < C && grid[r1][c1] != '#' && grid[r2][c2] != '#') {
		ret = max(ret, solve(stp + 1, r1, r2));
		if(r1 + 1 < R) ret = max(ret, solve(stp + 1, r1 + 1, r2));
		if(r2 + 1 < R) ret = max(ret, solve(stp + 1, r1, r2 + 1));
		if(r1 + 1 < R && r2 + 1 < R) ret = max(ret, solve(stp + 1, r1 + 1, r2 + 1));
		if(ret != -1) {
			if(grid[r1][c1] == '*') ret++;
			if(r1 != r2 && grid[r2][c2] == '*') ret++;
		}
	}
	return ret;
}

int main() {
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &C, &R);
		for(int i = 0; i < R; i++) scanf("%s", grid[i]);
		printf("%d\n", solve(0, 0, 0));
	}
	return 0;
}