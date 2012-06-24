/*
USER: zobayer
TASK: GEOPROB
ALGO: geometry, big integer
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <ios>
#include <cstring>
#include <algorithm>
using namespace std;

struct bigint {
	char s[250];
	int len;
	bigint()
	{
		s[0] = '0', s[1] = 0;
		len = 1;
	}
	bigint operator+(bigint &X)
	{
		int i, j, k, carry, a, b, len2 = X.len, len1 = len;
		bigint R;
		for(i=j=k=carry=0; i<len1 || j<len2 || carry; i++, j++, k++)
		{
			a = (i<len1)? s[i]-'0' : 0;
			b = (j<len2)? X.s[j]-'0' : 0;
			R.s[k] = (a+b+carry)%10 + '0';
			carry = (a+b+carry)/10;
		}
		R.len = k;
		R.s[k] = 0;
		return R;
	}
	bigint operator-(bigint &X)
	{
		int i, j, k, carry, a, b, len2 = X.len, len1 = len;
		bigint R;
		for(i=j=k=carry=0; i<len1; i++, j++, k++)
		{
			a = s[i]-'0';
			b = (j<len2)? X.s[j]-'0' : 0;
			if(a < b + carry)
			{
				R.s[k] = (a+10-b-carry)%10 + '0';
				carry = 1;
			}
			else
			{
				R.s[k] = (a-b-carry)%10 + '0';
				carry = 0;
			}
		}
		R.s[k] = 0;
		for(--k; k>0; k--)
		{
			if(R.s[k]=='0') R.s[k] = 0;
			else break;
		}
		R.len = k+1;
		return R;
	}
	void reset()
	{
		len = 1;
		s[0] = '0', s[1] = 0;
	}
	void rev()
	{
		reverse(s, s+len);
	}
};

int main()
{
	int t;
	bigint a, b, c;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s %s %s", a.s, b.s, c.s);
		a.len = strlen(a.s);
		b.len = strlen(b.s);
		c.len = strlen(c.s);
		a.rev();
		b.rev();
		c.rev();
		b = b+b;
		b = b-a;
		b = b-c;
		b.rev();
		puts(b.s);
		a.reset();
		b.reset();
		c.reset();
	}
	return 0;
}
