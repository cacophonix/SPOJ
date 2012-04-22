/*
USER: zobayer
TASK: JRIDE
ALGO: dynamic programming
*/

#include <cstdio>
using namespace std;

const int MAX = 100032;
int in[MAX];

int main(){
	int i, te, tc = 1, n, ts, td, tmp, s, d, ans;
	scanf("%d",&te);
	while(te--){
		scanf("%d",&n); n--;
		for(i = 0; i < n; i++) scanf("%d",&in[i]);
		ts = 0, td, tmp = 0, ans = -1, s = -1, d = -1;
		for(i = 0; i < n; i++) {
			td = i;
			if(tmp+in[i] > ans) {
				ans = tmp+in[i];
				s = ts;
				d = td;
			}
			else if(tmp+in[i] == ans && td-ts > d-s) {
				s=ts;
				d=td;
			}
			if(tmp+in[i] >= 0) tmp+=in[i];
			else if(tmp+in[i] < 0) {
				tmp = 0;
				ts = i+1;
			}
		}
		if(s != -1) printf("The nicest part of route %d is between stops %d and %d\n", tc++, s+1, d+2);
		else printf("Route %d has no nice parts\n",tc++);
	}
	return 0;
}
