/*
USER: zobayer
TASK: BABTWR
ALGO: dp
*/

#include <stdio.h>
#include <string.h>

#define MAX 111

struct boxtype {int x, y, z;} box[MAX];
int dp[MAX], total;

int solve(int i) {
	if(dp[i]) return dp[i];
	int h, maxh, b;
	for(maxh=b=0; b<total; b++)
		if(box[b].x < box[i].x && box[b].y < box[i].y)
			if((h=solve(b))>maxh)
				maxh = h;
	return dp[i] = maxh + box[i].z;
}

int main() {
	int n, i, k, x, y, z, h, maxh;
	while(scanf("%d", &n)==1 && n) {
		memset(dp, 0, sizeof(dp));
		for(i=k=0; i<n; i++) {
			scanf("%d%d%d", &x, &y, &z);
			box[k++] = (x<y)? (boxtype){x,y,z}:(boxtype){y,x,z};
			box[k++] = (x<z)? (boxtype){x,z,y}:(boxtype){z,x,y};
			box[k++] = (y<z)? (boxtype){y,z,x}:(boxtype){z,y,x};
		}
		total = k;
		for(i=maxh=0; i<total; i++)
			if((h=solve(i))>maxh)
				maxh = h;
		printf("%d\n", maxh);
	}
	return 0;
}
