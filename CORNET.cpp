/*
USER: zobayer
TASK: CORNET
ALGO: depth first search
*/

#include <stdio.h>
#include <stdlib.h>

const int MAX = 20002;
const int MOD = 1000;

int parent[MAX], d[MAX];

void find(int u) {
	if(u!=parent[u]) {
		find(parent[u]);
		d[u] = (d[u] + d[parent[u]]);
		parent[u] = parent[parent[u]];
	}
}

int main() {
	int t, i, j, n;
	char cm[2];
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(i=1; i<=n; i++) parent[i] = i, d[i] = 0;
		while(scanf("%s", cm)==1 && cm[0]!='O') {
			switch(cm[0]) {
			case 'E':
				scanf("%d", &i);
				find(i);
				printf("%d\n", d[i]);
				break;
			case 'I':
				scanf("%d%d", &i, &j);
				parent[i] = parent[j];
				d[i] = d[j] + abs(i-j) % MOD;
			}
		}
	}
	return 0;
}
