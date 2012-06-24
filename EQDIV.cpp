/*
USER: zobayer
TASK: EQDIV
ALGO: bfs
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <cstring>
#include <climits>
#include <iostream>
#include <sstream>
#include <string>
#include <numeric>
#include <utility>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
using namespace std;

#define OFF ios::sync_with_stdio(false)
#define IOR(x) freopen(x,"r",stdin);
#define IOW(x) freopen(x,"w",stdout);
#define i64 long long

#define ALL(p) p.begin(),p.end()
#define CLR(p) p.clear()
#define pb(x) push_back(x)
#define pii pair<int,int>
#define mset(p,v) memset(p,v,sizeof(p))

#define MAX 101

int grid[MAX][MAX], n;
char buff[MAX*MAX];
int line[2*MAX];

inline bool inRange(int i, int j)
{
	return (i>0 && i<=n && j>0 && j<=n);
}

int visit(pii P)
{
	queue< pii > Q;
	Q.push(P);
	int cnt = 1, i, j, val;
	val = grid[P.first][P.second];
	grid[P.first][P.second] = -1;
	while(!Q.empty())
	{
		i = Q.front().first;
		j = Q.front().second;
		Q.pop();
		if(inRange(i+1,j) && grid[i+1][j]==val)
		{
			cnt++;
			grid[i+1][j] = -1;
			Q.push(pii(i+1,j));
		}
		if(inRange(i-1,j) && grid[i-1][j]==val)
		{
			cnt++;
			grid[i-1][j] = -1;
			Q.push(pii(i-1,j));
		}
		if(inRange(i,j+1) && grid[i][j+1]==val)
		{
			cnt++;
			grid[i][j+1] = -1;
			Q.push(pii(i,j+1));
		}
		if(inRange(i,j-1) && grid[i][j-1]==val)
		{
			cnt++;
			grid[i][j-1] = -1;
			Q.push(pii(i,j-1));
		}
	}
	return cnt;
}

int main()
{
	//IOR("in.txt");
	//IOW("out.txt");
	int i, j, k, u, v, reg, sz, flag;
	while(scanf("%d", &n)==1 && n)
	{
		getchar();
		mset(grid,0);
		k = 1;
		for(i=0; i<n-1; i++)
		{
			gets(buff);
			stringstream ss(buff);
			for(j=1; j<=n; j++)
			{
				ss >> u >> v;
				grid[u][v] = k;
			}
			k++;
		}
		reg = 0;
		flag = 1;
		for(i=1; flag && i<=n; i++)
			for(j=1; flag && j<=n; j++)
				if(grid[i][j]!=-1)
				{
					reg++;
					sz = visit(pii(i,j));
					if(sz!=n) flag = 0;
				}
		if(reg!=n) flag = 0;
		if(flag) printf("good\n");
		else printf("wrong\n");
	}
	return 0;
}
