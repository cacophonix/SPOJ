/*
USER: zobayer
TASK: MAJSTOR
ALGO: ad-hoc
*/

#include <stdio.h>
inline int add(char s, char f) {
	int t = 0;
	if(s=='R' && f=='R') t++;
	else if(s=='R' && f=='S') t+=2;
	else if(s=='P' && f=='P') t++;
	else if(s=='P' && f=='R') t+=2;
	else if(s=='S' && f=='S') t++;
	else if(s=='S' && f=='P') t+=2;
	return t;
}
int score(char *sven, char *frnd, int r) {
	int i, t;
	for(i = t = 0; i < r; i++) t += add(sven[i], frnd[i]);
	return t;
}
int main() {
	char sven[52], cards[] = "RPS", frnd[52][52];
	int n, r, i, j, k, exact = 0, known, mxknown = 0;
	scanf("%d%s%d", &r, sven, &n);
	for(i = 0; i < n; i++) {
		scanf("%s", frnd[i]);
		exact += score(sven, frnd[i], r);
	}
	printf("%d\n", exact);
	exact = 0;
	for(i = 0; i < r; i++) {
		mxknown = 0;
		for(j = 0; j < 3; j++) {
			known = 0;
			for(k = 0; k < n; k++) {
				known += add(cards[j], frnd[k][i]);
			}
			if(known > mxknown) mxknown = known;
		}
		exact += mxknown;
	}
	printf("%d\n", exact);
	return 0;
}