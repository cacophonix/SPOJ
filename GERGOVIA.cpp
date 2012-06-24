/*
USER: zobayer
TASK: GERGOVIA
ALGO: greedy
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
#define i64 long long

#define ALL(p) p.begin(),p.end()
#define CLR(p) p.clear()
#define pb(x) push_back(x)
#define pii pair<int,int>
#define mset(p,v) memset(p,v,sizeof(p))

#define ABS(x) (((x)<0)?-(x):(x))

int main()
{
	//IOR("in.txt");
	//IOW("out.txt");
	int n, i, a;
	long long res, tot;
	while(scanf("%d", &n)==1 && n)
	{
		res = tot = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d", &a);
			tot += a;
			res += ABS(tot);
		}
		printf("%lld\n", res);
	}
	return 0;
}
