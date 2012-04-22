/*
USER: zobayer
TASK: PT07Z
ALGO: tree diameter
*/

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

#define MAX 50005

int node, eccen, next;
int degree[MAX], edist[MAX];
bool color[MAX];
bool first;
vector< int > G[MAX];

void dfs(int u, int d)
{
	int v, i, sz = G[u].size(), fl = 0;
	for(i = 0; i < sz; i++)
	{
		v = G[u][i];
		if(!color[v])
		{
			color[v] = 1;
			fl = 1;
			dfs(v,d+1);
		}
	}
	if(eccen <= d)
	{
		eccen = d;
		if(!fl)
		{
			if(first) next = u;
			else next = degree[next] < degree[u] ? next : u;
		}
	}
}

int compute()
{
	int u = 1, v;
	first = 1;
	while(1)
	{
		memset(color, 0, sizeof(color));
		eccen = 0;
		color[u] = 1;
		dfs(u,0);
		if(first)
		{
			edist[u] = eccen;
			//printf("Next %d, Longest distance from %d is %d\n", next, u, edist[u]);
			first = 0;
			v = u;
			u = next;
		}
		else
		{
			edist[u] = eccen;
			//printf("Next %d, Longest distance from %d is %d\n", next, u, edist[u]);
			//printf("Previous longest distance was %d from %d\n", edist[v], v);
			if(edist[v] >= edist[u]) return edist[v];
			v = u;
			u = next;
		}
	}
	return 0;
}

int main()
{
	int i, u, v, res;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &node);
	for(i = 0; i < node-1; i++)
	{
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
		degree[u]++;
		degree[v]++;
	}
	res = compute();
	printf("%d\n", res);
	return 0;
}
