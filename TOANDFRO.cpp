/*
USER: zobayer
TASK: TOANDFRO
ALGO: ad-hoc
*/

#include <ios>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int len, r, c, i, j, k;
	char msg[250], res[250];
	while(scanf("%d", &c)==1 && c)
	{
		scanf("%s", msg);
		len = strlen(msg);
		r = len / c;
		for(i=1; i*c<len; i+=2)
			reverse(&msg[i*c], &msg[i*c]+c);
		for(i=k=0; k<c; k++)
			for(j=0; j<r; j++)
				res[i++] = msg[c*j + k];
		res[i] = 0;
		puts(res);
	}
	return 0;
}
