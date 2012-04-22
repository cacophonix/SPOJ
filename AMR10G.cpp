/*
USER: zobayer
TASK: AMR10G
ALGO: sorting
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int t, n, k, i, diff, mindiff;
	int a[20000];
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &n, &k);
		for(i = 0; i < n; i++) scanf("%d", &a[i]);
		sort(a, a + n);
		mindiff = a[k-1] - a[0];
		for(i = 0; i + k <= n; i++) {
			diff = a[i+k-1] - a[i];
			mindiff = min(diff, mindiff);
		}
		printf("%d\n", mindiff);
	}
	return 0;
}