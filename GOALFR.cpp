/*
USER: zobayer
TASK: GOALFR
ALGO: geometry
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <cmath>
#include <cstdio>
using namespace std;

#define eps 10e-10
#define sq(x) ((x)*(x))

struct POINT {
	double x, y;
};

struct CIRCLE {
	POINT c;
	double r;
};

bool cross(POINT p1, POINT p2, CIRCLE p) {
	double a, b, c, d;
	POINT t;

	t.x = p2.x - p1.x;
	t.y = p2.y - p1.y;

	a = sq(t.x) + sq(t.y);
	b = 2.0 * (t.x * (p1.x - p.c.x) + t.y * (p1.y - p.c.y));
	c = sq(p.c.x) + sq(p.c.y);
	c += sq(p1.x) + sq(p1.y);
	c -= 2.0 * (p.c.x * p1.x + p.c.y * p1.y);
	c -= sq(p.r);
	d = b * b - 4 * a * c;

	if(fabs(a) < eps || d < -eps) return false;
	return true;
}

int main() {
	CIRCLE golee;
	POINT raul, gbarU = {52.0, 3.66}, gbarD = {52.0, -3.66};
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%lf%lf%lf%lf%lf", &raul.x, &raul.y, &golee.c.x, &golee.c.y, &golee.r);
		if(cross(raul, gbarU, golee) && cross(raul, gbarD, golee)) printf("No goal...\n");
		else printf("Goal!\n");
	}
	return 0;
}
