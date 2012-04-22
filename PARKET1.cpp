/*
USER: zobayer
TASK: PARKET1
ALGO: math
*/

#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	double R, C, r, b;
	scanf("%lf %lf", &r, &b);
	R = ((r+4.0) + sqrt((r+4.0)*(r+4.0) - 16.0*(b+r))) / 4.0;
	C = (b+r) / R;
	if(R > C) printf("%.0lf %.0lf\n", R, C);
	else printf("%.0lf %.0lf\n", C, R);
	return 0;
}

/*
R + C = (r + 4) / 2
RC = b + r

C = (b + r) / R
R + (b + r) / R = (r + 4) / 2
2R^2 - R(r+4) + 2(b+r) = 0
*/