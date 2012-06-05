/*
USER: zobayer
TASK: TEAM2
ALGO: ad-hoc
*/

#include <cstdio>
#include <algorithm>
using namespace std;

#define sol(a,b,c,d) max(max(a,c)+max(b,d),max(a,b)+max(c,d))

int main() {
	int a, b, c, d, r1, r2, r3, cs = 1;
	while(scanf("%d %d %d %d", &a, &b, &c, &d) == 4) {
		r1 = sol(a, b, c, d);
		r2 = sol(a, c, b, d);
		r3 = sol(a, d, b, c);
		r1 = max(r1, r2);
		r1 = max(r1, r3);
		printf("Case %d: %d\n", cs++, r1);
	}
	return 0;
}