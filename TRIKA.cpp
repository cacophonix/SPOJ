/*
USER: zobayer
TASK: TRIKA
ALGO: dynamic programming
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, m, r, c, a[32][32], i, j;
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d%d%d%d", &n, &m, &r, &c);
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for(i = r + 1; i <= n; i++) a[i][c] = a[i-1][c] - a[i][c];
	for(j = c + 1; j <= m; j++) a[r][j] = a[r][j-1] - a[r][j];
	for(i = r + 1; i <= n; i++)
		for(j = c + 1; j <= m; j++)
			a[i][j] = max(a[i-1][j], a[i][j-1]) - a[i][j];
	if(a[n][m] >= 0) printf("Y %d\n", a[n][m]);
	else printf("N\n");
	return 0;
}
