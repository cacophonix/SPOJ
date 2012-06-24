/*
USER: zobayer
TASK: NSYSTEM
ALGO: ad-hoc
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <ios>
#include <algorithm>
using namespace std;

char num1[20], num2[20], res[20], alp[5] = "ixcm";
int cm[26];

int genN(char *s)
{
	int i, n;
	for(i=n=0; s[i]; )
	{
		if(s[i]>'9')
		{
			n += cm[s[i]-'a'];
			i++;
		}
		else
		{
			n += cm[s[i+1]-'a']*(s[i]-'0');
			i += 2;
		}
	}
	return n;
}

void genS(char *s, int n)
{
	int k = 0, m, p = 0;
	while(n)
	{
		m = n%10;
		if(m==1) s[k++] = alp[p];
		else if(m>1) s[k++] = alp[p], s[k++] = m+'0';
		p++;
		n /= 10;
	}
	res[k] = 0;
	reverse(res, res+k);
}

int main()
{
	int t, n1, n2;
	cm['m'-'a'] = 1000;
	cm['c'-'a'] = 100;
	cm['x'-'a'] = 10;
	cm['i'-'a'] = 1;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s %s", num1, num2);
		n1 = genN(num1);
		n2 = genN(num2);
		genS(res, n1+n2);
		printf("%s\n", res);
	}
	return 0;
}
