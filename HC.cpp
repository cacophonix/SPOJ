/*
USER: zobayer
TASK: HC
ALGO: nim game
*/

#include <ios>

int main() {
	int t, n, i, p;
	char name[5], player[2][5] = {"hhb", "lxh"};
	for(scanf("%d", &t); t; t--) {
		scanf("%d%s", &n, name);
		p = (name[0]=='l');
		for(i=1; i<n; i++) {
			scanf("%s", name);
			p ^= (name[0]=='l');
		}
		puts(player[p]);
	}
	return 0;
}
