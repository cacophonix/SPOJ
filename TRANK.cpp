/*
USER: zobayer
TASK: TRANK
ALGO: permutation, brute force
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <algorithm>
#include <ios>
#include <cstring>
using namespace std;

char perm[125][10], str[125][10];

int find_diff(char *a, char *b)
{
	int i, j, k, pa, pb, diff = 0;
	for(i=0; i<4; i++)
	{
		for(j=i+1; j<5; j++)
		{
			pa = pb = -1;
			for(k=0; k<5; k++)
			{
				if(pa < 0 && a[i]==b[k]) pa = k;
				if(pb < 0 && a[j]==b[k]) pb = k;
			}
			if(pa > pb) diff++;
		}
	}
	return diff;
}

int main()
{
	char temp[6] = "ABCDE";
	int i = 0, j;
	do{
		strcpy(perm[i++], temp);
	} while(next_permutation(temp, temp+5));
	int n, min, best_idx, diff;
	while(scanf("%d", &n)==1 && n)
	{
		for(i=0; i<n; i++)
			scanf("%s", str[i]);
		min = 999999999;
		best_idx = -1;
		for(i=0; i<120; i++)
		{
			diff = 0;
			for(j=0; j<n; j++)
				diff += find_diff(perm[i], str[j]);
			if(diff < min)
			{
				min = diff;
				best_idx = i;
			}
		}
		printf("%s is the median ranking with value %d.\n", perm[best_idx], min);
	}
	return 0;
}
