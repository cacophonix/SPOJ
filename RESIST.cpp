/*
USER: zobayer
TASK: RESIST
ALGO: gaussian elimination
*/

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAX = 128;
const double EPS = 1e-9;
const double INF = 1e19;

double G[MAX][MAX], M[MAX][MAX], res[MAX];

void gaussianElimination(int n) {
	int i, j, k; double p;
	for(i = 0; i < n; i++) {
		for(k = i, j = i + 1; j < n; j++) if(fabs(M[j][i]) > fabs(M[k][i])) k = j;
		if(i != k) {
			for(j = i; j < n; j++) swap(M[i][j], M[k][j]);
			swap(res[i], res[k]);
		}
		for(k = i, p = M[i][i]; k < n; k++) M[i][k] /= p; res[i] /= p;
		for(j = i + 1; j < n; j++) {
			if(fabs(M[j][i]) < EPS) continue;
			for(k = i, p = M[j][i]; k < n; k++) M[j][k] -= M[i][k] * p;
			res[j] = res[j] - res[i] * p;
		}
	}
	for(i = n-1; i >= 0; i--) {
		if(fabs(M[i][i]) < EPS) continue;
		for(j = i + 1; j < n; j++) res[i] -= res[j] * M[i][j];
	}
}

int main() {
	int n, e, i, j, u, v, w;
	while(scanf("%d %d", &n, &e) == 2) {
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) G[i][j] = INF, M[i][j] = 0.0;
			res[i] = 0.0;
		}
		for(i = 0; i < e; i++) {
			scanf("%d %d %d", &u, &v, &w);
			u--, v--;
			G[u][v] = 1.0 / (1.0 / G[u][v] + 1.0 / w);
			G[v][u] = 1.0 / (1.0 / G[v][u] + 1.0 / w);
		}
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				M[i][j] -= 1.0 / G[i][j];
				M[i][i] += 1.0 / G[i][j];
			}
		}
		res[0] = 1.0, res[n-1] = -1.0;
		gaussianElimination(n - 1);
		printf("%.2lf\n", fabs(res[0]) + EPS);
	}
	return 0;
}