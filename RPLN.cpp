/*
USER: zobayer
TASK: RPLN
ALGO: range minimum query
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1 << 17;
const int LOG = 17;

int M[MAX][LOG], A[MAX];

void process(int n) {
	int i, j;
	for(i = 0; i < n; i++) M[i][0] = i;
	for(j = 1; (1 << j) <= n; j++) {
		for(i = 0; i + (1 << j) <= n; i++) {
			if(A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]]) M[i][j] = M[i][j - 1];
			else M[i][j] = M[i + (1 << (j - 1))][j - 1];
		}
	}
}

int main() {
	int test, cs, n, q, i, j, k;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &n, &q);
		for(i = 0; i < n; i++) scanf("%d", &A[i]);
		process(n);
		printf("Scenario #%d:\n\n", cs);
		while(q--) {
			scanf("%d %d", &i, &j);
			for(i--, j--, k = 1; (1 << k) <= (j - i + 1); k++); k--;
			printf("%d\n", min(A[M[i][k]], A[M[j - (1 << k) + 1][k]]));
		}
	}
	return 0;
}
