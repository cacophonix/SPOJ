/*
USER: zobayer
TASK: BEENUMS
ALGO: math
*/

#include <cstdio>
#include <cmath>
using namespace std;

typedef long long i64;

int main() {
	i64 p, d, rt;
	while(scanf("%lld", &p)==1 && p > 0) {
		d = 9 + 12*(p-1);
		rt = (i64)sqrt((double)d);
		if(rt*rt == d) {
			rt -= 3;
			if(rt % 6 == 0) puts("Y");
			else puts("N");
		}
		else puts("N");
	}
	return 0;
}