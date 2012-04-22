/*
USER: zobayer
TASK: LUCKYNUM
ALGO: breadth first search
*/

#include <cstdio>
using namespace std;

const int MAX = 10000;

struct QData {
	int mod, from;
} Q[MAX];

struct NData {
	int d;
	QData p;
	char ch;
	bool f, a;
} N[MAX][2];

int k;

inline int myMod(int b, int m) {
	return (b<m? b : b%m);
}

void bfs() {
	int qh, qt, u, f, v[2], temp, i, dig[2] = {6, 8};
	qh = qt = 0;
	Q[qt].mod = 0; Q[qt].from = -1; qt++;
	while(qh < qt) {
		u = Q[qh].mod, f = Q[qh].from; qh++;
		temp = myMod(u * myMod(10, k), k);
		v[0] = myMod(temp + myMod(6, k), k);
		v[1] = myMod(temp + myMod(8, k), k);
		if(f==-1) {
			for(i=0; i<2; i++) {
				N[v[i]][i].ch = '0'+dig[i];
				N[v[i]][i].a = i;
				N[v[i]][i].f = 1;
				N[v[i]][i].d = 1;
				N[v[i]][i].p.from = N[v[i]][i].p.mod = -1;
				if(!v[i]) return;
				Q[qt].mod = v[i]; Q[qt].from = i; qt++;
			}
		}
		else if(N[u][f].a) {
			for(i=0; i<2; i++) if(!N[v[i]][i].f) {
				N[v[i]][i].ch = '0'+dig[i];
				N[v[i]][i].f = 1;
				N[v[i]][i].a = (N[v[i]][i].ch==N[u][f].ch);
				N[v[i]][i].d = N[u][f].d + 1;
				N[v[i]][i].p.mod = u, N[v[i]][i].p.from = f;
				if(!v[i]) return;
				Q[qt].mod = v[i]; Q[qt].from = i; qt++;
			}
		}
		else {
			i = (N[u][f].ch=='8');
			if(!N[v[i]][i].f) {
				N[v[i]][i].ch = '0'+dig[i];
				N[v[i]][i].f = 1; N[v[i]][i].a = 0;
				N[v[i]][i].d = N[u][f].d + 1;
				N[v[i]][i].p.mod = u; N[v[i]][i].p.from = f;
				if(!v[i]) return;
				Q[qt].mod = v[i]; Q[qt].from = i; qt++;
			}
		}
	}
}

void printPath(int u, int f) {
	if(u==-1) return;
	printPath(N[u][f].p.mod, N[u][f].p.from);
	putchar(N[u][f].ch);
}

int main() {
	int t, i;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &k);
		for(i=0; i<k; i++) {
			N[i][0].f = N[i][1].f = 0;
			N[i][0].a = N[i][1].a = 1;
		}
		bfs();
		if(!N[0][0].f && !N[0][1].f) puts("-1");
		else {
			printPath(0, (N[0][0].f? 0:1));
			putchar('\n');
		}
	}
	return 0;
}
