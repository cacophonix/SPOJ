/*
USER: zobayer
TASK: POLEVAL
ALGO: modular exponentiation
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

#define MAX 1001

i64 dp[101][MAX];

inline i64 sq(i64 x)
{
	return x*x;
}

i64 Pow(int n, int p)
{
	if(p==0) return dp[n][p]=1;
	if(n==0) return dp[n][p]=0;
	if(p==1) return dp[n][p]=n;
	if(p==2) return dp[n][p]=n*n;
	if(dp[n][p]) return dp[n][p];
	if(p&1) return dp[n][p]=n*Pow(n,p-1);
	return dp[n][p]=sq(Pow(n,p/2));
}

int main()
{
	//IOR("in.txt");
	//IOW("out.txt");
	int n, k, i, j, c = 1, x;
	i64 res, coeff[MAX], temp;
	while(scanf("%d", &n)==1 && n>=0)
	{
		printf("Case %d:\n", c++);
		for(i=n; i>=0; i--)
			scanf("%lld", &coeff[i]);
		scanf("%d", &k);
		for(i=0; i<k; i++)
		{
			scanf("%d", &x);
			res = 0;
			for(j=0; j<=n; j++)
			{
				if(x<0)
				{
					temp = Pow(-x, j);
					if(j&1) temp = -temp;
				}
				else temp = Pow(x, j);
				res += coeff[j]*temp;
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}
