/*
USER: zobayer
TASK: LENGFACT
ALGO: math
*/

#include <cmath>
#include <cstdio>
using namespace std;

int main() {
	double x, ans, pi = acos(-1.0);
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%lf", &x);
		// striling's approximation
		if(x<3.0) ans = 1.0;
		else ans = floor((x*log(x)-x+(log(2.0*pi*x))/2.0)/log(10.0))+1.0;
		printf("%.0lf\n", ans + 1e-12);
	}
	return 0;
}
