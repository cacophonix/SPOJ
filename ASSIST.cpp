/*
USER: zobayer
TASK: ASSIST
ALGO: simulation
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

#define READ(x) freopen(x,"r",stdin)
#define WRITE(x) freopen(x,"w",stdout)
#define SET(x) memset(x,-1,sizeof(x))
#define CLR(x) memset(x,0,sizeof(x))
#define ABS(x) (((x)<0)?-(x):(x))
#define ALL(x) x.begin(),x.end()

#define MAX 34000
#define TAR 3000
#define INF (1<<28)
#define NIL -1

#define i64 long long
#define eps (1e-10)

int lucky[TAR+1];
bool flag[MAX+1];

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	for(int i=1,k=2; i<=TAR; i++, k++) {
		while(flag[k]) k++;
		lucky[i] = k;
		for(int j=k+1,c=0; j<=MAX; j++) {
			if(flag[j]) continue;
			c++;
			if(c==k) {
				flag[j] = 1;
				c = 0;
			}
		}
	}
	//for(int i=1; i<=TAR; i++) printf("%d\t", lucky[i]);
	int n;
	while(scanf("%d", &n)==1 && n) {
		printf("%d\n", lucky[n]);
	}
	return 0;
}
