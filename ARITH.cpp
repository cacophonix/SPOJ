/*
USER: zobayer
TASK: ARITH
ALGO: big integer
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char mul[510][1010];
char num1[510], num2[510];
char inp[1010];
int len1, len2;

void add(char *n1, char *n2, char *res)
{
	int i, j, k, carry, a, b, l1, l2;
	i = j = k = carry = 0;
	l1 = strlen(n1), l2 = strlen(n2);
	for( ; i<l1 || j<l2 || carry; i++, j++, k++)
	{
		a = i<l1? n1[i]-'0' : 0;
		b = j<l2? n2[j]-'0' : 0;
		res[k] = (a+b+carry)%10 + '0';
		carry = (a+b+carry)/10;
	}
	res[k] = 0;
}

void sub(char *n1, char *n2, char *res)
{
	int i, j, k, a, b, carry;
	for(i=j=k=carry=0; i<len1; i++, j++, k++)
	{
		a = n1[i]-'0';
		b = j<len2 ? n2[j]-'0' : 0;
		if( a < b + carry)
		{
			res[k] = (a+10 - b - carry) + '0';
			carry = 1;
		}
		else
		{
			res[k] = (a - b - carry) + '0';
			carry = 0;
		}
	}
	res[k] = 0;
	for(i=k-1; i>0; i--)
	{
		if(res[i]=='0') res[i] = 0;
		else break;
	}
}

void multi()
{
	char res[1010], temp1[1010], temp2[1010];
	int i, j, k, a, b, carry;
	strcpy(res,"0");
	for(j=0; j<len2; j++)
	{
		a = num2[j]-'0';
		if(a==0)
		{
			strcpy(mul[j],"0");
		}
		else
		{
			if(a==1)
			{
				strcpy(mul[j],num1);
				k = len1;
			}
			else
			{
				k = carry = 0;
				for(i=0; i<len1 || carry; i++, k++)
				{
					b = i<len1? num1[i]-'0' : 0;
					mul[j][k] = (a*b + carry) % 10 + '0';
					carry = (a*b+carry)/10;
				}
				mul[j][k] = 0;
			}
			for(i=0;i<j;i++) temp1[i] = '0';
			temp1[i] = 0;
			strcat(temp1, mul[j]);
			reverse(mul[j], mul[j]+k);
			add(res, temp1, temp2);
			strcpy(res,temp2);
		}
	}
	int reslen = strlen(res);
	reverse(res, res + reslen);
	reverse(num1, num1 + len1);
	reverse(num2, num2 + len2);
	/* Printing part */
	int pFlen = strlen(mul[0]);
	int pLlen = strlen(mul[len2-1]);
	int h1 = (len2+1 > pFlen)? len2+1 : pFlen;
	int h2 = (reslen > pLlen+len2-1)? reslen : pLlen+len2-1;
	int align = (h1>h2)? h1 : h2;
	align = (align > len1)? align : len1;
	char hlin1[510], hlin2[1010];
	if(len2==1)
	{
		printf("%*s\n",align, num1);
		printf("%*c%s\n",align-len2,'*',num2);
		for(i=0;i<h1;i++) hlin1[i] = '-'; hlin1[i] = 0;
		printf("%*s\n",align,hlin1);
		printf("%*s\n",align,res);
	}
	else
	{
		printf("%*s\n",align, num1);
		printf("%*c%s\n",align-len2,'*',num2);
		for(i=0;i<h1;i++) hlin1[i] = '-'; hlin1[i] = 0;
		printf("%*s\n",align,hlin1);
		for(i=0;i<len2;i++) printf("%*s\n",align-i,mul[i]);
		for(i=0;i<h2;i++) hlin2[i] = '-'; hlin2[i] = 0;
		printf("%*s\n",align,hlin2);
		printf("%*s\n",align,res);
	}
}

void print(char *n1, char *n2, char *res, char op)
{
	int h1, i;
	char lin1[510];
	int lenres = strlen(res);
	h1 = (len2 + 1 > lenres) ? len2 + 1 : lenres;
	for(i=0; i<h1; i++) lin1[i] = '-'; lin1[i] = 0;
	h1 = (h1 > len1) ? h1 : len1;
	reverse(num1, num1 + len1);
	reverse(num2, num2 + len2);
	reverse(res, res + lenres);
	printf("%*s\n",h1, num1);
	printf("%*c%s\n",h1-len2,op,num2);
	printf("%*s\n",h1,lin1);
	printf("%*s\n",h1,res);
}

int main()
{
	int t;
	char op, res[510];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",inp);
		sscanf(inp,"%[0123456789]%c%s", num1, &op, num2);
		len1 = strlen(num1);
		len2 = strlen(num2);
		reverse(num1,num1+len1);
		reverse(num2,num2+len2);
		switch(op)
		{
		case '*':
			multi();
			break;
		case '+':
			add(num1,num2,res);
			print(num1, num2, res, '+');
			break;
		case '-':
			sub(num1, num2, res);
			print(num1, num2, res, '-');
		}
		printf("\n");
	}
	return 0;
}
