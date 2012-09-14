/*
USER: zobayer
TASK: RPAR
ALGO: segment tree
*/

#include <cstdio>

const int MAX = 1 << 18;
const int MOD = 10007;

struct Tree {
	int a, b, c;
	int ca, cb, cc;
	int xs, x;
} T[MAX];

void push(int node, int a, int b, int c, int n) {
	T[node].ca = (T[node].ca + a) % MOD;
	T[node].cb = (T[node].cb + b) % MOD;
	T[node].cc = (T[node].cc + c) % MOD;

	T[node].a = (T[node].a + a * T[node].xs) % MOD;
	T[node].b = (T[node].b + b * T[node].x) % MOD;
	T[node].c = (T[node].c + c * n) % MOD;
}

void fix(Tree &root, const Tree &lt, const Tree &rt) {
	root.a = (lt.a + rt.a) % MOD;
	root.b = (lt.b + rt.b) % MOD;
	root.c = (lt.c + rt.c) % MOD;
}

void init(int node, int i, int j) {
	T[node].ca = T[node].cb = T[node].cc = 0;
	T[node].a = T[node].b = T[node].c = 0;
	if(i == j) {
		T[node].xs = ((i % MOD) * (i % MOD)) % MOD;
		T[node].x = i % MOD;
		return;
	}
	int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1;
	init(lt, i, mid);
	init(rt, mid + 1, j);
	T[node].xs = (T[lt].xs + T[rt].xs) % MOD;
	T[node].x = (T[lt].x + T[rt].x) % MOD;
}

void update(int node, int i, int j, int p, int q, int a, int b, int c) {
	if(i == p && j == q) {
		push(node, a, b, c, (j - i + 1) % MOD);
		return;
	}
	int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1;
	push(lt, T[node].ca, T[node].cb, T[node].cc, (mid - i + 1) % MOD);
	push(rt, T[node].ca, T[node].cb, T[node].cc, (j - mid) % MOD);
	T[node].ca = T[node].cb = T[node].cc = 0;
	if(q <= mid) update(lt, i, mid, p, q, a, b, c);
	else if(p > mid) update(rt, mid + 1, j, p, q, a, b, c);
	else {
		update(lt, i, mid, p, mid, a, b, c);
		update(rt, mid + 1, j, mid + 1, q, a, b, c);
	}
	fix(T[node], T[lt], T[rt]);
}

Tree query(int node, int i, int j, int p, int q) {
	if(i == p && j == q) return T[node];
	int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1;
	push(lt, T[node].ca, T[node].cb, T[node].cc, (mid - i + 1) % MOD);
	push(rt, T[node].ca, T[node].cb, T[node].cc, (j - mid) % MOD);
	T[node].ca = T[node].cb = T[node].cc = 0;
	if(q <= mid) return query(lt, i, mid, p, q);
	else if(p > mid) return query(rt, mid + 1, j, p, q);
	else {
		Tree res, ls, rs;
		ls = query(lt, i, mid, p, mid);
		rs = query(rt, mid + 1, j, mid + 1, q);
		fix(res, ls, rs);
		return res;
	}
}

int main() {
	int n, q, t, x0, x1, a, b, c;
	Tree sum;
	scanf("%d %d", &n, &q);
	init(1, 0, n-1);
	while(q--) {
		scanf("%d", &t);
		if(t) {
			scanf("%d %d", &x0, &x1);
			sum = query(1, 0, n-1, x0, x1);
			printf("%d\n", (sum.a + sum.b + sum.c) % MOD);
		}
		else {
			scanf("%d %d %d %d %d", &x0, &x1, &a, &b, &c);
			update(1, 0, n-1, x0, x1, a, b, c);
		}
	}
	return 0;
}
