/*
USER: zobayer
TASK: MBEEWALK
ALGO: math
*/

#include <ios>

//http: // www.research.att.com / ~njas / sequences / A002898

int a[] = {1, 0, 6, 12, 90, 360, 2040, 10080, 54810, 290640, 1588356, 8676360, 47977776, 266378112, 1488801600};

int main() {
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		printf("%d\n", a[n]);
	}
	return 0;
}