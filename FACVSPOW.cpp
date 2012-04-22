/*
USER: zobayer
TASK: FACVSPOW
ALGO: math
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

int a[MAX];

int main() {
	//IOR("in.txt");
	//IOW("out.txt");
	int i, j;
	double left, right, v;
	a[1] = 2;
	left = log(2.0);
	for(i=j=2; i<MAX; i++) {
		v = log((double)i);
		for(++j; ;j++) {
			left += log((double)j);
			right = v*j;
			if(left > right) {
				a[i] = j;
				break;
			}
		}
	}
	int t, n;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		printf("%d\n", a[n]);
	}
	return 0;
}
