/*
USER: zobayer
TASK: GCPC11B
ALGO: dynamic programming
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>

bool check(char *s1, char *s2, int len) {
	int i, j, k, ret, dp[2][1024];
	for(i = 1, ret = 0; i <= len; i++) {
		for(k = i & 1, j = 1; j <= len; j++) {
			if(abs(s1[i-1]-s2[j-1]) <= 1) {
				if(i == 1 || j == 1) dp[k][j] = 1;
				else dp[k][j] = dp[k^1][j-1] + 1;
				if(dp[k][j] > ret) ret = dp[k][j];
			}
			else dp[k][j] = 0;
		}
	}
	return ret >= (len+1)>>1;
}

int main() {
	int test, len;
	char tmp[8], s1[1024], s2[1024], res[2][10] = {"NEGATIVE", "POSITIVE"};
	//freopen("in.txt", "r", stdin);
	test = atoi(fgets(tmp, 7, stdin));
	while(test--) {
		len = atoi(fgets(tmp, 7, stdin)); 
		fgets(s1, 1023, stdin);
		fgets(s2, 1023, stdin);
		puts(res[check(s1, s2, len)]);
	}
	return 0;
}
