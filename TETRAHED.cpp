/*
USER: zobayer
TASK: TETRAHED
ALGO: geometry
*/

#include <cstdio>

typedef struct { int x, y, z; } Point;
typedef long long i64;

inline i64 calc(const Point &a, const Point &b, const Point &c, const Point &d) {
	i64 usq, vsq, wsq, Usq, Vsq, Wsq, u1, v1, w1;
	usq = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z);
	vsq = (a.x-c.x)*(a.x-c.x) + (a.y-c.y)*(a.y-c.y) + (a.z-c.z)*(a.z-c.z);
	wsq = (a.x-d.x)*(a.x-d.x) + (a.y-d.y)*(a.y-d.y) + (a.z-d.z)*(a.z-d.z);
	Usq = (c.x-d.x)*(c.x-d.x) + (c.y-d.y)*(c.y-d.y) + (c.z-d.z)*(c.z-d.z);
	Vsq = (b.x-d.x)*(b.x-d.x) + (b.y-d.y)*(b.y-d.y) + (b.z-d.z)*(b.z-d.z);
	Wsq = (b.x-c.x)*(b.x-c.x) + (b.y-c.y)*(b.y-c.y) + (b.z-c.z)*(b.z-c.z);
	u1 = vsq + wsq - Usq; v1 = wsq + usq - Vsq; w1 = usq + vsq - Wsq;
	return 4*usq*vsq*wsq - u1*u1*usq - v1*v1*vsq - w1*w1*wsq + u1*v1*w1;
}

int main() {
	int test, i;
	Point p[5];
	i64 res[5];
	scanf("%d", &test);
	while(test--) {
		for(i = 0; i < 5; i++) scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].z);
		res[0] = calc(p[1], p[2], p[3], p[4]); i = 0;
		res[1] = calc(p[0], p[2], p[3], p[4]); if(res[1] > res[i]) i = 1;
		res[2] = calc(p[0], p[1], p[3], p[4]); if(res[2] > res[i]) i = 2;
		res[3] = calc(p[0], p[1], p[2], p[4]); if(res[3] > res[i]) i = 3;
		res[4] = calc(p[0], p[1], p[2], p[3]); if(res[4] > res[i]) i = 4;
		printf("%d\n", i + 1);
	}
	return 0;
}
