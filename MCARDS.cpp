/*
USER: zobayer
TASK: MCARDS
ALGO: dynamic programming
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int idx[5][101], u[404], v[404];
int seq[404], aux[404];
int ord[4] = {1, 2, 3, 4}, N, C;

int lis(int sz) {
	int i, u, v, bsz = 0, m;
	aux[bsz++] = 0;
	for(i=1; i<sz; i++) {
		if(seq[aux[bsz-1]] < seq[i]) {
			aux[bsz++] = i;
			continue;
		}
		for(u=0, v=bsz-1; u < v; ) {
			m = (u + v)>>1;
			if(seq[aux[m]] < seq[i]) u = m + 1;
			else v = m;
		}
		if(seq[i] < seq[aux[u]]) aux[u] = i;
	}
	return bsz;
}

int main() {
	int i, j, t, cnt, mn = 1<<30;
	//freopen("C:\\in.txt", "r", stdin);
	scanf("%d%d", &C, &N);
	for(i=0, t=N*C; i<t; i++) scanf("%d%d", &u[i], &v[i]);
	do {
		for(cnt=i=0; i<C; i++)
			for(j=1; j<=N; j++)
				idx[ord[i]][j] = ++cnt;
		for(j=0; j<t; j++) seq[j] = idx[u[j]][v[j]];
		mn = min(mn, t-lis(t));
	} while(next_permutation(ord, ord + C));
	printf("%d\n", mn);
	return 0;
}
