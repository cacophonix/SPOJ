/*
USER: zobayer
TASK: FISHER
ALGO: dynamic programming
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN=1024;
const int INF=0x3f3f3f3f;

int T,N;

struct state {
	int r , t ;
	state() {
		r = t = INF;
	}
	state(int _r,int _t) {
		r = _r;
		t = _t;
	}
	bool operator<(const state &A)const {
		if( t > T && A.t > T )
			return r < A.r;
		if( t > T )
			return false;
		if( A.t > T )
			return true;
		if( r != A.r )
			return r < A.r;
		if( t != A.t )
			return t < A.t;
		return false;
	}
};

state dp[MAXN][MAXN];
int risk[MAXN][MAXN];
int dist[MAXN][MAXN];

int main() {
	while(scanf("%d%d",&N,&T)==2 && N+T) {
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				scanf("%d",&dist[i][j]);
		for(int i = 1; i <= N; i++)
			for(int j = 1; j <= N; j++)
				scanf("%d",&risk[i][j]);
		for(int i = 0;i <= N; i++)
			for(int j = 0;j <= T; j++)
				dp[j][i]=state();
		for(int i = 0; i <= T; i++)
			dp[i][N] = state(0,0);
		for(int i = 1; i <= T; i++) {
			for(int j = 1; j <= N; j++) {
				for(int k = 1; k <= N; k++) {
					if((j==k)||(i<dist[j][k])) continue;
					state next;
					next.r = risk[j][k] + dp[i-dist[j][k]][k].r;
					next.t = dist[j][k] + dp[i-dist[j][k]][k].t;
					if(next < dp[i][j]) dp[i][j]=next;
				}
			}
		}
		printf("%d %d\n", dp[T][1].r, dp[T][1].t );
	}
	return 0;
}
