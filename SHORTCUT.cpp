/*
USER: zobayer
TASK: SHORTCUT
ALGO: sweep
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct Point { int x, y, i; };

const int MAX = 250016, INF = 0x7f7f7f7f;
Point P[MAX], T[MAX];
char buff[MAX];
int bestfrom, bestto, bestdist;

inline bool sortX(const Point &a, const Point &b) {
	return ((a.x==b.x)? a.y < b.y : a.x < b.x);
}

inline bool sortY(const Point &a, const Point &b) {
	return ((a.y==b.y)? a.x < b.x : a.y < b.y);
}

void scanX(int n) {
	int from, to, dist, i;
	sort(T, T+n, sortX);
	for(i = 1; i < n; i++) {
		if(T[i-1].x==T[i].x && abs(T[i-1].i - T[i].i) > 1) {
			dist = abs(T[i-1].y - T[i].y);
			from = min(T[i-1].i, T[i].i);
			to = max(T[i-1].i, T[i].i);
			if(dist > bestdist) continue;
			if(dist==bestdist) {
				if(from > bestfrom) continue;
				if(from==bestfrom && to <= bestto) continue;
			}
			bestdist = dist;
			bestfrom = from;
			bestto = to;
		}
	}
}

void scanY(int n) {
	int from, to, dist, i;
	sort(T, T+n, sortY);
	for(i = 1; i < n; i++) {
		if(T[i-1].y==T[i].y && abs(T[i-1].i - T[i].i) > 1) {
			dist = abs(T[i-1].x - T[i].x);
			from = min(T[i-1].i, T[i].i);
			to = max(T[i-1].i, T[i].i);
			if(dist > bestdist) continue;
			if(dist==bestdist) {
				if(from > bestfrom) continue;
				if(from==bestfrom && to <= bestto) continue;
			}
			bestdist = dist;
			bestfrom = from;
			bestto = to;
		}
	}
}

int main() {
	int t, n, i;
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	t = atoi(fgets(buff, MAX, stdin));
	while(t--) {
		n = atoi(fgets(buff, MAX, stdin));
		fgets(buff, MAX, stdin);
		P[0].x = P[0].y = P[0].i = 0; T[0] = P[0];
		bestdist = INF; bestto = -INF; bestfrom = INF;
		for(i = 1; i <= n; i++) {
			switch(buff[i-1]) {
				case 'N': P[i].x = P[i-1].x; P[i].y = P[i-1].y+1; P[i].i = i; break;
				case 'S': P[i].x = P[i-1].x; P[i].y = P[i-1].y-1; P[i].i = i; break;
				case 'E': P[i].x = P[i-1].x+1; P[i].y = P[i-1].y; P[i].i = i; break;
				case 'W': P[i].x = P[i-1].x-1; P[i].y = P[i-1].y; P[i].i = i; break;
			}
		}
		for(i = 1; i <= n; i++) T[i] = P[i];
		scanY(n + 1);
		scanX(n + 1);
		printf("%d %d %d ", bestdist, bestfrom, bestto);
		if(P[bestfrom].x < P[bestto].x) printf("E\n");
		if(P[bestfrom].x > P[bestto].x) printf("W\n");
		if(P[bestfrom].y < P[bestto].y) printf("N\n");
		if(P[bestfrom].y > P[bestto].y) printf("S\n");
	}
	return 0;
}
