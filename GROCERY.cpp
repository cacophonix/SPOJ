/*
USER: zobayer
TASK: GROCERY
ALGO: ad-hoc
*/

#include <cstdio>
using namespace std;

#define AMP 1000000

int main()
{
	int i, j, k, l;
	for(i=1; i*i*i*i <= 244140625; i++)
		for(j=i; i*j*j*j <= AMP*2000; j++)
			for(k=j; i*j*k*k <= AMP*2000 && 2000-(i+j+k)>=k; k++)
			{
				if(i*j*k > AMP && (AMP*(i+j+k))%(i*j*k-AMP)==0)
				{
					l = (AMP*(i+j+k))/(i*j*k-AMP);
					if(l>=k && i+j+k+l<=2000)
					{
						printf("%.2lf %.2lf %.2lf %.2lf\n",i/100.0,j/100.0,k/100.0,l/100.0);
					}
				}
			}
	return 0;
}
/* END OF CODE */
