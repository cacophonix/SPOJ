/*
USER: zobayer
TASK: CF36D
ALGO: ad-hoc
*/

#include <stdio.h>

int main() {
	int t, n, m, k, z, e;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d", &k, &n, &m);
		e = n + m;
		if(k==1) {
			if((n&1) && (m&1)) puts("-");
			else puts("+");
			continue;
		}
		if(m < n) n = m;
		if(n % (k+1) == 0) {
			puts("+");
			continue;
		}
		z = n / (k + 1);
		if(z & 1) {
			if(e & 1) puts("-");
			else puts("+");
		}
		else {
			if(e & 1) puts("+");
			else puts("-");
		}
	}
	return 0;
}
