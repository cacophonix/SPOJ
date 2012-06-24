/*
USER: zobayer
TASK: ENCONDIN
ALGO: ad-hoc
*/

#include <stdio.h>
#include <string.h>

int main()
{
	char str[10001], ch;
	int i, j, k, len;
	while(gets(str))
	{
		len = strlen(str);
		for(i=0; i<len;)
		{
			if(str[i]!=str[i+1])
			{
				printf("1");
				for(j=i; j<len && str[j]!=str[j+1]; j++, i++)
				{
					if(str[j]=='1') printf("11");
					else printf("%c", str[j]);
				}
				printf("1");
			}
			else
			{
				ch = str[i];
				for(j=i, k=0; j<len && k<9 && str[j]==ch; j++, i++, k++);
				printf("%d%c", k, ch);
			}
		}
		printf("\n");
	}
	return 0;
}

