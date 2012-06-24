/*
USER: zobayer
TASK: MMASS
ALGO: expression evaluation
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <stack>
#include <cctype>
using namespace std;

inline int getM(char ch)
{
	switch(ch)
	{
	case 'H': return 1;
	case 'O': return 16;
	case 'C': return 12;
	}
	return 0;
}

int main()
{
	char str[150];
	int i, v;
	stack < int > S;
	scanf("%s", str);
	for(i=0; str[i]; i++)
	{
		if(isdigit(str[i]))
		{
			v = S.top();
			S.pop();
			S.push(v * (str[i]-'0'));
		}
		else if(str[i]=='(') S.push(-1);
		else if(str[i]==')')
		{
			v = 0;
			while(!S.empty() && S.top()!=-1)
			{
				v += S.top();
				S.pop();
			}
			S.pop();
			S.push(v);
		}
		else if(isalpha(str[i])) S.push(getM(str[i]));
	}
	v = 0;
	while(!S.empty())
	{
		v += S.top();
		S.pop();
	}
	printf("%d\n", v);
	return 0;
}
