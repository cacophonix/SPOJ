/*
USER: zobayer
TASK: MSE06H
ALGO: binary indexed tree
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long i64;
const int RMAX = 1000009;
const int NMAX = 1009;

struct Road { int u, v; };

i64 BIT[NMAX], m, n;
Road roads[RMAX];

i64 read(int idx) {
	i64 sum = 0;
	while(idx > 0) {
		sum += BIT[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void add(int idx, int v) {
	while(idx <= m) {
		BIT[idx] += v;
		idx += (idx & -idx);
	}
}

bool comp(const Road a, const Road b) {
	return ((a.u==b.u)? (a.v < b.v) : (a.u < b.u));
}

int main() {
	int t, k, i, j, cs = 1;
	i64 res;
	scanf("%d", &t);
	while(t--) {
		memset(BIT, 0, sizeof(BIT));
		res = 0;
		scanf("%d%d%d", &n, &m, &k);
		for(i = 0; i < k; i++) scanf("%d%d", &roads[i].u, &roads[i].v);
		sort(roads, roads + k, comp);
		for(i = k-1; i >= 0; i = j) {
			for(j = i; j >= 0 && roads[j].u == roads[i].u; j--) res += read(roads[j].v - 1);
			for(j = i; j >= 0 && roads[j].u == roads[i].u; j--) add(roads[j].v, 1);
		}
		printf("Test case %d: %lld\n", cs++, res);
	}
	return 0;
}
