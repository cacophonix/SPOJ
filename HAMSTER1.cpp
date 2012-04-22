/*
USER: zobayer
TASK: HAMSTER1
ALGO: ternary search
*/

#include <cstdio>
#include <cmath>
using namespace std;

typedef long double ld;
const ld g = 10.0;

ld k1, k2, u;

ld score(ld alpha) {
	return (u*u)/(2.0*g)*(2.0*k1*sin(2.0*alpha) + k2*sin(alpha)*sin(alpha));
}

ld search(ld low, ld high, ld eps) {
	if(fabs(high - low) < eps) return (low + high) / 2.0;
	ld leftThird = (2.0 * low + high) / 3.0;
	ld rightThird = (low + 2.0 * high) / 3.0;
	if(score(leftThird) < score(rightThird)) return search(leftThird, high, eps);
	else return search(low, rightThird, eps);
}

int main() {
	int test;
	ld alpha, total;
	scanf("%d", &test);
	while(test--) {
		scanf("%Lf %Lf %Lf", &u, &k1, &k2);
		alpha = search(0.0, 0.5*acos(-1.0), 1e-9);
		total = score(alpha);
		printf("%.3Lf %.3Lf\n", alpha, total);
	}
	return 0;
}