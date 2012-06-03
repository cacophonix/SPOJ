/*
USER: zobayer
TASK: EQBOX
ALGO: computational geometry
*/

#include <cstdio>
#include <cmath>

#define eps 1e-10
#define i64 long long

inline bool fits(i64 a, i64 b, i64 c, i64 d) {
	if( a > c && b > d ) return true;
	if( d >= b ) return false;
	double x, y, L, K, Dmax, D;
	if( c*c+d*d < b*b ) return true;
	if( c*c+d*d > a*a+b*b ) return false;
	L = ( b - sqrt(c*c + d*d - a*a) ) / 2.0;
	K = ( a - sqrt(c*c + d*d - b*b) ) / 2.0;
	D = d;
	if( D*D > L*L + K*K ) return false;
	return true;
}

int main() {
	int i;
	i64 a, b, x, y, t;
	scanf("%d", &i);
	while(i--) {
		scanf("%lld %lld %lld %lld", &a, &b, &x, &y);
		if( a < b ) { t = a; a = b; b = t; }
		if( x < y ) { t = x; x = y; y = t; }
		if( fits(a, b, x, y) ) printf("Escape is possible.\n");
		else printf("Box cannot be dropped.\n");
	}
	return 0;
}


