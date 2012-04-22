/*
USER: zobayer
TASK: SAMER08G
ALGO: ad-hoc
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 1000;
int car[MAX], pos[MAX], cng[MAX];

int main() {
	int n, i, sp;
	while(scanf("%d", &n)==1 && n) {
		for(i = 0; i < n; i++) scanf("%d%d", &car[i], &cng[i]);
		memset(pos, -1, sizeof pos);
		for(i = 0; i < n; i++) {
			sp = i + cng[i];
			if(sp >= 0 && sp < n && pos[sp]==-1) pos[sp] = car[i];
			else break;
		}
		if(i == n) {
			printf("%d", pos[0]);
			for(i = 1; i < n; i++) printf(" %d", pos[i]);
			printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}