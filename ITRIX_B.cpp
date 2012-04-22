/*
USER: zobayer
TASK: ITRIX_B
ALGO: math
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int d, t, i;
	char buff[32], *s = "2357";
	long long int n;
	scanf("%d", &t);
	while(t--) {
		scanf("%lld", &n);
		i = 0;
		while(n) {
			d = n & 3; n >>= 2;
			if(!d) d = 4, n--;
			buff[i++] = s[d-1];
		}
		buff[i] = 0;
		reverse(buff, buff+i);
		puts(buff);
	}
	return 0;
}