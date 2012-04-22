/*
USER: zobayer
TASK: JULKA
ALGO: big integer
*/

#include <stdio.h>
#include <string.h>

#define MAX 111

char klaudia[MAX], natalia[MAX], total[MAX], diff[MAX];

void calc()
{
	int len1 = strlen(total);
	int len2 = strlen(diff);
	int a, b, c, i, j, k, f;
	char temp[MAX];

	for(i=len1-1, j=len2-1, k=c=0; i>=0 || j>=0 || c; i--, j--, k++)
	{
		a = i>=0? total[i]-'0' : 0;
		b = j>=0? diff[j]-'0' : 0;
		temp[k] = (a+b+c)%10 + '0';
		c = (a+b+c)/10;
	}
	temp[k] = 0;

	strcpy(klaudia,"0");
	for(i=k-1, j=a=f=0; i>=0; i--)
	{
		b = (a*10 + temp[i]-'0') / 2;
		a = (a*10 + temp[i]-'0') % 2;
		if(b) f = 1;
		if(f) klaudia[j++] = b+'0';
	}
	if(!j) j++;
	klaudia[j] = 0;

	for(i=len1-1, j=len2-1, k=c=0; i>=0; i--, j--, k++)
	{
		a = total[i]-'0';
		b = j>=0? diff[j]-'0' : 0;
		if(a < b+c)
		{
			temp[k] = (10+a-b-c) + '0';
			c = 1;
		}
		else
		{
			temp[k] = a-b-c + '0';
			c = 0;
		}
	}
	temp[k] = 0;

        strcpy(natalia,"0");
        for(i=k-1, j=a=f=0; i>=0; i--)
        {
                b = (a*10 + temp[i]-'0') / 2;
                a = (a*10 + temp[i]-'0') % 2;
                if(b) f = 1;
                if(f) natalia[j++] = b+'0';
        }
        if(!j) j++;
        natalia[j] = 0;
}

int main()
{
	while(scanf("%s %s", total, diff)==2)
	{
		calc();
		printf("%s\n%s\n", klaudia, natalia);
	}
	return 0;
}
