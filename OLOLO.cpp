/*
USER: zobayer
TASK: OLOLO
ALGO: ad-hoc
*/

#include <cstdio>

const int BUFF = 5000000;
static char buff[BUFF], *p;

#define R(n) while(*p<48)p++;n=0;do{n=n*10+*p++-48;}while(*p>47);

int main() {
	int n, s, a;
	fread(buff, 1, BUFF, stdin);
	p = buff; R(n); s = 0;
	while(n--) { R(a); s ^= a; }
	printf("%d\n", s);
	return 0;
}