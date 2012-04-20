/*
USER: zobayer
TASK: FRACTION
ALGO: math
*/

#include <cstdio>
#include <cmath>
using namespace std;

const int MAX = 7600459;
short frac[MAX][2];

int main() {
	int m, t, idx, i;
	short n, x, y, x1, y1, x2, y2;
	scanf("%d", &t);
	while(t--) {
		scanf("%hd%d", &n, &m);
		idx = 0;
		x = 1, y = n;
		x1 = 0, x2 = 1, y1 = 1, y2 = n;
		frac[idx][0] = 0, frac[idx][1] = 1, idx++;
		frac[idx][0] = 1, frac[idx][1] = n, idx++;
		while(y!=1) {
			x = ((y1+n)/y2)*x2-x1;
			y = ((y1+n)/y2)*y2-y1;
			frac[idx][0] = x, frac[idx][1] = y;
			idx++;
			x1 = x2, x2 = x, y1 = y2, y2 = y;
		}
		for(i=0; i<m; i++) {
			scanf("%d", &idx);
			idx--;
			printf("%hd/%hd\n", frac[idx][0], frac[idx][1]);
		}
	}
	return 0;
}
