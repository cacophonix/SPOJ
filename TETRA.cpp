/*
USER: zobayer
TASK: TETRA
ALGO: geometry
*/

#include <cstdio>
#include <cmath>

const double EPS = 1e-9;

inline double volume(double u, double v, double w, double U, double V, double W) { 
	double u1,v1,w1; 
	u1 = v * v + w * w - U * U; 
	v1 = w * w + u * u - V * V; 
	w1 = u * u + v * v - W * W; 
	return sqrt(4.0*u*u*v*v*w*w - u*u*u1*u1 - v*v*v1*v1 - w*w*w1*w1 + u1*v1*w1) / 12.0;
}

inline double surface(double a, double b, double c) {
	return sqrt((a + b + c) * (-a + b + c) * (a - b + c) * (a + b - c)) / 4.0;
}

int main() {
	int test;
	double WX, WY, WZ, XY, XZ, YZ, sur, rad;
	scanf("%d", &test);
	while(test--) {
		scanf("%lf %lf %lf %lf %lf %lf", &WX, &WY, &WZ, &XY, &XZ, &YZ);
		sur = surface(WX, WY, XY) + surface(WX, XZ, WZ) + surface(WY, YZ, WZ) + surface(XY, XZ, YZ);
		rad = volume(WX, WY, WZ, YZ, XZ, XY) * 3.0 / sur;
		printf("%.4lf\n", rad + EPS);
	}
	return 0;
}