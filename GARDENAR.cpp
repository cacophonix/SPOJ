/*
USER: zobayer
TASK: GARDENAR
ALGO: geometry
*/

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

double a, b, c;

double side(double L, double R) {
	double M, at, a1, a2, a3, s;
	int i = 34;
	while(i--) {
		M = (L + R) / 2.0;
		at = M * M * sqrt(3.0) / 4.0;
		s = (M + a + b) / 2.0; a1 = sqrt( s * (s-a) * (s-b) * (s-M) );
		s = (M + b + c) / 2.0; a2 = sqrt( s * (s-b) * (s-c) * (s-M) );
		s = (M + c + a) / 2.0; a3 = sqrt( s * (s-c) * (s-a) * (s-M) );
		if(at > a1 + a2 + a3) R = M;
		else L = M;
	}
	return M;
}

template< class T > T tmax(T x, T y, T z) {
	return max( x, max( y, z) );
}

template< class T > T tmin(T x, T y, T z) {
	return min( x, min( y, z) );
}

int main() {
	double x;
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%lf%lf%lf", &a, &b, &c);
		x = side(tmax(fabs(a-b), fabs(b-c), fabs(c-a)), tmin(a+b, b+c, c+a));
		printf("%.2lf\n", sqrt(3.0)/4.0 * x * x + 1e-10);
	}
	return 0;
}

