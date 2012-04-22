/*
USER: zobayer
TASK: MIDO
ALGO: ad-hoc
*/

#include <cstdio>
using namespace std;

int main() {
	int n;
	int last;
	int p, m, s;
	int t1, t2, a1, a2;
	scanf("%d", &n);
	last = 0;
	a1 = a2 = t1 = t2 = 0;
	while(n--) {
		scanf("%d %d:%d", &p, &m, &s);
		s += m * 60;
		if(a1 > a2) t1 += s - last;
		else if(a1 < a2) t2 += s - last;
		if(p == 1) a1++;
		else if(p==2) a2++;
		last = s;
	}
	s = 2880;
	if(a1 > a2) t1 += s - last;
	else if(a1 < a2) t2 += s - last;
	if(p == 1) a1++;
	else if(p==2) a2++;
	printf("%02d:%02d\n", t1/60, t1%60);
	printf("%02d:%02d\n", t2/60, t2%60);
	return 0;
}