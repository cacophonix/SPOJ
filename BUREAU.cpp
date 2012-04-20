/*
USER: zobayer
TASK: BUREAU
ALGO: ad-hoc
*/

#include <cstdio>
#include <cstring>
using namespace std;

int a[100001];
char ok[100001], buff[16000000], *ptr = buff;

inline int nextint() {
	int ret = 0;
	while(*ptr < 33) ptr++;
	do { ret = ret*10 + *ptr++ - '0'; } while(*ptr > 32);
	return ret;
}

inline char *nextstr() {
	char *str;
	while(*ptr < 33) ptr++;
	for(str = ptr; *ptr > 32; ptr++);
	return str;
}

int main() {
	int test, n, i, f;
	fread(buff, 1, 16000000, stdin);
	test = nextint();
	while(test--) {
		n = nextint();
		for(i = 1; i <= n; i++) {
			if(*nextstr()=='c') a[i] = nextint();
			else a[i] = 0;
			ok[i] = 1;
		}
		for(i = n; i; i--)
			if(a[i] && ok[i])
				ok[a[i]] = 0;
		for(f = 0, i = 1; i <= n; i++) f += ok[i];
		printf("%d\n", f);
		for(i = 1, f = 0; i <= n; i++) {
			if(ok[i]) {
				if(f++) printf(" ");
				printf("%d", i);
			}
		}
		printf("\n");
	}
	return 0;
}
