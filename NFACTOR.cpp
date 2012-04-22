/*
USER: zobayer
TASK: NFACTOR
ALGO: math
*/

#include <cstdio>
using namespace std;

const int MAX = 1000001;
const int LMT = 1000;
int cnt[MAX];
int pre[MAX][11];

void sieve() {
	int i, j;
	cnt[2] = 1;
	for(i = 4; i < MAX; i+=2) cnt[i]++;
	for(i = 3; i < MAX; i+=2) {
		if(!cnt[i]) {
			cnt[i] = 1;
			for(j = i<<1; j < MAX; j+=i) cnt[j]++;
		}
	}
	for(i = 1; i < MAX; i++) {
		for(j = 0; j < 11; j++) {
			if(cnt[i]==j) pre[i][j] = pre[i-1][j] + 1;
			else pre[i][j] = pre[i-1][j];
		}
	}
}

int main() {
	int t, a, b, n;
	sieve();
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d", &a, &b, &n);
		printf("%d\n", pre[b][n] - pre[a-1][n]);
	}
	return 0;
}