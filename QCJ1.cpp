/*
USER: zobayer
TASK: QCJ1
ALGO: sweep
*/

#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

#define MAXH 50
#define MAXW 250

char grid[MAXH][MAXW];

int main()
{
	int i = 0, h, w = 0, pre=-2, tot=0, stp=0, len;
	vector< pair<int,int> > walk;
	while(gets(grid[i])) i++;
	h = i-1;
	len = strlen(grid[i-1]);
	while(w<len)
	{
		if(grid[h][w]=='/')
		{
			if(pre!=1)
			{
				walk.push_back(pair<char,int>(pre,stp));
				stp = 0;
			}
			stp++;
			pre = 1;
			w++;
			tot++;
		}
		else if(grid[h][w]=='_')
		{
			if(pre!=0)
			{
				walk.push_back(pair<char,int>(pre,stp));
				stp = 0;
			}
			stp++;
			pre = 0;
			w++;
			tot++;
		}
		else if(grid[h][w]=='\\')
		{
			if(pre!=-1)
			{
				walk.push_back(pair<char,int>(pre,stp));
				stp = 0;
			}
			stp++;
			pre = -1;
			w++;
			tot++;
		}
		else
		{
			if(pre==-1)
			{
				if(h == i) break;
				else h++;
			}
			else if(pre==0)
			{
				h++;
			}
			else if(pre==1)
			{
				h--;
			}
		}
	}
	walk.push_back(pair<char,int>(pre,stp));
	printf("Total Walk Distance = %d\n", tot);
	for(i=0; i<walk.size(); i++)
	{
		if(walk[i].first==-1) printf("Down %d steps\n", walk[i].second);
		else if(walk[i].first==0) printf("Walk %d steps\n", walk[i].second);
		else if(walk[i].first==1) printf("Up %d steps\n", walk[i].second);
	}
	return 0;
}
