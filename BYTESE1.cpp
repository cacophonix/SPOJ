/*
USER: zobayer
TASK: BYTESE1
ALGO: dijkstra
*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <ios>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define bwxy pair<pair<int,int>, pair<int,int> >
#define inf (1<<25)
#define MAX 101

int R, C;
bwxy G[MAX][MAX];

struct comp {
	bool operator()(const bwxy &a, const bwxy &b) {
		return (a.first.first > b.first.first);
	}
};

inline bool inrange(int r, int c)
{
	return (r>=0 && r<R && c>=0 && c<C);
}

inline void getdata(bwxy a, int &b, int &w, int &u, int &v)
{
	b = a.first.first; w = a.first.second;
	u = a.second.first; v = a.second.second;
}

void dijkstra()
{
	priority_queue<bwxy, vector< bwxy >, comp> Q;
	int u, v, w, b, u1, v1, w1, b1, i, j;
	G[0][0].first.first = G[0][0].first.second;
	Q.push(G[0][0]);
	while(!Q.empty())
	{
		getdata(Q.top(), b, w, u, v);
		Q.pop();
		for(i=-1; i<=1; i++)
		{
			for(j=-1; j<=1; j++)
			{
				if(i!=j && i+j && inrange(u+i, v+j))
				{
					getdata(G[u+i][v+j], b1, w1, u1, v1);
					if(w1 + b < b1)
					{
						G[u+i][v+j].first.first = w1 + b;
						Q.push(G[u+i][v+j]);
					}
				}
			}
		}
	}
}

int main()
{
	int t, i, j, v, hi, hj, time;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &R, &C);
		for(i=0; i<R; i++)
		{
			for(j=0; j<C; j++)
			{
				scanf("%d", &v);
				G[i][j].first.first = inf;
				G[i][j].first.second = v;
				G[i][j].second.first = i;
				G[i][j].second.second = j;
			}
		}
		dijkstra();
		scanf("%d%d%d", &hi, &hj, &time);;
		hi--, hj--;
		if(G[hi][hj].first.first <= time) printf("YES\n%d\n", time-G[hi][hj].first.first);
		else printf("NO\n");
	}
	return 0;
}

