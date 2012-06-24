/*
USER: zobayer
TASK: EDIST
ALGO: dynamic programming
*/

#include <stdio.h>
#include <string.h>

#define max_len 2002

char str1[max_len], str2[max_len];
int edit_value[max_len][max_len];

int minimum(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
	int test;
	
	int len1, len2;
	int val, i, j;
	scanf("%d", &test);
	while(test--)
	{
		scanf("%s %s", str1, str2);
		len1 = strlen(str1);
		len2 = strlen(str2);
		edit_value[0][0] = 0;
        	for(i=0 ; i<len1 ; i++) edit_value[i][0] = i;
        	for(j=0 ; j<len2 ; j++) edit_value[0][j] = j;

        	for(i=1 ; i<=len1 ; i++)
        		for(j=1 ; j<=len2 ; j++)
            	{
            		val = (str1[i-1] == str2[j-1]) ? 0 : 1;
            		edit_value[i][j] = minimum(edit_value[i-1][j-1]+val , minimum(edit_value[i-1][j]+1, edit_value[i][j-1]+1));
            	}
            	printf("%d\n", edit_value[len1][len2]);
	}
	return 0;
}
