/*
USER: zobayer
TASK: PROBLEM
ALGO: ad-hoc
*/

#include <cstdio>

int mp[10] = {1, 0, 0, 0, 0, 0, 1, 0, 2, 1};

int main() {
	int test, i, j;
	char num[128];
	scanf("%d", &test);
	while(test--) {
		scanf("%s", num);
		for(i = j = 0; num[i]; i++) j += mp[num[i]-'0'];
		printf("%d\n", j);
	}
	return 0;
}
