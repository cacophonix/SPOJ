/*
USER: zobayer
TASK: XMEDIAN
ALGO: heap
*/

#include <cstdio>
#include <set>
using namespace std;

multiset< int > S;
multiset< int > :: iterator m1, m2;

int main() {
	int n, i, f;
	scanf("%d", &n);
	scanf("%d", &f);
	S.insert(f);
	m1 = m2 = S.begin();
	for(i = 2; i <= n; i++) {
		printf("%d\n", *m1);
		scanf("%d", &f);
		S.insert(f);
		if(f < *m1) {
			if(i & 1) m2--;
			else m1--;
		}
		else if(f >= *m1 && f < *m2) {
			m1++;
			m2--;
		}
		else {
			if(i & 1) m1++;
			else m2++;
		}
	}
	printf("%d\n", *m1);
	return 0;
}
