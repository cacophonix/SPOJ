/*
USER: zobayer
TASK: TRICENTR
ALGO: geometry
*/

#include <stdio.h>
#include <math.h>

int main()
{
	int t;
	double a, b, c, da, db, dc, s, r, m;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf", &a, &da, &db, &dc);
		s = 3.0*a*da/2.0;
		b = 2.0*s/3.0/db;
		c = 2.0*s/3.0/dc;
		r = a*b*c/4.0/s;
		m = 4.0*(r*r-(a*a+b*b+c*c)/9.0);
		m = (m<0.0) ? 0.0 : m;
		printf("%.3lf %.3lf\n", s, sqrt(m));
	}
	return 0;
}
