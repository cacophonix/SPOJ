/*
USER: zobayer
TASK: GCPC11F
ALGO: ad-hoc
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>

char str[1024];
int cnt[26];

int main() {
	int test, i, mx, mc, d;
	test = atoi(fgets(str, 1023, stdin));
	while(test--) {
		fgets(str, 1023, stdin);
		memset(cnt, 0, sizeof cnt);
		for(i = 0; str[i]>31; i++) if(str[i]>32) cnt[str[i]-'A']++;
		for(mx = 0, mc = 1, i = 1; i < 26; i++) {
			if(cnt[i] > cnt[mx]) mx = i, mc = 1;
			else if(cnt[i] == cnt[mx]) mc++;
		}
		if(mc > 1) fputs("NOT POSSIBLE\n", stdout);
		else {
			if(mx >= 4) d = mx - 4;
			else d = 26 - 4 + mx;
			printf("%d ", d);
			for(i = 0; str[i]>31; i++) if(str[i]>32) str[i] = 'A' + (str[i]-'A' - d + 26) % 26;
			fputs(str, stdout);
		}
	}
	return 0;
}
