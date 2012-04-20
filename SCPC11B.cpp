/*
USER: zobayer
TASK: SCPC11B
ALGO: sorting
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int n, i, a[2048];
	while(scanf("%d", &n)==1 && n) {
		for(i = 0; i < n; i++) scanf("%d", a + i);
		sort(a, a + n);
		for(i = 1; i < n; i++) {
			if(a[i] - a[i-1] > 200) break;
		}
		if(i < n || (1422 - a[i-1])*2 > 200) puts("IMPOSSIBLE");
		else puts("POSSIBLE");
	}
	return 0;
}
