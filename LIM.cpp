/*
USER: zobayer
TASK: LIM
ALGO: gaussian elimination
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int MAX = 302;
const double EPS = 1e-9;

vector< int > G[MAX];
int mp[MAX], ac[MAX];
double mat[MAX][MAX], sol[MAX];

int main() {
	//freopen("in.txt", "r", stdin);
	int n, e, i, j, k, u, v, sz;
	double p, q, sum;
	while(scanf("%d", &e) == 1 && e) {
		for(i = 0; i < MAX; i++) G[i].clear();
		memset(mp, -1, sizeof mp);
		for(i = 0, n = 0; i < e; i++) {
			scanf("%d %d", &u, &v);
			if(mp[u] == -1) { mp[u] = n; ac[n] = u; n++; }
			if(mp[v] == -1) { mp[v] = n; ac[n] = v; n++; }
			G[mp[u]].push_back(mp[v]);
			G[mp[v]].push_back(mp[u]);
		}
		for(i = 0; i < n; i++) {
			for(j = 0; j <= n; j++) mat[i][j] = 0;
			if(ac[i] <= 290) {
				sz = G[i].size();
				for(j = 0; j < sz; j++) mat[i][G[i][j]] = -1;
				mat[i][i] = sz;
			}
			else {
				mat[i][i] = 1;
				mat[i][n] = (ac[i] == 300);
			}
		}
		for(i = 0; i < n; i++) {
			if(fabs(mat[i][i]) < EPS) continue;
			for(j = i + 1; j < n; j++) {
				if(fabs(mat[j][i]) < EPS) continue;
				p = mat[i][i], q = mat[j][i];
				for(k = i; k <= n; k++) mat[j][k] = mat[j][k] - mat[i][k] * q / p;
			}
		}
		for(i = n-1; i >= 0; i--) {
			sum = mat[i][n];
			for(j = i + 1; j < n; j++) sum -= mat[i][j] * sol[j];
			sol[i] = sum / mat[i][i];
			if(i == mp[0]) break;
		}
		printf("%.3lf\n", sol[mp[0]] + EPS);
	}
	return 0;
}