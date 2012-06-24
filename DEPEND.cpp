/*
USER: zobayer
TASK: DEPEND
ALGO: topological sort
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <cstdio>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <queue>
#include <cassert>
using namespace std;

#define DEBUG if(0)
#define MAX 10000
#define WHITE 0
#define GRAY 1
#define BLACK 2

map< string, int > M;
map< string, int > :: iterator itm;
set< int > G[MAX], R[MAX];
set< int > P;
bool available[MAX];
int subtotal, visited[MAX];

int dfs(int u)
{
	int sz = G[u].size(), cnt = 0, v;
	visited[u] = GRAY; /* encountered, but not confirmed ok */
	for(set< int >::iterator it=G[u].begin(); it!=G[u].end(); it++)
	{
		v = *it;
		if(visited[v]==WHITE) cnt += dfs(v); /* try to install dependies first */
		else if(visited[v]==BLACK) cnt++; /* already installed package */
	}
	if(cnt==sz && available[u]) /* this package is good to install */
	{
		subtotal++;
		visited[u] = BLACK;
		return 1;
	}
	return 0;
}

int main()
{
	DEBUG freopen("in2.txt", "r", stdin);
	char name[100];
	int vertex = 1, u, v, cnt = 0;
	while(scanf("%s", name)==1)
	{
		itm = M.find((string)name);
		if(itm==M.end())
		{
			DEBUG assert(vertex < MAX);
			M.insert(itm, pair< string, int >((string)name, vertex++));
			u = vertex - 1;
		}
		else u = (*itm).second;
		P.insert(u); /* new package */
		available[u] = true;
		while(scanf("%s", name)==1)
		{
			if(name[0]=='0' && name[1]==0) break;
			itm = M.find((string)name);
			if(itm==M.end())
			{
				DEBUG assert(vertex < MAX);
				M.insert(itm, pair< string, int >((string)name, vertex++));
				v = vertex - 1;
			}
			else v = (*itm).second;
			G[u].insert(v);
		}
	}
	for(set< int >::iterator it=P.begin(); it!=P.end(); it++)
	{
		u = *it;
		if(visited[u]==WHITE)
		{
			subtotal = 0;
			dfs(u);
			cnt += subtotal;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
