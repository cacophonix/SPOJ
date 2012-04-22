/*
USER: zobayer
TASK: LITE
ALGO: segment tree
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 200064, BUFF = 128, PARAM = 4;

struct TreeNode { int total, state; } T[MAX];

void update(int Node, int ri, int rj, int i, int j) {
	if(i==ri && j==rj) {
		T[Node].state ^= 1;
		T[Node].total = rj - ri + 1 - T[Node].total;
		return;
	}
	int m = (ri + rj) >> 1, L = Node << 1, R = L + 1;
	if(j <= m) update(L, ri, m, i, j);
	else if(i > m) update(R, m+1, rj, i, j);
	else {
		update(L, ri, m, i, m);
		update(R, m+1, rj, m+1, j);
	}
	if(T[Node].state) T[Node].total = rj - ri + 1 - T[L].total - T[R].total;
	else T[Node].total = T[L].total + T[R].total;
}

int query(int Node, int ri, int rj, int i, int j) {
	if(i==ri && j==rj) return T[Node].total;
	int m = (ri + rj) >> 1, ret, L = Node << 1, R = L + 1;
	if(j <= m) ret = query(L, ri, m, i, j);
	else if(i > m) ret = query(R, m+1, rj, i, j);
	else {
		ret = query(L, ri, m, i, m);
		ret += query(R, m+1, rj, m+1, j);
	}
	if(T[Node].state) return j - i + 1 - ret;
	return ret;
}

static int *readln() {
	static char buff[BUFF], *p;
	static int param[PARAM];
	int idx = 0;
	fgets(buff, 128, stdin);
	p = strtok(buff, " ");
	while(p) {
		param[idx++] = atoi(p);
		p = strtok(0, " ");
	}
	return param;
}

int main() {
	int n, m, q, i, j, *param;
	param = readln(), n = param[0], m = param[1];
	while(m--) {
		param = readln(), q = param[0], i = param[1], j = param[2];
		switch(q) {
			case 0: update(1, 0, n-1, i-1, j-1); break;
			case 1: printf("%d\n", query(1, 0, n-1, i-1, j-1)); break;
		}
	}
	return 0;
}
