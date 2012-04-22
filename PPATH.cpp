/*
USER: zobayer
TASK: PPATH
ALGO: breadth first search
*/

#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 10000
#define LMT 100

bool flag[MAX], visited[MAX];
int d[MAX];

void sieve()
{
	register int i, j, k;
	flag[0] = flag[1] = 1;
	for(i=1000; i<MAX; i+=2) flag[i] = 1;
	for(i=3; i<LMT; i+=2)
		if(!flag[i])
			for(j=i*i, k=i<<1; j<MAX; j+=k)
				flag[j] = 1;
}

int bfs(int start, int end)
{
	queue< int > Q;
	int i, u, v, t, j;
	char temp[10], x;
	Q.push(start);
	memset(visited, 0, sizeof visited);
	memset(d, -1, sizeof d);
	d[start] = 0;
	visited[start] = 1;
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		sprintf(temp,"%d",u);
		x = temp[0];
		for(t=0;t<4;t++)
		{
			if(t==0 || t==3) i=1; else i=0;
			if(t==3) j=2; else j=1;
			x = temp[t];
			for(;i<=9;i+=j)
			{
				temp[t] = i+'0';
				v = atoi(temp);
				if(v!=u && !visited[v] && !flag[v])
				{
					Q.push(v);
					visited[v] = 1;
					d[v] = d[u]+1;
					if(v==end) return d[end];
				}
			}
			temp[t] = x;
		}
	}
	return d[end];
}

int main()
{
	int a, b, t, dist;
	sieve();
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &a, &b);
		if(a==b) { printf("0\n"); continue; }
		dist = bfs(a,b);
		if(dist==-1) printf("impossible\n");
		else printf("%d\n", dist);
	}
	return 0;
}