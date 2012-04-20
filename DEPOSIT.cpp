/*
USER: zobayer
TASK: DEPOSIT
ALGO: pre-calculation
*/

#include <cstdio>
using namespace std;

int main() {
	int r, f, s, x, y, k, t, dep[20][2], tot[20][2];
	dep[0][0] = dep[1][1] = tot[0][0] = 1;
	dep[0][1] = dep[1][0] = tot[0][1] = 0;
	for(r = 2; r < 20; r++) {
		dep[r][0] = dep[r-1][0] + dep[r-2][0];
		dep[r][1] = dep[r-1][1] + dep[r-2][1];
	}
	for(r = 1; r < 20; r++) {
		tot[r][0] = tot[r-1][0] + dep[r][0];
		tot[r][1] = tot[r-1][1] + dep[r][1];
	}
	while(scanf("%d", &r)==1 && r) {
		scanf("%d%d", &k, &t);
		f = tot[r-1][0];
		s = tot[r-1][1];
		for(x = 1; (t-f*x) % s; x++);
		y = (t-f*x) / s;
		printf("%d %d %d\n", x, y, k * (x*dep[r-1][0] + y*dep[r-1][1]));
	}
	return 0;
}
