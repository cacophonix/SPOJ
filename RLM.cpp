/*
USER: zobayer
TASK: RLM
ALGO: simulation
*/

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

i64 decode(char *str) {
	i64 ret = 0;
	int p, q;
	for(int i=0; str[i]; i+=2) {
		p = str[i]-'0';
		q = str[i+1]-'0';
		while(p--) ret = ret*10 + q;
	}
	return ret;
}

void encode(i64 n1, i64 n2, char *op, char *res) {
	int k = 0, cnt;
	i64 r;
	char temp[25], v;
	switch(op[0]) {
		case '+': r = n1 + n2; break;
		case '-': r = n1 - n2; break;
		case '*': r = n1 * n2; break;
		case '/': r = n1 / n2; break;
	}
	sprintf(temp, "%lld", r);
	for(int i=0, j; temp[i]; i=j) {
		v = temp[i];
		for(j=i,cnt=0; j<i+9 && temp[j] && v==temp[j]; j++,cnt++);
		res[k++] = cnt+'0';
		res[k++] = v;
	}
	if(!k) strcpy(res,"10"), k+=2;
	res[k] = 0;
}

int main() {
	DEBUG IOR("in.txt");
	char num1[25], num2[25], op[2], res[50];
	i64 n1, n2;
	while(scanf("%s%s%s", num1, op, num2)==3) {
		n1 = decode(num1);
		n2 = decode(num2);
		encode(n1, n2, op, res);
		printf("%s %s %s = %s\n", num1, op, num2, res);
	}
	return 0;
}
