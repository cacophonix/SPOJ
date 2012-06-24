/*
USER: zobayer
TASK: MAYA
ALGO: ad-hoc
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

char maya[20][15] = {
	"S", ".", "..", "...", "....",
	"-", ". -", ".. -", "... -", ".... -",
	"- -", ". - -", ".. - -", "... - -", ".... - -",
	"- - -", ". - - -", ".. - - -", "... - - -", ".... - - -"
};

int pwr[7] = {1, 20, 360, 7200, 144000, 2880000, 57600000};

int main()
{
	int n, res, i, j;
	char temp[100];
	while(scanf("%d", &n)==1 && n)
	{
		getchar();
		res = 0;
		for(i=n-1; i>=0; i--)
		{
			gets(temp);
			for(j=0; j<20; j++)
				if(!strcmp(temp, maya[j]))
					break;
			if(j) res += pwr[i]*j;
		}
		printf("%d\n", res);
	}
	return 0;
}
