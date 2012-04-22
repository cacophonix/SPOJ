/*
USER: zobayer
TASK: BOI7SEQ
ALGO: stack
*/

#include <cstdio>
using namespace std;

typedef long long i64;

const int MAX = 1000000;
const int BUFF = 8000000;
const int INF = 0x7f7f7f7f;

static char buff[BUFF], *ptr = buff;
static int Stack[MAX], top;

inline int min(int a, int b) {
	return (a < b? a : b);
}

inline int nextInt() {
	int ret = 0;
	while(*ptr < '0' || *ptr > '9') ptr++;
	do { ret = ret * 10 + *ptr++ - '0';
	} while(*ptr >= '0' && *ptr <= '9');
	return ret;
}

int main() {
	int n, i, a;
	i64 res = 0;
	fread_unlocked(buff, BUFF, 1, stdin);
	n = nextInt();
	Stack[top++] = INF;
	for(i = 0; i < n; i++) {
		a = nextInt();
		while(Stack[top-1] <= a) {
			top--;
			res += min(Stack[top-1], a);
		}
		Stack[top++] = a;
	}
	for(i = 1; i < top - 1; i++) res += Stack[i];
	printf("%lld\n", res);
	return 0;
}
