/*
USER: zobayer
TASK: IKEYB
ALGO: dynamic programming
*/

#include <cstdio>
#include <cstring>

const int MAX = 100;
const int INF = 0x3f3f3f3f;

int dp[MAX][MAX], path[MAX][MAX], cost[MAX], K, L;
char letters[MAX], keys[MAX];

int solve(int key, int letter) {
	if(letter == L) return 0;
	if(key == K) return INF;
	if(dp[key][letter] != -1) return dp[key][letter];
	int &ret = dp[key][letter]; ret = INF;
	for(int tmp, sum = 0, i = letter; i < L; i++) {
		sum += cost[i] * (i -letter + 1);
		tmp = sum + solve(key + 1, i + 1);
		if(ret > tmp) {
			ret = tmp;
			path[key][letter] = i;
		}
	}
	return ret;
}

int main() {
	int test, cs, i, key, letter;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d %s %s", &K, &L, keys, letters);
		for(i = 0; i < L; i++) scanf("%d", cost + i);
		memset(dp, -1, sizeof dp);
		solve(0, 0);
		printf("Keypad #%d:\n", cs);
		for(key = letter = 0; key < K; key++) {
			printf("%c: ", keys[key]);
			for(i = letter; i <= path[key][letter]; i++) putchar(letters[i]);
			letter = path[key][letter] + 1; puts("");
		}
		puts("");
	}
	return 0;
}
