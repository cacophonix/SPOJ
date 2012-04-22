/*
USER: zobayer
TASK: MARTIAN
ALGO: dynamic programming
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int BUFF = 1 << 21;

int yeyenum[512][512], bloggium[512][512], maximum[512][512];
static char buff[BUFF], *ptr = buff;

#define nextint(n) n=0;while(*ptr<48)ptr++;do{n=n*10+*ptr++-48;}while(*ptr>=48)

int main() {
	int i, j, sum, pre, R, C;
	//freopen("in.txt", "r", stdin);
	fread_unlocked(buff, 1, BUFF, stdin);
	while(true) {
		nextint(R);
		nextint(C);
		if(R==0 && C==0) break;
		for(i = 0; i < R; i++) {
			for(j = 0; j < C; j++) {
				nextint(yeyenum[i][j]);
			}
		}
		for(i = 0; i < R; i++) {
			for(j = 0; j < C; j++) {
				nextint(bloggium[i][j]);
			}
		}
		for(i = 0; i < R; i++) {
			for(sum = j = 0; j < C; j++) {
				sum += bloggium[i][j];
			}
			pre = i > 0? maximum[i-1][0] : 0;
			maximum[i][0] = pre + sum;
			for(j = 1; j <= C; j++) {
				sum += yeyenum[i][j-1] - bloggium[i][j-1];
				pre = i > 0? max(pre, maximum[i-1][j]) : 0;
				maximum[i][j] = pre + sum;
			}
		}
		for(j = 1, sum = maximum[i-1][0]; j <= C; j++) {
			sum = max(sum, maximum[i-1][j]);
		}
		printf("%d\n", sum);
	}
	return 0;
}