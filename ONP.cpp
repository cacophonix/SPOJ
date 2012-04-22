/*
USER: zobayer
TASK: ONP
ALGO: expression evaluation
*/

#include <cstdio>
#include <stack>
#include <map>
#include <cctype>
using namespace std;

// assuming no invalid input will be given

int main()
{
	int t, x, i, k;
	char str[500], res[500];
	map<char,int> pri;
	pri.insert(pair<char,int>('+',1));
	pri.insert(pair<char,int>('-',2));
	pri.insert(pair<char,int>('*',3));
	pri.insert(pair<char,int>('/',4));
	pri.insert(pair<char,int>('^',5));
	stack<char> S;
	for(scanf("%d",&t);t;t--)
	{
		k = 0;
		scanf("%s",str);
		for(i=0;str[i];i++)
		{
			if(isalpha(str[i])) res[k++] = str[i];
			else if(str[i]=='(') S.push(str[i]);
			else if(str[i]==')')
			{
				while(!S.empty() && S.top()!='(')
				{
					res[k++] = S.top();
					S.pop();
				}
				S.pop();
			}
			else
			{
				while(!S.empty() && S.top()!='(' && pri[S.top()]>pri[str[i]])
				{
					res[k++] = S.top();
					S.pop();
				}
				S.push(str[i]);
			}
		}
		while(!S.empty())
		{
			res[k++] = S.top();
			S.pop();
		}
		res[k] = 0;
		printf("%s\n",res);
	}
	return 0;
}
