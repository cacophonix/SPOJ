/*
USER: zobayer
TASK: GSS3
ALGO: segment tree
*/

#include <cstdio>
using namespace std;

struct Tree { int maxv, sum, lval, rval; };
const int MAX = 1 << 16;
int a[MAX];
Tree T[MAX << 1];

inline int max2(int a, int b) {
	return ((a > b)? a : b);
}

inline int max3(int a, int b, int c) {
	return max2(a, max2(b, c));
}

void init(int Node, int i, int j) {
	if(i==j) {
		T[Node].maxv = T[Node].sum = T[Node].rval = T[Node].lval = a[i];
		return;
	}
	int m = (i+j)/2;
	init(2*Node, i, m);
	init(2*Node+1, m+1, j);
	T[Node].sum = T[Node*2].sum + T[Node*2+1].sum;
	T[Node].maxv = max3(T[2*Node].maxv, T[2*Node].rval + T[2*Node+1].lval, T[2*Node+1].maxv);
	T[Node].lval = max2(T[2*Node].lval, T[2*Node].sum + T[2*Node+1].lval);
	T[Node].rval = max2(T[2*Node].rval + T[2*Node+1].sum, T[2*Node+1].rval);
}

void update(int Node, int i, int j, int idx, int val) {
	if(i==j && j==idx) {
		T[Node].maxv = T[Node].sum = T[Node].rval = T[Node].lval = a[idx] = val;
		return;
	}
	int m = (i+j)/2;
	if(idx<=m) update(2*Node, i, m, idx, val);
	else update(2*Node+1, m+1, j, idx, val);
	T[Node].sum = T[Node*2].sum + T[Node*2+1].sum;
	T[Node].maxv = max3(T[2*Node].maxv, T[2*Node].rval + T[2*Node+1].lval, T[2*Node+1].maxv);
	T[Node].lval = max2(T[2*Node].lval, T[2*Node].sum + T[2*Node+1].lval);
	T[Node].rval = max2(T[2*Node].rval + T[2*Node+1].sum, T[2*Node+1].rval);
}

void find(Tree &res, int Node, int L, int R, int i, int j) {
	if(L==i && R==j) {
		res = T[Node];
		return;
	}
	int m = (L + R)/2;
	if(j<=m) find(res, 2*Node, L, m, i, j);
	else if(i>m) find(res, 2*Node+1, m+1, R, i, j);
	else {
		Tree Left, Right;
		find(Left, 2*Node, L, m, i, m);
		find(Right, 2*Node+1, m+1, R, m+1, j);
		res.maxv = max3(Left.maxv, Right.maxv, Left.rval + Right.lval);
		res.sum = Left.sum + Right.sum;
		res.lval = max2(Left.lval, Left.sum + Right.lval);
		res.rval = max2(Left.rval + Right.sum, Right.rval);
	}
}

int main() {
	int n, i, j, m, t;
	Tree res;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &a[i]);
	init(1, 0, n-1);
	scanf("%d", &m);
	while(m--) {
		scanf("%d%d%d", &t, &i, &j);
		if(t) {
			find(res, 1, 0, n-1, --i, --j);
			printf("%d\n", res.maxv);
		}
		else update(1, 0, n-1, --i, j);
	}
	return 0;
}
