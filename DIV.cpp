/*
USER: zobayer
TASK: DIV
ALGO: math
*/

#include <iostream>
using namespace std;

const int MAX = 1000000, LMT = 1000, LEN = 78500;
int small[MAX+10];

void smallest() {
	int i, j, k;
	for(i=2; i<=MAX; i++) small[i] = ((i&1)==0)? 2 : i;
	for(i=3; i<=LMT; i+=2)
		if(small[i]==i)
			for(j=i; j<=MAX; j+=i)
				if(small[j]==j)
					small[j] = i;
}

int dn(int n) {
	int prv=0, cnt=0, res=1;
	while(n>1) {
		if(small[n]!=prv) {
			res *= (cnt+1);
			prv = small[n];
			cnt = 1;
		}
		else cnt++;
		n /= small[n];
	}
	return res*(cnt+1);
}

int main() {
	smallest();
	int d, i, p, q, cnt;
	freopen("out.txt", "w", stdout);
	for(i=2; i<=MAX; i++) {
		d = dn(i);
		p = small[d];
		if(p==d) continue;
		q = small[d/p];
		if(q==p || q!=d/p) continue;
		cnt++;
		if(cnt%9==0) printf("%d\n", i);
	}
	return 0;
}
