/*
USER: zobayer
TASK: FTHEELF
ALGO: math
*/

#include <cstdio>
#include <cmath>

const double g = 9.8;

int main() {
	double v, h;
	while(scanf("%lf %lf", &v, &h) == 2) {
		if(h < 0 && v < 0) break;
		if(v < 1) printf("0.000000\n");
		else printf("%.6lf\n", v * v / g / tan(asin(v / sqrt(2.0 * g * h + 2.0 * v * v))));
	}
	return 0;
}

