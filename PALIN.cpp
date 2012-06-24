/*
USER: zobayer
TASK: PALIN
ALGO: ad-hoc
*/

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
using namespace std;

#define i64 long long
#define eps 1e-10

#define OFF ios::sync_with_stdio(false)
#define IOR(x) freopen(x,"r",stdin)
#define IOW(x) freopen(x,"w",stdout)

#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define clr(x) x.clear()
#define sz size()
#define mset(x,v) memset(x,v,sizeof(x))

#define MAX 1001001

char str[MAX];

void makepal(int len, int odd)
{
	int j, i = len-1, k = odd? len-1 : len, carry = 1, a;
	for(; i>=0 || carry; i--, k++)
	{
		a = (i>=0)? str[i] - '0' : 0;
		str[k] = (a + carry) % 10 + '0';
		carry = (a + carry) / 10;
	}
	str[k] = 0;
	for(i=0, j=k-1; i < j; i++, j--) str[i] = str[j];
}

int main()
{
	int t, len, odd, mid, i, j, flag;
	for(scanf("%d", &t); t; t--)
	{
		scanf("%s", str);
		len = strlen(str);
		mid = (len + 1) / 2;
		odd = (len & 1) ? 1 : 0;
		i = mid-1, j = mid, flag = 0;
		for(i=odd?i-1:i; i>=0 && j<len; i--, j++)
		{
			if(str[i] > str[j]) { str[j] = str[i]; flag = 1; }
			else if(str[i]==str[j]) str[j] = str[i];
			else break;
		}
		if(! flag) makepal(mid, odd);
		printf("%s\n",str);
	}
	return 0;
}
