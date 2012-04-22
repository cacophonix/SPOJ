/*
USER: zobayer
TASK: GCPC11J
ALGO: breadth first search
*/

#include <cstdio>
#include <cstring>

const int MAX = 100000;

int d[MAX], to[MAX<<1], next[MAX<<1], fin[MAX], q[MAX], n, st, en;

int bfs(int s) {
	int e, u, v;
	memset(d, -1, n*sizeof(int));
	st = 0, en = 0;
	q[en++] = s;
	d[s] = 0;
	while(st < en) {
		u = q[st++];
		for(e = fin[u]; e >= 0; e = next[e]) {
			v = to[e];
			if(d[v] == -1) {
				d[v] = d[u] + 1;
				q[en++] = v;
			}
		}
	}
	for(u = 0; u < n; u++) if(d[u] > d[s]) s = u;
	return s;
}

int main() {
	int test, e, i, u, v;
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		memset(fin, -1, n*sizeof(int));
		for(i = 1, e = 0; i < n; i++) {
			scanf("%d %d", &u, &v);
			to[e] = v, next[e] = fin[u], fin[u] = e++;
			to[e] = u, next[e] = fin[v], fin[v] = e++;
		}
		printf("%d\n", (1 + d[bfs(bfs(0))])>>1);
	}
	return 0;
}
