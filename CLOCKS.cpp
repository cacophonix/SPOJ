/*
USER: zobayer
PROG: CLOCKS
ALGO: pre-calculation
*/

#include <cstdio>
using namespace std;

int type[9];
int moves[9][9] = {
	{3,3,3,3,3,2,3,2,0},
	{2,3,2,3,2,3,1,0,1},
	{3,3,3,2,3,3,0,2,3},
	{2,3,1,3,2,0,2,3,1},
	{2,3,2,3,1,3,2,3,2},
	{1,3,2,0,2,3,1,3,2},
	{3,2,0,3,3,2,3,3,3},
	{1,0,1,3,2,3,2,3,2},
	{0,2,3,2,3,3,3,3,3}
};

int main() {
	int i, j, k;
	for(i=0;i<9;i++) {
		scanf("%d",&k);
		switch(k) {
			case 0: k =12; break;
			case 1: k = 3; break;
			case 2: k = 6; break;
			case 3: k = 9; break;
		}
		for(j=0;j<9;j++) type[j] = (type[j]+(4-k/3)*moves[i][j])%4;
	}
	for(i=0;i<9;i++) {
		for(j=0;j<type[i];j++) {
			if(!(i+j)) printf("%d",i+1);
			else printf(" %d",i+1);
		}
	}
	printf("\n");
	return 0;
}
