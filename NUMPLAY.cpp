/*
USER: zobayer
TASK: NUMPLAY
ALGO: dynamic programming
*/

#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct { char s[1734]; int len; } Big;

const Big ONE = (Big){"1", 1};
const Big ZERO = (Big){"0", 1};

void add(const Big &a, const Big &b, Big &c) {
	int i, j, k, carry, x, y;
	for(i = j = carry = k = 0; i < a.len || j < b.len || carry; i++, j++, k++) {
		x = (i < a.len) ? a.s[i] - '0' : 0;
		y = (j < b.len) ? b.s[j] - '0' : 0;
		c.s[k] = (x + y + carry) % 10 + '0';
		carry = (x + y + carry) / 10;
	}
	c.s[c.len = k] = 0;
}

void solve(int n) {
	if(n == 0) puts("0");
	else if(n == 1) puts("4");
	else {
		Big n1, n3, n5, n7, p1, p3, p5, p7;
		p1 = p3 = p5 = p7 = ONE;
		for(int i = 2; i <= n; i++) {
			n1 = p3;
			add(p1, p7, n3);
			add(p3, p7, n5);
			n7 = p5;
			p1 = n1, p3 = n3, p5 = n5, p7 = n7;
		}
		add(n1, n3, p1);
		add(n5, n7, p3);
		add(p1, p3, p5);
		reverse(p5.s, p5.s + p5.len);
		puts(p5.s);
	}
}

int main() {
	int test, n;
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		solve(n);
	}
	return 0;
}
