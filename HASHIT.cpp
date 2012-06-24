/*
USER: zobayer
TASK: HASHIT
ALGO: hashing
*/

#include <iostream>
#include <cstring>
#include <string>
#include <map>
using namespace std;

int key(char *s)
{
	int n = 0, i;
	for(i=0;s[i];i++)
		n += s[i]*(i+1);
	n *= 19;
	return n % 101;
}

int add(int hkey, bool *flag)
{
	for(int j=0;j<=19;j++)
		if(!flag[(hkey + j*(j+23))%101])
			return (hkey + j*(j+23))%101;
	return -1;
}

int main()
{
	int t, n, i, pos, tot;
	char op[10], str[30], input[100];
	string s, tab[101];
	scanf("%d",&t);
	while(t--)
	{
		map <string, int> M;
		bool flag[101] = {0};
		tot = 0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%s",input);
			strcpy(op,strtok(input,": "));
			strcpy(str,strtok(0,""));
			s = str;
			if(!strcmp(op,"ADD"))
			{
				if(M.find(s)==M.end())
				{
					pos = add(key(str),flag);
					if(pos != -1)
					{
						tot++;
						flag[pos] = 1;
						tab[pos] = s;
						M.insert(pair<string, int>(s, pos));
					}
				}
			}
			else if(!strcmp(op,"DEL"))
			{
				if(M.find(s)!=M.end())
				{
					flag[M[s]] = 0;
					M.erase(s);
					tot--;
				}
			}
		}
		printf("%d\n",tot);
		for(i=0;i<101;i++)
			if(flag[i])
				printf("%d:%s\n",i,tab[i].c_str());
	}
	return 0;
}

