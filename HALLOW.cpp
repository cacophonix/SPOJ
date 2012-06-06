/*
USER: zobayer
TASK: HALLOW
ALGO: pegionhole principle
*/

#include <cstdio>
#include <cstring>

int arr[120000], flag[120000], u[120000];

int main() {
	int n, m, i, x, total, g, mn, a, b;
	while(scanf("%d %d",&n,&m) == 2 && (n | m)) {
		memset(arr, 0, sizeof arr);
		memset(flag, 0, sizeof flag);
		mn = 120000, total = 0, arr[0] = 0, flag[0] = 1;
		for(i = 1; i < m + 1; i++) scanf("%d", &u[i]);
		for(i = 1; i < m + 1; i++) {
			g = i, x = u[i], total += x, total %= n;
			if(flag[total]) {
				if(i - arr[total] < mn) {
					mn = arr[total];
					a = arr[total] + 1, b = i;
				}
			}
			arr[total] = i, flag[total] = 1;
		}
		for(i = a; i < b; i++) printf("%d ", i); printf("%d\n", i);
	}
	return 0;
}  
