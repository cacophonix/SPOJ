/*
USER: zobayer
TASK: BHAT007
ALGO: ad-hoc
*/

#include <cstdio>
#include <cstring>

char num1[40], num2[40];
int nb1[110], nb2[110], len1, len2;

void add(int base, int *nb, int &k) {
	int i, j, a, b, carry;
	for(i = len1-1, j = len2-1, carry = k = 0; i >= 0 || j >= 0 || carry; i--, j--, k++) {
		a = i >= 0 ? num1[i]-'0' : 0;
		b = j >= 0 ? num2[j]-'0' : 0;
		nb[k] = (a + b + carry) % base;
		carry = (a + b + carry) / base;
	}
	while(k--) if(nb[k]) break;
}

int main() {
	int test, b1, b2, l1, l2;
	scanf("%d", &test);
	while(test--) {
		scanf("%s %s %d %d", num1, num2, &b1, &b2);
		len1 = strlen(num1);
		len2 = strlen(num2);
		add(b1, nb1, l1);
		add(b2, nb2, l2);
		if(l1 == l2 && !memcmp(nb1, nb2, l1*sizeof(int))) puts("yes");
		else puts("no");
	}
	return 0;
}
