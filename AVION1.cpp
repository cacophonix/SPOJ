/*
USER: zobayer
TASK: AVION1
ALGO: ad-hoc
*/

#include <stdio.h>
#include <string.h>

int main() {
	char str[16], *ptr;
	int first = 0, i;
	for(i = 0; i < 5; i++) {
		scanf("%s", str);
		ptr = strstr(str, "FBI");
		if(ptr) {
			if(first) putchar(' ');
			putchar(i+'1'); first++;
		}
	}
	if(!first) puts("HE GOT AWAY!");
	else putchar('\n');
	return 0;
}