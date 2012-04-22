/*
USER: zobayer
TASK: MBINGO
ALGO: ad-hoc
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main() {
	int a[92], n, r, i, j;
	char f[92];
	while(scanf("%d%d", &n, &r)==2 && n) {
		memset(f, 0, sizeof f);
		for(i = 0; i < r; i++) scanf("%d", &a[i]);
		for(i = 0; i < r; i++)
			for(j = 0; j < r; j++)
				f[abs(a[i]-a[j])] = 1;
		for(i = 0; i <= n && f[i]; i++);
		if(i==n+1) puts("Y");
		else puts("N");
	}
	return 0;
}