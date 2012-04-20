/*
USER: zobayer
TASK: EQ
ALGO: heap
*/

#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

typedef long long i64;

int main() {
	int test, n, p, i, k;
	i64 tot, top;
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d", &n, &p);
		priority_queue< i64, vector< i64 >, greater< i64 > > Q;
		tot = 0;
		while(p--) {
			scanf("%d %d", &i, &k);
			if(Q.size() < n) {
				Q.push(i + 5 + k);
				tot += 5 + k;
			}
			else {
				top = Q.top(); Q.pop();
				if(top > i) {
					tot += top - i + 5 + k;
					Q.push(top + 5 + k);
				}
				else {
					tot += 5 + k;
					Q.push(i + 5 + k);
				}
			}
		}
		printf("%lld\n", tot);
	}
	return 0;
}
