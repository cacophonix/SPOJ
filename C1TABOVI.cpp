/*
USER: zobayer
TASK: C1TABOVI
ALGO: recursion
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int INF = 0x7f7f7f7f;
int cnt, a[1000];

void equalize(int s, int e, int op) {
	int m, i, j;
	if(op==-1) {
		m = -INF;
		for(i = s; i <= e; i++) m = max(m, a[i]);
		for(i = s; i <= e; i++) a[i] -= m;
		cnt += -m;
	}
	else if(op==1) {
		m = INF;
		for(i = s; i <= e; i++) m = min(m, a[i]);
		for(i = s; i <= e; i++) a[i] -= m;
		cnt += m;
	}
	for(i = s; i <= e; i++) {
		if(!a[i]) continue;
		if(a[i] < 0) {
			j = i;
			while(j <= e && a[j] < 0) j++;
			j--;
			equalize(i, j, -1);
		}
		else {
			j = i;
			while(j <= e && a[j] > 0) j++;
			j--;
			equalize(i, j, 1);
		}
		i = j;
	}
}

int main() {
	int b, n, i;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	for(i = 0; i < n; i++) {
		scanf("%d", &b);
		a[i] -= b;
	}
	cnt = 0;
	equalize(0, n-1, 0);
	printf("%d\n", cnt);
	return 0;
}