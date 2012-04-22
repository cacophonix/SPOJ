/*
USER: zobayer
TASK: QUADRATE
ALGO: ad-hoc
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char buff[64], expr[64], *ptr;

int main() {
	int test = atoi(gets(buff)), i, j, a[3], d;
	while(test--) {
		gets(buff);
		for(i = j = 0; buff[i]!='='; i++) {
			if(buff[i]==' ') continue;
			if(buff[i]=='-' || buff[i]=='+') {
				expr[j++] = ' '; expr[j++] = buff[i];
			}
			else expr[j++] = buff[i];
		}
		expr[j] = 0;
		ptr = strtok(expr, " ");
		a[0] = a[1] = a[2] = 0;
		while(ptr) {
			for(i = j = 0; ptr[j]; j++) i += (ptr[j]=='x');
			a[i] = atoi(ptr);
			if(!a[i]) a[i] = ptr[0]=='-'?-1:1;
			ptr = strtok(0, " ");
		}
		d = a[1]*a[1] - 4*a[2]*a[0];
		if(!d) puts("Equal roots.");
		else if(d < 0) puts("Imaginary roots.");
		else puts("Distinct real roots.");
	}
	return 0;
}