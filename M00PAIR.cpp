/*
USER: zobayer
TASK: M00PAIR
ALGO: big integer
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Big {
	int len, rev;
	char num[1000];
} ans[1000];

void shl(Big &a, Big &r) {
	int v, k, i;
	for(i = v = k = 0; i < a.len || v; i++, k++) {
		v += (i < a.len? a.num[i]-'0' : 0) << 1;
		r.num[k] = v % 10 + '0'; v /= 10;
	}
	r.num[k] = 0, r.rev = 1, r.len = k;
}

void add(Big &a, Big &b, Big &r) {
	int i, j, k, v;
	for(i = j = k = v = 0; i < a.len || j < b.len || v; i++, j++, k++) {
		v += (i < a.len? a.num[i]-'0' : 0) + (j < b.len? b.num[j]-'0' : 0);
		r.num[k] = v % 10 + '0'; v /= 10;
	}
	r.num[k] = 0, r.rev = 1, r.len = k;
}

int main() {
	int i, n;
	Big temp;
	ans[0].len = ans[0].rev = ans[1].len = ans[1].rev = 1;
	ans[0].num[0] = '0'; ans[1].num[0] = '1';
	ans[0].num[1] = ans[1].num[1] = 0;
	for(i = 2; i < 1000; i++) {
		shl(ans[i-2], temp);
		add(ans[i-1], temp, ans[i]);
	}
	while(scanf("%d", &n)==1) {
		n--;
		if(ans[n].rev) {
			ans[n].rev = 0;
			reverse(ans[n].num, ans[n].num+ans[n].len);
		}
		puts(ans[n].num);
	}
	return 0;
}