/*
USER: zobayer
TASK: JNEXT
ALGO: ad-hoc
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 1000000;

int a[MAX], cnt[10];

int main() {
	int test, i, j, k, n;
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) scanf("%d", &a[i]);
		memset(cnt, 0, sizeof(int) * 10);
		for(i = n - 1; i >= 0; i--) {
			cnt[a[i]]++;
			for(j = a[i]+1; j < 10; j++) if(cnt[j]) break;
			if(j < 10) {
				a[i] = j; cnt[j]--;
				for(j = 0, k = i+1; j < 10; j++) while(cnt[j]--) a[k++] = j;
				break;
			}
		}
		if(i >= 0) {
			for(i = 0; i < n; i++) printf("%d", a[i]);
			printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}
