/*
USER: zobayer
TASK: CPCRC1C
ALGO: math
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long i64;
const i64 p10[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

void countdigits(char *num, int p, i64 *cnt) {
	int i, now, last;
	if(!p) {
		for(i = 0; i <= *num-'0'; i++) cnt[i]++;
		return;
	}
	for(i = 0; i < *num-'0'; i++) cnt[i] += p10[p];
	for(i = 0; i < 10; i++) cnt[i] += (i64)(*num-'0') * p * p10[p-1];
	last = (*num - '0') * p10[p];
	sscanf(num, "%d", &now);
	cnt[*num-'0'] += now - last + 1;
	countdigits(&num[1], p-1, cnt);
}

int main() {
	int n1, n2, i;
	i64 cnt1[10], cnt2[10], ans;
	char s1[11], s2[11];
	while(scanf("%d %d", &n1, &n2)==2 && n1>-1) {
		memset(cnt1, 0, sizeof cnt1); // n1-1
		memset(cnt2, 0, sizeof cnt2); // n2
		if(n1 > 1) {
			sprintf(s1, "%d", n1-1);
			countdigits(s1, strlen(s1)-1, cnt1);
		}
		if(n2 > 0) {
			sprintf(s2, "%d", n2);
			countdigits(s2, strlen(s2)-1, cnt2);
		}
		for(ans = 0, i = 1; i < 10; i++) ans += (cnt2[i] - cnt1[i]) * i;
		printf("%lld\n", ans);
	}
	return 0;
}