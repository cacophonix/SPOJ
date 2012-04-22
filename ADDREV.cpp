/*
USER: zobayer
TASK: ADDREV
ALGO: big integer
*/

#include <cstdio>
#include <cstring>
using namespace std;

char num1[222], num2[222], res[222];

void cutzero_in(int len1, int len2);
void cutzero_out(int k);
void reverse_in(int len1, int len2);
void rev_add();

int main()
{
 	int t, len1, len2;
 	scanf("%d",&t);
 	for(;t;t--)
 	{
	 	scanf("%s%s",num1,num2);
	 	len1 = strlen(num1);
	 	len2 = strlen(num2);
	 	reverse_in(len1, len2); // As the numbers to be reversed
	 	rev_add();
	 	printf("%s\n",res); // In case of normal addition, res is to be reversed
	}
	return 0;
}

void cutzero_in(int len1, int len2)
{
	int i, j;
	//Eleminating leading zeroes in reversed num1
 	for(i=0;i<len1-1;i++)
 	{
	 	if(num1[i]!='0')
		 	break;
	}
	if(i!=0)
		for(j=0;i<=len1;i++,j++)
			num1[j] = num1[i];
	//Eleminating leading zeroes in reversed num2
	for(i=0;i<len2-1;i++)
 	{
	 	if(num2[i]!='0')
		 	break;
	}
	if(i!=0)
		for(j=0;i<=len2;i++,j++)
			num2[j] = num2[i];
}

void cutzero_out(int k)
{
 	int i, j;
 	for(i=0;i<k-1;i++)
 	{
	 	if(res[i]!='0')
		 	break;
	}
	if(i!=0)
		for(j=0;i<=k;i++,j++)
			res[j] = res[i];
}

void reverse_in(int len1, int len2)
{
 	int i, j;
 	for(i=0,j=len1-1;i<j;i++,j--)
 	{
	 	num1[i] ^= num1[j];
	 	num1[j] ^= num1[i];
	 	num1[i] ^= num1[j];
	}
	for(i=0,j=len2-1;i<j;i++,j--)
	{
	 	num2[i] ^= num2[j];
	 	num2[j] ^= num2[i];
	 	num2[i] ^= num2[j];
	}
	cutzero_in(len1,len2);
}

void rev_add()
{
	int sum, carry = 0, k = 0, i, j,len1 = strlen(num1), len2 = strlen(num2);
 	for(i=len1-1,j=len2-1;i>=0&&j>=0;i--,j--)
 	{
	 	sum = (num1[i]-'0')+(num2[j]-'0')+carry;
	 	res[k++] = sum%10 + '0';
	 	carry = sum/10;
	}
	if(j==-1)
		while(i>=0)
		{
		 	sum = carry+num1[i--]-'0';
		 	res[k++] = sum%10+'0';
		 	carry = sum/10;
		}
	else if(i==-1)
		while(j>=0)
		{
		 	sum = carry+num2[j--]-'0';
		 	res[k++] = sum%10+'0';
		 	carry = sum/10;
		}
	while(carry)
	{
	 	res[k++] = carry%10+'0';
	 	carry /=10;
	}
	res[k] = '\0'; 
	// The reverse of res is the normal sum, so no need to reverse it again
	cutzero_out(k);
}
