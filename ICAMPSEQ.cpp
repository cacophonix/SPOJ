/*
USER: zobayer
TASK: ICAMPSEQ
ALGO: brute force
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i;
	static char buff[128], *bp, *cp;
	double a, b, c, d, s;
	double __000, __001, __010, __011, __100, __101, __110, __111;
	double mn000, mn001, mn010, mn011, mn100, mn101, mn110, mn111;
	double mx000, mx001, mx010, mx011, mx100, mx101, mx110, mx111;
	mn000 = mn001 = mn010 = mn011 = mn100 = mn101 = mn110 = mn111 = 1e19;
	mx000 = mx001 = mx010 = mx011 = mx100 = mx101 = mx110 = mx111 = -1e19;
	n = atoi(gets(buff));
	for(i = 0; i < n; i++) {
		bp = gets(buff);
		while(*bp <= 32) bp++; cp = bp; while(*cp > 32) cp++; *cp = 0; a = atof(bp); bp = cp;
		while(*bp <= 32) bp++; cp = bp; while(*cp > 32) cp++; *cp = 0; b = atof(bp); bp = cp;
		while(*bp <= 32) bp++; cp = bp; while(*cp > 32) cp++; *cp = 0; c = atof(bp); bp = cp;
		while(*bp <= 32) bp++; cp = bp; while(*cp > 32) cp++; *cp = 0; d = atof(bp); bp = cp;
		__000 = a + b + c + d; if(mx000 < __000) mx000 = __000; if(mn000 > __000) mn000 = __000;
		__001 = a + b + c - d; if(mx001 < __001) mx001 = __001; if(mn001 > __001) mn001 = __001;
		__010 = a + b - c + d; if(mx010 < __010) mx010 = __010; if(mn010 > __010) mn010 = __010;
		__011 = a + b - c - d; if(mx011 < __011) mx011 = __011; if(mn011 > __011) mn011 = __011;
		__100 = a - b + c + d; if(mx100 < __100) mx100 = __100; if(mn100 > __100) mn100 = __100;
		__101 = a - b + c - d; if(mx101 < __101) mx101 = __101; if(mn101 > __101) mn101 = __101;
		__110 = a - b - c + d; if(mx110 < __110) mx110 = __110; if(mn110 > __110) mn110 = __110;
		__111 = a - b - c - d; if(mx111 < __111) mx111 = __111; if(mn111 > __111) mn111 = __111;
	}
	s = -1e19;
	if(mx000 - mn000 > s) s = mx000 - mn000;
	if(mx001 - mn001 > s) s = mx001 - mn001;
	if(mx010 - mn010 > s) s = mx010 - mn010;
	if(mx011 - mn011 > s) s = mx011 - mn011;
	if(mx100 - mn100 > s) s = mx100 - mn100;
	if(mx101 - mn101 > s) s = mx101 - mn101;
	if(mx110 - mn110 > s) s = mx110 - mn110;
	if(mx111 - mn111 > s) s = mx111 - mn111;
	printf("%.3lf\n", s + 1e-9);
	return 0;
}