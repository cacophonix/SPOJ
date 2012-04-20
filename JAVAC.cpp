/*
USER: zobayer
TASK: JAVAC
ALGO: ad-hoc
*/

#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

#define MAX 500
#define IOR(x) freopen(x,"r",stdin)
#define IOW(x) freopen(x,"w",stdout)
#define mset(x,v) memset(x,v,sizeof(x))

int main()
{
	char str[MAX], res[MAX];
	int len, i, j, flag; // 0-common, 1-java, 2-C++, 3-error
	while(scanf("%s",str)==1)
	{
		len = strlen(str);
		if(str[0]=='_' || str[0]<'a')
			printf("Error!\n");
		else
		{
			flag = 0;
			for(i=j=0;i<len;i++)
			{
				if(!flag && str[i]=='_') flag = 2;
				if(!flag && isupper(str[i])) flag = 1;
				if((flag==1 && str[i]=='_')||(flag==2 && isupper(str[i])))
				{
					flag = 3;
					break;
				}
				if(flag==1 && isupper(str[i]))
				{
					res[j++] = '_';
					res[j++] = str[i]+32;
				}
				else if(flag==2 && str[i]=='_')
				{
					if(!islower(str[i+1]))
					{
						flag = 3;
						break;
					}
					else res[j++] = str[++i]-32;
				}
				else res[j++] = str[i];
			}
			res[j] = 0;
			if(flag==3) printf("Error!\n");
			else printf("%s\n",res);
		}
	}
	return 0;
}
