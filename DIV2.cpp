/*
USER: zobayer
TASK: DIV2
ALGO: math
*/

#include <cstdio>
using namespace std;

const int MAX = 1000032;

int flag[MAX>>5], cand[MAX>>5];

#define sb(c, i) (c[i>>5]|=(1<<(i&31)))
#define cb(c, i) (c[i>>5]&(1<<(i&31)))

int main() {
	int cnt, i, j, k;
	//freopen("out.txt", "w", stdout);
	for(i = 3; i <= 1000; i += 2)
		if(!cb(flag, i))
			for(j = i*i, k = i<<1; j <= 1000000; j += k)
				sb(flag, j);
	sb(cand, 2);
	for(i = 3; i <= 1000000; i += 2)
		if(!cb(flag, i))
			sb(cand, i);
	for(i = 4; i <= 1000000; i += 4) sb(cand, i);
	for(i = 3; i <= 1000; i += 2)
		for(k = i*i, j = k; j <= 1000000; j += k)
			sb(cand, j);
	for(i = 2, cnt = 1; i <= 1000000; i++) {
		if(!cb(cand, i)) {
			if(cnt==108) {
				printf("%d\n", i);
				cnt = 0;
			}
			cnt++;
		}
	}
	return 0;
}
