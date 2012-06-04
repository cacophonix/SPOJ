/*
USER: zobayer
TASK: SPOINTS
ALGO: computational geometry
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct { int x, y; } point;

const int MAX = 128;

point P0;

inline int triArea2(const point &a, const point &b, const point &c) {
	return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}

inline int sqDist(const point &a, const point &b) {
	return ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

inline bool comp(const point &a, const point &b) {
	int d = triArea2(P0, a, b);
	if(d < 0) return false;
	if(!d && sqDist(P0, a) > sqDist(P0, b)) return false;
	return true;
}

void convexHull(point *P, int &np, point *C, int &nc) {
	int i, j, pos = 0;
	for(i = 1; i < np; i++)
		if(P[i].y<P[pos].y || (P[i].y==P[pos].y && P[i].x<P[pos].x))
			pos = i;
	swap(P[0], P[pos]);
	P0 = P[0];
	sort(&P[1], &P[np], comp);
	for(i = 0; i < 3; i++) C[i] = P[i];
	for(i = j = 3; i < np; i++) {
		while(triArea2(C[j-2], C[j-1], P[i]) < 0) j--;
		C[j++] = P[i];
	}
	nc = j;
}

inline bool onsegment(const point &p1, const point &p2, const point &p3) {
	bool x = min(p1.x, p2.x) <= p3.x && p3.x <= max(p1.x, p2.x);
	bool y = min(p1.y, p2.y) <= p3.y && p3.y <= max(p1.y, p2.y);
	return x && y;
}

inline bool intersect(const point &p1, const point &p2, const point &p3, const point &p4) {
	int d1, d2, d3, d4;
	d1 = triArea2(p3, p4, p1);
	d2 = triArea2(p3, p4, p2);
	d3 = triArea2(p1, p2, p3);
	d4 = triArea2(p1, p2, p4);
	if(((d1 < 0 && d2 > 0) || (d1 > 0 && d2 < 0)) && ((d3 < 0 && d4 > 0) || (d3 > 0 && d4 < 0))) return true;
	if(!d3 && onsegment(p1, p2, p3)) return true;
	if(!d4 && onsegment(p1, p2, p4)) return true;
	if(!d1 && onsegment(p3, p4, p1)) return true;
	if(!d2 && onsegment(p3, p4, p2)) return true;
	return false;
}

bool checkIntersect(point *pa, int na, point *pb, int nb) {
	int i, j;
	pa[na] = pa[0], pb[nb] = pb[0];
	for(i = 0; i < na; i++)
		for(j = 0; j < nb; j++)
			if(intersect(pa[i], pa[i+1], pb[j], pb[j+1]))
				return true;
	return false;
}

inline bool inConvexPoly(point *C, int nc, const point &p) {
	if(nc == 1) return C[0].x == p.x && C[0].y == p.y;
	int st = 1, en = nc - 1, mid;
	while(en - st > 1) {
		mid = (st + en)>>1;
		if(triArea2(C[0], C[mid], p) < 0) en = mid;
		else st = mid;
	}
	int d1, d2, d3;
	if((d1 = triArea2(C[0], C[st], p)) < 0) return false;
	if((d2 = triArea2(C[st], C[en], p)) < 0) return false;
	if((d3 = triArea2(C[en], C[0], p)) < 0) return false;
	if(!d1 && onsegment(C[0], C[st], p)) return true;
	if(!d2 && onsegment(C[st], C[en], p)) return true;
	if(!d3 && onsegment(C[en], C[0], p)) return true;
	return d1 > 0 && d2 > 0 && d3 > 0;
}

bool checkContained(point *pa, int na, point *pb, int nb) {
	int i, j;
	for(i = 0; i < nb; i++)
		if(inConvexPoly(pa, na, pb[i]))
			return true;
	return false;
}

int main() {
	point wp[MAX], bp[MAX], wc[MAX], bc[MAX];
	int n1, n2, i, c1, c2;
	//freopen("in.txt", "r", stdin);
	while(scanf("%d %d", &n1, &n2) == 2 && (n1 | n2)) {
		for(i = 0; i < n1; i++) scanf("%d %d", &bp[i].x, &bp[i].y);
		for(i = 0; i < n2; i++) scanf("%d %d", &wp[i].x, &wp[i].y);
		if(n1 >= 3) convexHull(bp, n1, bc, c1);
		else { memcpy(bc, bp, sizeof(point) * n1); c1 = n1; }
		if(n2 >= 3) convexHull(wp, n2, wc, c2);
		else { memcpy(wc, wp, sizeof(point) * n2); c2 = n2; }
		if(checkIntersect(bc, c1, wc, c2)) puts("NO");
		else if(checkContained(bc, c1, wc, c2)) puts("NO");
		else if(checkContained(wc, c2, bc, c1)) puts("NO");
		else puts("YES");
	}
	return 0;
}