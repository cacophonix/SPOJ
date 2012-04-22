/*
USER: zobayer
TASK: WEIRDFN
ALGO: heap
*/

#include <cstdio>
#include <queue>
using namespace std;

typedef long long i64;
const i64 mod = 1000000007;

int a, b, c;

inline int getval(i64 m, i64 i) {
	i64 sum = m*a + i*b + c;
	if(sum >= mod) sum -= mod;
	return sum;
}

int main() {
	int test, n, i, f;
	i64 sum;
	scanf("%d", &test);
	while(test--) {
		scanf("%d%d%d%d", &a, &b, &c, &n);
		priority_queue< int, vector< int >, less< int > > Left;
		priority_queue< int, vector< int >, greater< int > > Right;
		Left.push(1);
		sum = 1;
		for(i = 1; i < n; i++) {
			f = getval(Left.top(), i+1);
			sum += f;
			if(f < Left.top()) {
				if(i & 1) {
					Right.push(Left.top());
					Left.pop();
				}
				Left.push(f);
			}
			else if(Right.empty() || (f >= Left.top() && f < Right.top())) {
				if(i & 1) Right.push(f);
				else Left.push(f);
			}
			else {
				if((i+1) & 1) {
					Left.push(Right.top());
					Right.pop();
				}
				Right.push(f);
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}
