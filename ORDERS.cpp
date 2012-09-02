/*
USER: zobayer
TASK: ORDERS
ALGO: semgent tree
*/

#include <cstdio>

const int MAX = 1 << 18;
const int TMAX = 1 << 19;

int s[MAX], a[MAX], T[TMAX], res[MAX];

void init(int node, int i, int j) {
	if(i == j) { T[node] = 1; return; }
	int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1;
	init(lt, i, mid);
	init(rt, mid + 1, j);
	T[node] = T[lt] + T[rt];
}

int find(int node, int i, int j, int v) {
	if(i == j) return i;
	int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1;
	if(T[lt] >= v) return find(lt, i, mid, v);
	return find(rt, mid + 1, j, v - T[lt]);
}

void remove(int node, int i, int j, int p) {
	if(i == j) { T[node] = 0; return; }
	int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1;
	if(p <= mid) remove(lt, i, mid, p);
	else remove(rt, mid + 1, j, p);
	T[node] = T[lt] + T[rt];
}

int main() {
	int test, n, i;
	for(i = 0; i < MAX; i++) s[i] = i + 1;
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) scanf("%d", a + i);
		init(1, 0, n-1);
		for(i = n - 1; i >= 0; i--) {
			res[i] = find(1, 0, n-1, i + 1 - a[i]);
			remove(1, 0, n-1, res[i]);
		}
		printf("%d", s[res[0]]);
		for(i = 1; i < n; i++) printf(" %d", s[res[i]]);
		printf("\n");
	}
	return 0;
}
