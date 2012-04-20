/*
USER: zobayer
TASK: ZBROJ
ALGO: ad-hoc
*/

#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
	char num1[8], num2[8];
	int i, mx, mn;
	scanf("%s %s", num1, num2);
	for(i = 0; num1[i]; i++) if(num1[i]=='6') num1[i] = '5';
	for(i = 0; num2[i]; i++) if(num2[i]=='6') num2[i] = '5';
	mn = atoi(num1) + atoi(num2);
	for(i = 0; num1[i]; i++) if(num1[i]=='5') num1[i] = '6';
	for(i = 0; num2[i]; i++) if(num2[i]=='5') num2[i] = '6';
	mx = atoi(num1) + atoi(num2);
	printf("%d %d\n", mn, mx);
	return 0;
}