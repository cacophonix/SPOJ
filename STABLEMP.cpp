/*
USER: zobayer
TASK: STABLEMP
ALGO: stable marriage
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 555;
int n, L[MAX][MAX], R[MAX][MAX], L2R[MAX], R2L[MAX], p[MAX];

void stable() {
	memset(R2L, -1, sizeof R2L);
	memset(p, 0, sizeof p);
	for(int i = 0; i < n; i++) {
		int girl = i;
		while(girl >= 0) {
			int boy;
			while(true) {
				boy = L[girl][p[girl]++];
				if(R2L[boy] < 0 || R[boy][girl] > R[boy][R2L[boy]]) break;
			}
			int match = R2L[boy];
			R2L[L2R[girl] = boy] = girl;
			girl = match;
		}
	}
}

int main() {
	int t, part, wom, man;
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d", &man);
			man--;
			for(int j = 0; j < n; j++) {
				scanf("%d", &part);
				part--;
				R[man][part] = n - j;
			}
		}
		for(int i = 0; i < n; i++) {
			scanf("%d", &wom);
			wom--;
			for(int j = 0; j < n; j++) {
				scanf("%d", &part);
				part--;
				L[wom][j] = part;
			}
		}
		
		stable();
		for(int i = 0; i < n; i++) printf("%d %d\n", i + 1, L2R[i] + 1);
	}
	return 0;
}
