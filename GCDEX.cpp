/*
USER: zobayer
TASK: GCDEX
ALGO: math, euler phi
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

#define MAX 1000001

i64 g[MAX];
int phi[MAX];

int main()
{
	//IOR("in.txt");
	//IOW("out.txt");
	int i, j, n;

	for(i=2,phi[1]=1; i<MAX; i++)
	{
		if(!phi[i])
		{
			phi[i] = i-1;
			for(j=(i<<1); j<MAX; j+=i)
			{
				if(!phi[j]) phi[j] = j;
				phi[j] = phi[j]/i*(i-1);
			}
		}
	}

	for(i=1; i<MAX; i++)
		for(j=2; i*j<MAX; j++)
			g[i*j] += i*phi[j];

	for(i=2; i<MAX; i++)
		g[i] += g[i-1];

	while(scanf("%d", &n)==1 && n)
		printf("%lld\n", g[n]);

	return 0;
}
