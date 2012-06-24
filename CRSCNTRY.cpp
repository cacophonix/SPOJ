/*
USER: zobayer
TASK: CRSCNTRY
ALGO: dynamic programming
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

#define MAX 2002

int cardA[MAX], cardB[MAX], DP[2][MAX];

int lcs(int len1, int len2)
{
	int i, j;
	for(j=0; j<=len2; j++)
		DP[0][j] = 0;
	for(i=1; i<=len1; i++)
		for(j=1; j<=len2; j++)
			if(cardA[i-1]==cardB[j-1])
				DP[i&1][j] = DP[!(i&1)][j-1] + 1;
			else
				DP[i&1][j] = max(DP[!(i&1)][j], DP[i&1][j-1]);
	return DP[len1&1][len2];
}

int main()
{
	//IOR("in.txt");
	//IOW("out.txt");
	int t, len1, len2, n, best;
	scanf("%d", &t);
	while(t--)
	{
		len1 = best = 0;
		while(scanf("%d", &n)==1 && n)
			cardA[len1++] = n;
		while(scanf("%d", &n)==1 && n)
		{
			len2 = 0;
			cardB[len2++] = n;
			while(scanf("%d", &n)==1 && n)
				cardB[len2++] = n;
			best = max(best, lcs(len1, len2));
		}
		printf("%d\n", best);
	}
	return 0;
}
