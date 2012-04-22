/*
USER: zobayer
TASK: SKYLINE
ALGO: big integer
*/

#include <stdio.h>

char ans[1001][600];
int save[1001];
int n, last;

int div(char *num, char *res, int d) {
	int i, k, f, a, mod, div;
	for(f = i = mod = k = 0; num[i]; i++) {
		a = (mod * 10 + num[i] - '0');
		div = a / d;
		mod = a % d;
		if(div) f = 1;
		if(f) res[k++] = div + '0';
	}
	if(!k) res[k++] = '0';
	res[k] = 0;
	last = k;
	return mod;
}

void mul(char *num, char *res, int m) {
	int i, k = 0, a, carry = 0, j, t;
	for(i = last - 1; i >= 0 || carry; i--) {
		a = ( i >= 0? num[i]-'0' : 0 ) * m  + carry;
		res[k++] = a % 10 + '0';
		carry = a / 10;
	}
	res[k] = 0;
	last = k;
	for(i = 0, j = k-1; i < j; i++, j--) {
		t = res[i]; res[i] = res[j]; res[j] = t;
	}
}

void precal() {
	char temp[600];
	ans[0][0] = ans[1][0] = '1', ans[2][0] = '2', last = 1;
	save[0] = save[1] = 1; save[2] = 2;
	for(int i = 2; i < 1000; i++) {
		mul(ans[i], ans[i+1], 4*i + 2);
		div(ans[i+1], ans[i+1], i + 2);
	}
	for(int i = 3; i <= 1000; i++) save[i] = div(ans[i], temp, 1000000);
}

int main() {
	precal();
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while(scanf("%d", &n)==1 && n) {
		printf("%d\n", save[n]);
	}
	return 0;
}