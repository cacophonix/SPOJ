/*
USER: zobayer
TASK: INCARDS
ALGO: dijkstra
*/

#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 100001
#define INF 1<<29

struct comp
{
	bool operator()(const pair< int, int > &a, const pair< int, int > &b)
	{
		return a.second > b.second;
	}
};

int main()
{
	vector< pair< int, int > > G1[MAX], G2[MAX];
	priority_queue< pair< int, int >, vector< pair< int, int > >, comp > Q;
	int t, x, i, u, v, w, p, q, sz, total;
	int D1[MAX], D2[MAX];
	scanf("%d",&t);
	for(x=1;x<=t;x++)
	{
		scanf("%d%d",&p,&q);
		for(i=1;i<=p;i++)
		{
			G1[i].clear();
			G2[i].clear();
		}
		for(i=0;i<q;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			G1[u].push_back(pair<int,int>(v,w));
			G2[v].push_back(pair<int,int>(u,w));
		}
		
		D1[1] = D2[1] = 0;
		for(i=2;i<=p;i++) D1[i] = D2[i] = INF;
		
		Q.push(pair< int, int>(1,0));
		while(!Q.empty())
		{
			u = Q.top().first;
			Q.pop();
			sz = G1[u].size();
			for(i=0;i<sz;i++)
			{
				v = G1[u][i].first;
				w = G1[u][i].second;
				if(D1[u]+w < D1[v])
				{
					D1[v] = D1[u]+w;
					Q.push(G1[u][i]);
				}
			}
		}
		
		Q.push(pair< int, int>(1,0));
		while(!Q.empty())
		{
			u = Q.top().first;
			Q.pop();
			sz = G2[u].size();
			for(i=0;i<sz;i++)
			{
				v = G2[u][i].first;
				w = G2[u][i].second;
				if(D2[u]+w < D2[v])
				{
					D2[v] = D2[u]+w;
					Q.push(G2[u][i]);
				}
			}
		}
		
		for(i=1,total=0;i<=p;i++)
		{
			//if(D1[i]||D2[i]) printf("D1[%d]=%d; D2[%d]=%d\n",i,D1[i],i,D2[i]);
			total += D1[i]+D2[i];
		}
		printf("%d\n",total);
	}
	return 0;
}
