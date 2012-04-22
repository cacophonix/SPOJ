/*
USER: zobayer
TASK: MRECT1
ALGO: binary search
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 300003;
const int BUFF = 10500000;
struct Point { int x, y; };

Point px[MAX], py[MAX];
static char buff[BUFF], *ptr = buff;

inline bool sortX(const Point &a, const Point &b) {
	return (a.x == b.x)? a.y < b.y : a.x < b.x;
}

inline bool sortY(const Point &a, const Point &b) {
	return (a.y == b.y)? a.x < b.x : a.y < b.y;
}

inline int get(const Point &p, char c) {
	return (c=='x')? p.x : p.y;
}

int lowerBound(char c, Point *p, int a, int b, int v) {
	int cnt = b - a, stp, i;
	while(cnt > 0) {
		stp = cnt >> 1;
		i = a + stp;
		if(get(p[i], c) < v) a = ++i, cnt -= stp+1;
		else cnt = stp;
	}
	return a;
}

int upperBound(char c, Point *p, int a, int b, int v) {
	int cnt = b - a, stp, i;
	while(cnt > 0) {
		stp = cnt >> 1;
		i = a + stp;
		if(get(p[i], c) <= v) a = ++i, cnt -= stp+1;
		else cnt = stp;
	}
	return a;
}

inline int nextInt() {
	int ret = 0;
	while(*ptr < '0' || *ptr > '9') *ptr++;
	do { ret = ret * 10 + *ptr++ - '0';
	} while('0'<=*ptr && *ptr<='9');
	return ret;
}

int main() {
	int n, i, q, x1, y1, x2, y2, cnt, lb, ub, rl, rr;
	fread_unlocked(buff, BUFF, 1, stdin);
	n = nextInt();
	for(i = 0; i < n; i++) {
		px[i].x = py[i].x = nextInt();
		px[i].y = py[i].y = nextInt();
	}
	sort(px, px + n, sortX);
	sort(py, py + n, sortY);
	q = nextInt();
	while(q--) {
		x1 = nextInt();
		y1 = nextInt();
		x2 = nextInt();
		y2 = nextInt();

		cnt = 0;
		lb = lowerBound('y', py, 0, n, y1);
		ub = upperBound('y', py, lb, n, y1);
		rl = lowerBound('x', py, lb, ub, x1);
		rr = upperBound('x', py, rl, ub, x2) - 1;
		if(rr - rl + 1 > 0) cnt += rr - rl + 1;

		lb = lowerBound('y', py, 0, n, y2);
		ub = upperBound('y', py, lb, n, y2);
		rl = lowerBound('x', py, lb, ub, x1);
		rr = upperBound('x', py, rl, ub, x2) - 1;
		if(rr - rl + 1 > 0) cnt += rr - rl + 1;

		lb = lowerBound('x', px, 0, n, x1);
		ub = upperBound('x', px, lb, n, x1);
		rl = lowerBound('y', px, lb, ub, y1+1);
		rr = upperBound('y', px, rl, ub, y2-1) - 1;
		if(rr - rl + 1 > 0) cnt += rr - rl + 1;

		lb = lowerBound('x', px, 0, n, x2);
		ub = upperBound('x', px, lb, n, x2);
		rl = lowerBound('y', px, lb, ub, y1+1);
		rr = upperBound('y', px, rl, ub, y2-1) - 1;
		if(rr - rl + 1 > 0) cnt += rr - rl + 1;
		printf("%d\n", cnt);
	}
	return 0;
}
