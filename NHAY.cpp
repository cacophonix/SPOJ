/*
USER: zobayer
TASK: NHAY
ALGO: knuth morris patt
*/

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int *overlap;
char *pattern;

void computeOverlap()
{
	overlap[0] = -1;
	for(int i=0; pattern[i]; i++)
	{
		overlap[i+1] = overlap[i] + 1;
		while(overlap[i+1] > 0 && pattern[i] != pattern[overlap[i+1]-1])
			overlap[i+1] = overlap[overlap[i+1]-1] + 1;
	}
}

vector< int > kmpMatcher(int m)
{
	vector< int > V;
	int i = 0, j = 0;
	char ch;
	while(1)
	{
		ch = getchar();
		if(ch == '\n') break;
		while(1)
		{
			if(ch == pattern[j])
			{
				j++;
				if(j == m)
				{
					V.push_back(i-m+1);
					j = overlap[j];
				}
				break;
			}
			else if(j == 0) break;
			else j = overlap[j];
		}
		i++;
	}
	return V;
}

int main()
{
	int n, i, sz;
	vector< int > V;
	//freopen("in.txt","r",stdin);
	while(scanf("%d",&n)==1)
	{
		getchar();
		pattern = new char[n+10];
		overlap = new int[n+10];
		gets(pattern);
		computeOverlap();
		V = kmpMatcher(n);
		sz = V.size();
		for(i=0; i < sz; i++)
			printf("%d\n",V[i]);
		if(!sz) printf("\n");
		delete[] pattern;
		delete[] overlap;
	}
	return 0;
}


