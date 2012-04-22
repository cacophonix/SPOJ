/*
USER: zobayer
TASK: MJLAR10
ALGO: ad-hoc
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ord[6][3], a[3], b[3], c[3];
char flag[53];

bool wins() {
	int i, j, k, cnt;
	for(i = 0; i < 6; i++) {
		for(j = 0; j < 6; j++) {
			for(k = cnt = 0; k < 3; k++) {
				if(a[ord[i][k]] > c[ord[j][k]]) cnt++;
			}
			if(cnt > 1) return true;
		}
	}
	return false;
}

int main() {
	int i, j;
	i = 0, a[0] = 0, a[1] = 1, a[2] = 2;
	do {
		for(j = 0; j < 3; j++) ord[i][j] = a[j];
		i++;
	} while(next_permutation(a, a + 3));
	while(scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &b[0], &b[1])==5) {
		if(!(a[0] + a[1] + a[2] + b[0] + b[1])) break;
		memset(flag, 0, sizeof flag);
		flag[a[0]] = flag[a[1]] = flag[a[2]] = flag[b[0]] = flag[b[1]] = 1;
		for(i = 1; i <= 52; i++) {
			if(flag[i]) continue;
			c[0] = b[0], c[1] = b[1], c[2] = i;
			if(!wins()) break;
		}
		if(i > 52) printf("-1\n");
		else printf("%d\n", i);
	}
	return 0;
}
