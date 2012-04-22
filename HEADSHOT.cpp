/*
USER: zobayer
TASK: HEADSHOT
ALGO: ad-hoc
*/

#include <stdio.h>
#include <math.h>

int main() {
	char round[110];
	double total, zero, ones, cnt;
	scanf("%s", round);
	total = zero = ones = cnt = 0;
	for(int i = 0; round[i]; i++, cnt++) {
		if(round[i]=='0') {
			total++;
			if(round[i+1]) {
				zero += round[i+1]=='0';
				ones += round[i+1]=='1';
			}
			else {
				zero += round[0]=='0';
				ones += round[0]=='1';
			}
		}
	}
	if(fabs(zero/(zero+ones) - total / cnt) < 1e-10) puts("EQUAL");
	else if(zero/(zero+ones) > total / cnt) puts("SHOOT");
	else puts("ROTATE");
	return 0;
}