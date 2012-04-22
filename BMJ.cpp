/*
USER: zobayer
TASK: BMJ
ALGO: ad-hoc
*/

#include <cstdio>
#include <cmath>
using namespace std;

int main() {
	int n, x, y, r;
	while(scanf("%d",&n)==1) {
		r = x = (-3+(int)sqrt(12*n-3))/6, y = 0;
		n -= 3*r*r + 3*r + 1;
		if(n==0) {
			printf("%d %d\n",x,y);
			continue;
		}
		n--, y++;
		if(n==0) {
			printf("%d %d\n",x,y);
			continue;
		}
		if(n <= r) {
			x -= n, y += n;
			printf("%d %d\n",x,y);
			continue;
		}
		x = 0, y = r+1, n -= r;
		if(n <= r+1) {
			x -= n;
			printf("%d %d\n",x,y);
			continue;
		}
		x = -r-1, n -= r+1;
		if(n <= r+1) {
			y -= n;
			printf("%d %d\n",x,y);
			continue;
		}
		y = 0, n -= r+1;
		if(n <= r+1) {
			x += n, y -= n;
			printf("%d %d\n",x,y);
			continue;
		}
		x = 0, y = -r-1, n -= r+1;
		if(n <= r+1) {
			x += n;
			printf("%d %d\n",x,y);
			continue;
		}
		x = r+1, n -= r+1;
		y += n;
		printf("%d %d\n",x,y);
	}
	return 0;
}
