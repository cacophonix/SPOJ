/*
USER: zobayer
TASK: CLOCK2
ALGO: ad-hoc
*/

#include <cstdio>
#include <cstring>

char a[][8] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII"};

int main() {
	int i, t=1;
	char aa[8];
	while(scanf("%s", aa) == 1) {
	    for(i = 0; i < 12; i++) if(!strcmp(a[i], aa)) break;
	    printf("Case %d: %d\n", t++, i+1);
	}
	return 0;
}
