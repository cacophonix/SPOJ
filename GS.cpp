/*
USER: zobayer
TASK: GS
ALGO: gaussian elimination
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef vector<double> vec;
typedef vector<vec> mat;

const double EPS = 1e-9;

int deg[20];

vec GaussianElimination(const mat& A, const vec& b) {
	int i, j, k, pivot, n = A.size();
	mat B(n, vec(n+1));
	vec x(n);
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) B[i][j] = A[i][j];
		B[i][n] = b[i];
	}
	for(i = 0; i < n; i++) {
		for(pivot = j = i; j < n; ++j) if(fabs(B[j][i]) > fabs(B[pivot][i])) pivot = j;
		swap(B[i], B[pivot]);
		if(fabs(B[i][i]) < EPS) return vec();
		for(j = n; j >= i; --j) B[i][j] /= B[i][i];
		for(j = 0; j < n; j++) if(i != j) for(k = i+1; k <= n; ++k) B[j][k] -= B[j][i] * B[i][k];
	}
	for(i = 0; i < n; i++) x[i] = B[i][n];
	return x;
}

int main() {
	int test, i, j, u, v, c, n, s, t;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	while(test--) {
		memset(deg, 0, sizeof deg);
		scanf("%d%d%d", &n, &s, &t);
		--s, --t;
		mat a(n, vec(n));
		for(i = 1; i < n; i++) {
			scanf("%d%d%d", &u, &v, &c);
			--u, --v;
			a[u][v] = a[v][u] = c;
			deg[u] += c, deg[v] += c;
		}
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				if (i == j) a[i][i] = 1;
				else a[i][j] = a[i][j] / -deg[i];
			}
		}
		for(i = 0; i < n; i++) a[i].erase(a[i].begin() + t);
		a.erase(a.begin() + t);
		vec ones(n-1, 1);
		vec ans = GaussianElimination(a, ones);
		printf("%.5f\n", s == t ? 0 : s < t ? ans[s] : ans[s-1]);
	}
}
