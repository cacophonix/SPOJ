/*
USER: zobayer
TASK: EQUI
ALGO: math
*/

#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	long long a[500], x, sum, p;
	set< long long > S;
	int i, n, r;
	while(scanf("%d", &n)==1 && n > 2) {
		S.clear();
		for(i = r = 0, n--, sum = 0; i < n; i++) {
			scanf("%lld", a + i);
			sum += a[i];
			S.insert(a[i]);
		}
		sort(a, a + n);
		x = a[(n >> 1) - 1];
		p = x * (n + 1) - sum;
		if(S.find(p) == S.end() && p < x) r++;
		if(sum % n == 0) {
			p = sum / n;
			if(p > a[(n >> 1) - 1] && p < a[n >> 1]) r++;
		}
		x = a[n >> 1];
		p = x * (n + 1) - sum;
		if(S.find(p) == S.end() && p > x) r++;
		printf("%d\n", r);
	}
	return 0;
}