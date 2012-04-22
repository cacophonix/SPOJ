/*
USER: zobayer
TASK: NY10B
ALGO: ad-hoc
*/

#include <cstdio>
using namespace std;

void d2b(int b, int n, int* num, int &len) {
	len = 0;
	while(n) {
		num[len++] = n % b;
		n /= b;
	}
}

void b2d(int b, int *num, int len, int &n) {
	int m , i;
	n = 0;
	for(m = 1, n = i = 0; i < len; i++) {
		n += num[i] * m;
		m *= b;
	}
}

void nim(int *num1, int &len1, int *num2, int len2, int b) {
	int i, x, y, len = len1>len2?len1:len2;
	for(i = 0; i < len; i++) {
		x = i < len1? num1[i]:0;
		y = i < len2? num2[i]:0;
		num1[i] = (x + y) % b;
	}
	len1 = i;
}

int nimsum(int b, int x, int y) {
	int num1[32], num2[32], len1, len2, ret;
	d2b(b, x, num1, len1);
	d2b(b, y, num2, len2);
	nim(num1, len1, num2, len2, b);
	b2d(b, num1, len1, ret);
	return ret;
}

int main() {
	int test, cs, b, x, y;
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d %d %d", &cs, &b, &x, &y);
		printf("%d %d\n", cs, nimsum(b, x, y));
	}
	return 0;
}