/*
USER: zobayer
TASK: CATM
ALGO: geometro
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main() {
	int R, C, test, mr, mc, ar, ac, br, bc;
	int mtop, mleft, mbot, mright, ctop, cleft, cbot, cright;
	scanf("%d%d%d", &R, &C, &test);
	while(test--) {
		scanf("%d%d%d%d%d%d", &mr, &mc, &ar, &ac, &br, &bc);
		if(mr >= ar && mr >= br) printf("YES\n");
		else if(mr <= ar && mr <= br) printf("YES\n");
		else if(mc >= ac && mc >= bc) printf("YES\n");
		else if(mc <= ac && mc <= bc) printf("YES\n");
		else {
			mtop = mr - 1;
			ctop = min(abs(1-ar)+abs(mc-ac), abs(1-br)+abs(mc-bc));
			mleft = C - mc;
			cleft = min(abs(mr-ar)+abs(C-ac), abs(mr-br)+abs(C-bc));
			mbot = R - mr;
			cbot = min(abs(R-ar)+abs(mc-ac), abs(R-br)+abs(mc-bc));
			mright = mc - 1;
			cright = min(abs(mr-ar)+abs(1-ac), abs(mr-br)+abs(1-bc));
			if(mtop < ctop || mbot < cbot || mleft < cleft || mright < cright) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
