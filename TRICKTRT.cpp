/*
USER: zobayer
TASK: TRICKTRT
ALGO: ternary search
*/

#include <cstdio>
#include <cmath>

typedef struct { double x, y; } Point;

const int MAX = 50000;
const double EPS = 1e-12;

Point P[MAX];
int n;

inline double distsq(const Point &a, const Point &b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

double cost(double x) {
	Point p = {x, 0};
	double dist, mx = 0.0;
	for(int i = 0; i < n; i++) {
		dist = distsq(p, P[i]);
		if(dist > mx) mx = dist;
	}
	return mx;
}

double ternary(double lt, double rt) {
	int cnt = 64;
	double ltthrd, rtthrd;
	while(cnt--) {
		ltthrd = (2.0 * lt + rt) / 3.0;
		rtthrd = (lt + 2.0 * rt) / 3.0;
		if(cost(ltthrd) < cost(rtthrd)) rt = rtthrd;
		else lt = ltthrd;
	}
	return (lt + rt) / 2.0;
}

int main() {
	double xmax, xmin, xsol;
	while(scanf("%d", &n) == 1 && n) {
		for(int i = 0; i < n; i++) {
			scanf("%lf %lf", &P[i].x, &P[i].y);
			if(!i) xmax = xmin = P[i].x;
			else {
				if(xmax < P[i].x) xmax = P[i].x;
				if(xmin > P[i].x) xmin = P[i].x;
			}
		}
		xsol = ternary(xmin, xmax);
		printf("%.9lf %.9lf\n", xsol + EPS, sqrt(cost(xsol)) + EPS);
	}
	return 0;
}