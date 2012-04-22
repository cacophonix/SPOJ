/*
USER: zobayer
TASK: ANARC09B
ALGO: math
*/

#include <cstdio>
using namespace std;

#define i64 long long
#define FS "%lld\n"

i64 gcd( i64 a, i64 b ) {
	if(b) return gcd( b, a % b );
	return a;
}

i64 lcm( i64 a, i64 b ) {
	return a / gcd( a, b ) * b;
}

int main() {
	int a, b;
	while(scanf("%d%d", &a, &b)==2 && a + b) {
		i64 lcmv = lcm(a, b);
		printf(FS, ( lcmv / a ) * ( lcmv / b ) );
	}
	return 0;
}
