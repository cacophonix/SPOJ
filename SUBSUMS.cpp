/*
USER: zobayer
TASK: SUBSUMS
ALGO: bitmask
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
#define DEBUG if(0)

#define i64 long long
#define u64 unsigned long long
#define eps 1e-10

#define LET(x,p) __typeof(p) x
#define FORIT(it,p) for(__typeof(p.end()) it=p.begin();it!=p.end();it++)
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)

#define ALL(p) p.begin(),p.end()
#define CLR(p) p.clear()
#define pb(p) push_back(p)
#define pii pair< int, int >
#define mset(p,v) memset(p,v,sizeof(p))
#define UB(p,v) upper_bound(ALL(p),v)
#define LB(p,v) lower_bound(ALL(p),v)

#define MAX 18
#define INF 2147483647

int sum1[1<<MAX], sum2[1<<MAX];
int s1[MAX], s2[MAX];

int main()
{
	DEBUG IOR("in.txt");
	int a, b, n, h1, h2, tot, hi, lo;
	i64 cnt;
	scanf("%d %d %d", &n, &a, &b);
	h1 = n>>1;
	h2 = (n+1)>>1;
	REP(i,h1) scanf("%d", &s1[i]);
	REP(i,h2) scanf("%d", &s2[i]);

	// for the left half
	REP(i,(1<<h1))
	{
		tot = 0;
		REP(j,h1)
			if((i>>j)&1)
				tot += s1[j];
		sum1[i] = tot;
	}
	sum1[1<<h1] = INF;

	// for the right half
	REP(i,(1<<h2))
	{
		tot = 0;
		REP(j,h2)
			if((i>>j)&1)
				tot += s2[j];
		sum2[i] = tot;
	}
	sum2[1<<h2] = INF;

	sort(sum2, sum2+(1<<h2));

	DEBUG REP(i,1<<h1) printf("s1[%d] = %d\n", i, sum1[i]);
	DEBUG REP(i,1<<h2) printf("s2[%d] = %d\n", i, sum2[i]);

	cnt = 0;
	REP(i,(1<<h1))
	{
		lo = lower_bound(sum2, sum2+(1<<h2), a-sum1[i]) - sum2;
		hi = upper_bound(sum2, sum2+(1<<h2), b-sum1[i]) - sum2;
		//if(sum2[hi]!=b-sum1[i]) hi--;
		hi--;
		DEBUG printf("low = %d; hi = %d\n", lo, hi);
		if(lo<=hi) cnt += (i64)(hi-lo+1);
	}

	printf("%lld\n", cnt);
	return 0;
}
/* END OF CODE */
