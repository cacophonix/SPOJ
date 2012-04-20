/*
USER: zobayer
TASK: LASTDIG2
ALGO: pre-calculation
*/

#include <ios>
#include <cstring>
using namespace std;

int main()
{
	int b, t, i, j, table[10][4];
	long long p;
	char str[1001];
	for(i=0; i<10; i++)
		for(j=table[i][0]=1; j<=4; j++)
			table[i][j&3] = (table[i][j-1]*i)%10;
	for(scanf("%d",&t); t; t--)
	{
		scanf("%s %lld", str, &p);
		if(!p) printf("1\n");
		else
		{
			b = str[strlen(str)-1]-'0';
			printf("%d\n", table[b][p&3]);
		}
	}
	return 0;
}
