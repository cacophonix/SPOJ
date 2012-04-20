/*
USER: zobayer
TASK: TTREAT
ALGO: ad-hoc
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 10001;
int a[MAX], b[MAX];

int main() {
	int n, m, dmp, st, en, dur, i;
	while(scanf("%d%d", &n, &m)==2) {
		if(!m && !n) break;
		for(i = 0; i < n; i++) {
			scanf("%d%d%d%d", &dmp, &dmp, &st, &dur);
			a[i] = st;
			b[i] = a[i] + dur;
		}
		while(m--) {
			scanf("%d%d", &st, &dur);
			en = st + dur;
			dmp = 0;
			for(i = 0; i < n; i++)
				if(b[i]-a[i] >= 1 && ((a[i]<=st && b[i]>=en) || (a[i]>=st && a[i]<en) || (b[i]>st && b[i]<=en)))
					dmp++;
			printf("%d\n", dmp);
		}
	}
	return 0;
}
