/*
USER: zobayer
TASK: GNYR09F
ALGO: dynamic programming
*/

#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<numeric>
#include<fstream>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define memo(a,v) memset(a,v,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define eps (1e-9)
#define inf (1<<29)
#define i64 long long
#define u64 unsigned i64
int N, K;
i64 dp[ 110 ][ 110 ][ 2 ];
i64 cal( int pos, int total, int prev )
{
	if( total < 0 ) return 0;
	if( pos < 0 ){
		if( total == 0 ) return 1;
		return 0;
	}
	i64 &ret = dp[ pos ][ total ][ prev ];
	if( ret != -1 ) return ret;
	ret = 0;
	if( prev == 1 ){
		ret += cal(pos - 1, total - 1, 1 );
		ret += cal(pos - 1, total, 0 );
	}
	else
	{
		ret += cal(pos - 1, total, 1 );
		ret += cal(pos - 1, total, 0 );
	}
	return ret;
}
int main()
{
	//freopen("b.txt","r",stdin);
	int tc;
	memo(dp,-1);
	cin >> tc;
	while( tc -- )
	{
		
		int cs;
		cin >> cs >> N >> K;
		cout << cs<<" ";
		i64 ret = cal(N - 2,K,0) ;
		ret += cal(N - 2,K,1);
		cout << ret << endl	;
	}
	return 0;
}
