/*
USER: zobayer
TASK: ONEZERO
ALGO: breadth first search
*/

#include <cstdio>
using namespace std;

const int MAX = 20002;

struct pred { int p; char c; } pre[MAX];
bool flag[MAX];
int n, Q[MAX];

inline int mod(int b, int m) {
	if(b < m) return b;
	return b % m;
}

void bfs(int s) {
	int qh, qt, p[2], i, u;
	qh = qt = 0;
	Q[qt++] = s;
	flag[s] = 1;
	pre[s].p = -1;
	pre[s].c = '1';
	while(qh < qt) {
		u = Q[qh++];
		p[0] = mod((u * mod(10, n)), n);
		p[1] = mod(p[0]+1, n);
		for(i=0; i<2; i++) {
			if(!flag[p[i]]) {
				pre[p[i]].p = u;
				pre[p[i]].c = '0'+i;
				if(!p[i]) return;
				flag[p[i]] = 1;
				Q[qt++] = p[i];
			}
		}
	}
}

void print_path(int u) {
	if(u==-1) return;
	print_path(pre[u].p);
	putchar(pre[u].c);
}

int main() {
	int t, i;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		if(n==1) {
			puts("1");
			continue;
		}
		for(i=0; i<n; i++) flag[i] = 0;
		bfs(1);
		print_path(0);
		putchar('\n');
	}
	return 0;
}
