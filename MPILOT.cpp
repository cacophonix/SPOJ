/*
USER: zobayer
TASK: MPILOT
ALGO: dynamic programming
*/

#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;

#define FORIT(i, m) for (__typeof((m).begin()) i=(m).begin(); i!=(m).end(); ++i)
#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)

#define sz size()
#define pb push_back
#define ALL(x) x.begin(), x.end()

#define i64 long long
#define SET(t,v) memset((t), (v), sizeof(t))
#define REV(x) reverse( ALL( x ) )

#define IO freopen("","r",stdin); freopen("","w",stdout);
#define debug(x) cerr << __LINE__ <<" "<< #x " = " << x << endl

#define M 10005
int a[M], b[M];
int memo[2][M], n;

int main() {
	
	scanf("%d",&n);
	REP(i,n) scanf("%d %d",&a[n-i-1], &b[n-i-1] );
	SET( memo, 0 );
	
	int pos = n, lim = n/2 + 1;
	while( --pos >= 0 ) {
		int turn, last; turn = (pos & 1), last = 1 - turn; 
		REP( p, lim ) {
			int& ret = memo[ turn ][ p ];
			int copilot = pos - p;
			if( p < copilot ) ret = (1<<30);
			else if( p+1 == lim ) ret = b[pos] + memo[ last ][ p ];
			else ret = min( a[pos] + memo[ last ][ p+1 ], b[pos] + memo[ last ][ p ] );
		}
	}

	printf("%d\n",memo[0][0]);
	return 0;
}
