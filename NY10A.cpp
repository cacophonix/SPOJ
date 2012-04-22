/*
USER: zobayer
TASK: NY10A
ALGO: ad-hoc
*/

#include <cstdio>
using namespace std;

int main() {
	int test, cs, cnt[8], i, p;
	char toss[64];
	scanf("%d", &test);
	while(test--) {
		scanf("%d %s", &cs, toss);
		for(i = 0; i < 8; i++) cnt[i] = 0;
		for(p = i = 0; i < 40; i++) {
			p = (p << 1) | (toss[i]=='H');
			if(i > 1) cnt[p&7]++;
		}
		printf("%d", cs);
		for(i = 0; i < 8; i++) printf(" %d", cnt[i]);
		printf("\n");
	}
	return 0;
}