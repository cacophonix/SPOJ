/*
USER: zobayer
TASK: SAMER08E
ALGO: ad-hoc
*/

#include <cstdio>
using namespace std;

struct Date { int d, m, y; };
const int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

inline bool isLeapYear(int y) {
	return (y % 400 == 0 || (y % 100 && y % 4 == 0));
}

inline bool isNextDay(const Date &now, const Date &prev) {
	int d = 1 + prev.d, m = prev.m, y = prev.y, dm;
	dm = days[m-1] + (m==2 && isLeapYear(y));
	if(d > dm) { d = 1, m++; }
	if(m > 12) { m = 1, y++; }
	return now.d == d && now.m == m && now.y == y;
}

int main() {
	int n, i, pc, nc, tot, cnt;
	Date now, prev;
	while(scanf("%d", &n)==1 && n) {
		tot = cnt = 0;
		scanf("%d%d%d%d", &prev.d, &prev.m, &prev.y, &pc);
		for(i = 1; i < n; i++) {
			scanf("%d%d%d%d", &now.d, &now.m, &now.y, &nc);
			if(isNextDay(now, prev)) tot += nc-pc, cnt++;
			prev = now, pc = nc;
		}
		printf("%d %d\n", cnt, tot);
	}
	return 0;
}