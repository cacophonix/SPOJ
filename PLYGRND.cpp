/*
USER: zobayer
TASK: PLYGRND
ALGO: geometry
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 24;
const double EPS = 1e-10;

bool valid(double *d, int n) {
	double sum = 0.0;
	for(int i = 0; i < n-1; i++) {
		sum += d[i];
		if(!(sum < d[i+1])) return true;
	}
	return false;
}

int main() {
	int n, i;
	double d[24];
	while(scanf("%d", &n)==1 && n) {
		for(i = 0; i < n; i++) scanf("%lf", &d[i]);
		if(n==1) printf("NO\n");
		else {
			sort(d, d+n);
			if(valid(d, n)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
