/*
USER: zobayer
TASK: BRODOVI
ALGO: ad-hoc
*/

#include <cstdio>
#include <cstring>
using namespace std;

int a[5000];
bool f[5000];

int main() {
	int i, j, d, n, last, cnt = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	for(i = 1; i < n; i++) {
		if(!f[i]) {
			f[i] = 1;
			d = a[i] - 1;
			last = a[i];
			cnt++;
			for(j = i + 1; j < n; j++) {
				if(last + d == a[j]) {
					f[j] = 1;
					last = a[j];
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}