/*
USER: zobayer
TASK: STONE
ALGO: geometry
*/

#include <cstdio>
#include <cmath>

#define MAX 1000009

struct point { double x, y; };
using namespace std;

point P[MAX];

int main()
{
	int t, n, i;
	double d, a, cx, cy;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
			scanf("%lf%lf", &P[i].x, &P[i].y);
		P[n] = P[0], cx = cy = a = 0.0;
		for(i=0; i<n; i++)
		{
			d = P[i].x * P[i+1].y - P[i+1].x * P[i].y;
			a += d;
			cx += (P[i].x + P[i+1].x) * d;
			cy += (P[i].y + P[i+1].y) * d;
		}
		cx /= (3.0 * a);
		cy /= (3.0 * a);
		printf("%.2lf %.2lf\n", cx, cy);
	}
	return 0;
}
