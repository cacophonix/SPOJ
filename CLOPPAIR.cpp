/*
USER: zobayer
TASK: CLOPPAIR
ALGO: divide and conquer
*/

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long i64;
typedef struct { int x, y, i; } Point;

const int MAX = 56384;
const i64 INF = 1LL<<60;
const double EPS = 1e-9;

int flag[MAX];

inline i64 sq(const i64 &x) {
	return x*x;
}

inline i64 sqdist(const Point &a, const Point &b) {
	return sq(a.x-b.x) + sq(a.y-b.y);
}

inline bool byX(const Point &a, const Point &b) {
	return ((a.x==b.x)? a.y < b.y : a.x < b.x);
}

inline bool byY(const Point &a, const Point &b) {
	return ((a.y==b.y)? a.x < b.x : a.y < b.y);
}

inline void presort(Point *P, Point *X, Point *Y, int n) {
	for(int i = 0; i < n; i++) X[i] = Y[i] = P[i];
	sort(X, X+n, byX);
	sort(Y, Y+n, byY);
}

inline i64 closestPair(Point *X, Point *Y, int n, int &px, int &py) {
	if(n == 1) return INF;
	if(n == 2) {
		px = X[0].i, py = X[1].i;
		return sqdist(X[0], X[1]);
	}

	int i, j, k, n1, n2, ns, m = n >> 1, px1, py1, px2, py2;
	Point Xm = X[m-1], *XL, *XR, *YL, *YR, *YS;
	XL = new Point[m], YL = new Point[m];
	XR = new Point[m+1], YR = new Point[m+1];
	YS = new Point[n];
	i64 lt, rt, dd, tmp;

	for(i = 0; i < m; i++) XL[i] = X[i], flag[X[i].i] = 0;
	for(; i < n; i++) XR[i - m] = X[i], flag[X[i].i] = 1;
	for(i = n2 = n1 = 0; i < n; i++) {
		if(!flag[Y[i].i]) YL[n1++] = Y[i];
		else YR[n2++] = Y[i];
	}

	lt = closestPair(XL, YL, n1, px1, py1);
	rt = closestPair(XR, YR, n2, px2, py2);
	if(lt < rt) dd = lt, px = px1, py = py1;
	else dd = rt, px = px2, py = py2;

	for(i = ns = 0; i < n; i++)
		if(sq(Y[i].x - Xm.x) < dd)
			YS[ns++] = Y[i];
	for(j = 0; j < ns; j++) {
		for(k = j + 1; k < ns && sq(YS[k].y - YS[j].y)+EPS < dd; k++) {
			tmp = sqdist(YS[j], YS[k]);
			if(dd > tmp) {
				dd = tmp;
				px = YS[j].i, py = YS[k].i;
			}
		}
	}

	delete[] XL; delete[] XR;
	delete[] YL; delete[] YR;
	delete[] YS;
	return dd;
}

Point P[MAX], X[MAX], Y[MAX];

int main() {
	int i, n, px, py;
	i64 ret;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &P[i].x, &P[i].y);
		P[i].i = i;
	}
	presort(P, X, Y, n);
	ret = closestPair(X, Y, n, px, py);
	if(px > py) swap(px, py);
	printf("%d %d %.6lf\n", px, py, sqrt((double)ret) + 1e-9);
	return 0;
}