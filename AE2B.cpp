/*
USER: zobayer
TASK: AE2B
ALGO: math
*/

#include <stdio.h>

const int BUFF = 1280000;
static char buff[BUFF], *ptr;

inline int gcd(int a, int b) {
	while(b) b ^= a ^= b ^= a %= b;
	return a;
}

inline int nextInt() {
	while(*ptr != '-' && (*ptr < '0' || *ptr > '9')) ptr++;
	int minus = 0, ret = 0;
	if(*ptr=='-') minus = 1, ptr++;
	while(*ptr >= '0' && *ptr <= '9') ret = ret * 10 + *ptr - '0', ptr++;
	if(minus) ret = -ret;
	return ret;
}

int main() {
	int test, k, n, dx, dy, x1, y1, x2, y2, g;
	fread(buff, BUFF, 1, stdin); ptr = buff;
	test = nextInt();
	while(test--) {
		k = nextInt();
		n = nextInt();
		x1 = nextInt();
		y1 = nextInt();
		x2 = nextInt();
		y2 = nextInt();
		g = gcd(k, n);
		dx = x1 > x2? x1 - x2 : x2 - x1;
		dy = y1 > y2? y1 - y2 : y2 - y1;
		if(g > 1) {
			if(dx % g || dy % g) {
				puts("NIE");
				continue;
			}
			k /= g, n /= g, dx /= g, dy /= g;
		}
		if(!(k&1) || !(n&1)) puts("TAK");
		else if((dx&1) + (dy&1) == 1) puts("NIE");
		else puts("TAK");
	}
	return 0;
}