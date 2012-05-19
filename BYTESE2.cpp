/*
USER: zobayer
TASK: BYTESE2
ALGO: simulation, sorting
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

#define MAX 101

int main()
{
	DEBUG IOR("in.txt");
	int t, n, a[MAX], b[MAX], total, best;
	scanf("%d", &t);
	REP(x,t)
	{
		total = best = 0;

		scanf("%d", &n);
		REP(i,n) scanf("%d%d", &a[i], &b[i]);

		sort(a, a+n);
		sort(b, b+n);

		for(int i=0,j=0; i<n && j<n; )
		{
			if(a[i] < b[j]) total++, i++;
			else total--, j++;

			best = max(best, total);
		}

		printf("%d\n", best);
	}
	return 0;
}
