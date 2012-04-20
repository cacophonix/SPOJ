/*
USER: zobayer
TASK: PANCAKES
ALGO: ad-hoc
*/

#include <cstdio>
using namespace std;

const int INF = 0x7fffffff;

int main() {
	int n, r, recpid, total, curr, need, i, k;
	int have[64];
	while(scanf("%d%d", &n, &r)==2 && n+r) {
		for(i = 0; i < n; i++) {
			scanf("%d", &have[i]);
			have[i] *= 10;
		}
		recpid = 1, total = 0;
		for(k = 1; k <= r; k++) {
			curr = INF;
			for(i = 0; i < n; i++) {
				scanf("%d", &need);
				if(need) curr = curr < (have[i]/need) ? curr : (have[i]/need);
			}
			if(curr == INF) continue;
			if(total < curr) {
				total = curr;
				recpid = k;
			}
		}
		printf("%d %d\n", recpid, total);
	}
	return 0;
}
