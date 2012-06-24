/*
USER: zobayer
TASK: CUBES
ALGO: ad-hoc
*/

#include <stdio.h>

int main()
{
	int a, b, c, d;
	for(a=6;a<=100;a++)
		for(b=2;b<a-2;b++)
			for(c=b+1;c<a-1;c++)
				for(d=c+1;d<a;d++)
					if(a*a*a==b*b*b+c*c*c+d*d*d)
						printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
	return 0;
}

