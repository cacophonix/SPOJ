/*
USER: zobayer
TASK: GNY07E
ALGO: ad-hoc
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	int test, n, i, j, k, a[32], res[128], idx, cs = 1;
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		for(i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(idx = 0, i = n; i; i--) {
			if(a[i] == i) continue;
			for(k = i; k; k--) if(abs(a[k]) == i) break;
			reverse(a+1, a+k+1);
			for(j = k; j; j--) a[j] *= -1;
			res[idx++] = k;
			if(i > 1) {
				if(a[1] != -i) {
					res[idx++] = 1;
					a[1] *= -1;
				}
				reverse(a+1, a+i+1);
				for(j = i; j; j--) a[j] *= -1;
				res[idx++] = i;
			}
		}
		printf("%d %d", cs++, idx);
		for(i = 0; i < idx; i++) printf(" %d", res[i]);
		printf("\n");
	}
	return 0;
}
