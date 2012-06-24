/*
USER: zobayer
TASK: BASE
ALGO: base conversion
*/

#include <string.h>
#include <stdio.h>
#include <ctype.h>

int pwr(int n, int p)
{
	int ret = 1;
	for(;p;p--) ret *= n;
	return ret;
}

int main()
{
	char str1[8], str2[8], hx[7] = {"ABCDEF"}, er[6] = {"ERROR"};
	int i, j, dec, b1, b2, n, len, cnt, tmp;
	while(scanf("%s%d%d",str1, &b1, &b2)==3)
	{
		dec = 0; j = 0; cnt = 1;
		len = strlen(str1);
		for(i=len-1;i>=0;i--)
		{
			n = (isalpha(str1[i])!=0) ? str1[i]-'A'+10 : str1[i]-'0';
			if(n>=b1)
			{
				cnt = 0;
				break;
			}
			dec += n*pwr(b1,len-1-i);
		}
		if(dec==0)
			str2[j++] = 0+'0';
		while(dec && cnt)
		{
			if(j>=7)
			{
				cnt = 0;
				break;
			}
			tmp = dec%b2;
			str2[j++] = (tmp<10) ? tmp+'0' : hx[tmp-10];
			dec /= b2;
		}
		str2[j] = 0;
		if(cnt==0)
			printf("%7s\n",er);
		else
		{
			for(i=j-1,j=0;j<i;j++,i--)
			{
				str2[i] ^= str2[j];
				str2[j] ^= str2[i];
				str2[i] ^= str2[j];
			}
			printf("%7s\n",str2);
		}
	}
	return 0;
}

