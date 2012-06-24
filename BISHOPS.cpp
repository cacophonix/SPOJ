/*
USER: zobayer
TASK: BISHOPS
ALGO: ad-hoc, big integer
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <ios>
#include <algorithm>
using namespace std;

int main()
{
	char num[111];
	while(scanf("%s", num)==1)
	{
		if(strcmp(num,"1")==0) puts(num);
		else
		{
			int i, k, carry, a, len;
			len = strlen(num);
			reverse(num, num+len);
			for(i=k=carry=0; i<len || carry; i++, k++)
			{
				a = (i<len)? num[i]-'0' : 0;
				num[k] = (a*2+carry)%10 + '0';
				carry = (a*2+carry)/10;
			}
			num[k] = 0;
			len = k;
			k = carry = 0;
			a = num[0]-'0';
			if(a<2)
			{
				num[k++] = 10 + a - 2 + '0';
				carry = 1;
			}
			else
			{
				num[k++] = a - 2 + '0';
				carry = 0;
			}
			for(i=1; i<len; i++, k++)
			{
				a = num[i]-'0';
				if(a<carry)
				{
					num[k] = a + 10 - carry + '0';
					carry = 1;
				}
				else
				{
					num[k] = a - carry + '0';
					carry = 0;
				}
			}
			for(--k; k>0; k--)
			{
				if(num[k]=='0') num[k] = 0;
				else break;
			}
			len = k+1;
			reverse(num, num + len);
			puts(num);
		}
	}
	return 0;
}
