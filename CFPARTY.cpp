/*
USER: zobayer
TASK: CFPARTY
ALGO: tial and error
*/

#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		printf("%d\n", max(0, n-2));
	}
	return 0;
}
