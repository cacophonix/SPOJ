/*
USER: zobayer
TASK: RPLL
ALGO: binary search
*/

#include <cstdio>

typedef long long i64;

struct point {
	i64 x, y, dx, dy;
	point() {}
	point(i64 _x, i64 _y, i64 _dx, i64 _dy) : x(_x), y(_y), dx(_dx), dy(_dy) {}
	point after(int t) { return point(x + dx * t, y + dy * t, dx, dy); }
};

point p[3];

inline i64 triArea(const point &a, const point &b, const point &c) {
	i64 d = a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y);
	return d < 0 ? -d : d;
}

inline i64 fun(int dt) {
	return triArea(p[0].after(dt), p[1].after(dt), p[2].after(dt));
}

int main() {
	int test, cs, x, y, dx, dy, speed, i, ans, dt;
	i64 mx_area;
	char dir[8];
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lld", &mx_area);
		mx_area <<= 1;
		for(i = 0; i < 3; i++) {
			scanf("%d %d %s %d", &x, &y, dir, &speed);
			switch(dir[0]) {
				case 'n': dx = 0, dy = +speed; break;
				case 's': dx = 0, dy = -speed; break;
				case 'e': dx = +speed, dy = 0; break;
				case 'w': dx = -speed, dy = 0; break;
			}
			p[i] = point(x, y, dx, dy);
		}
		ans = 0;
		while(true) {
			for(dt = 1; fun(dt) <= mx_area; dt <<= 1); dt >>= 1;
			if(!dt) break;
			for(i = 0; i < 3; i++) p[i] = p[i].after(dt);
			ans += dt;
		}
		printf("Scenario #%d: %d\n", cs, ans);
	}
	return 0;
}
