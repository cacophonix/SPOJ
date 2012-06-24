/*
USER: zobayer
TASK: FENCE1
ALGO: geometry
*/

#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	double area, pi = acos(-1.0), eps = 1e-10, L;
	while(scanf("%d", &n)==1 && n)
	{
		L = n;
		area = L*L/2.0/pi;
		printf("%.2lf\n", area + eps);
	}
	return 0;
}
