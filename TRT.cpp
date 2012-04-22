/*
USER: zobayer
TASK: TRT
ALGO: dynamic programming
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1 << 11;

int N, *vec, *vp1, *vp2;

inline int max (int a, int b) {
	return a > b ? a : b;
}

int main () {
	int i, j;
	scanf ("%d", &N);
	vec = new int[N];
	vp1 = new int [N];
	vp2 = new int [N];
	for (i = 0; i < N; ++i)
		scanf ("%d", vec + i);
	for (i = 0; i < N; ++i)
		vp1[i] = vec[i] * N;
	for (i = 2; i <= N; ++i) {
		for (j = 0; j + i <= N; ++j)
			vp2[j] = max(vp1[j]+vec[j+i-1]*(N+1-i),vp1[j+1]+vec[j]*(N+1-i));
		swap(vp1, vp2);
	}
	printf ("%d\n", vp1[0]);
	return 0;
}
