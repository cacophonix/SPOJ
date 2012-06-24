/*
USER: zobayer
TASK: GSS7
ALGO: heavy light decomposition, segment tree
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100001;

struct Segment {
	int sum, max, pre, suf, lzy, val;
};

struct Chain {
	int n, *a;
	Segment *T;
	Chain(int *aa, int cn) {
		a = new int[n = cn];
		T = new Segment[n << 2];
		memcpy(a, aa, sizeof(int) * n);
		init(1, 0, n-1);
	}
	inline void push(Segment &x, int i, int j, int val) {
		x.lzy = i!=j, x.val = val;
		x.sum = (j - i + 1) * val;
		x.max = x.suf = x.pre = max(0, x.sum);
	}
	inline void update(Segment &x, const Segment &lt, const Segment &rt) {
		x.sum = lt.sum + rt.sum;
		x.max = max(0, max(max(lt.max, rt.max), lt.suf + rt.pre));
		x.pre = max(0, max(lt.pre, lt.sum + rt.pre));
		x.suf = max(0, max(rt.suf, rt.sum + lt.suf));
	}
	void init(int x, int i, int j) {
		T[x].lzy = 0;
		if(i == j) {
			push(T[x], i, j, a[i]);
			return;
		}
		int mid = (i + j) >> 1, lt = x << 1, rt = lt | 1;
		init(lt, i, mid);
		init(rt, mid + 1, j);
		update(T[x], T[lt], T[rt]);
	}
	void upd(int x, int i, int j, int p, int q, int val) {
		if(i == p && j == q) {
			push(T[x], i, j, val);
			return;
		}
		int mid = (i + j) >> 1, lt = x << 1, rt = lt | 1;
		if(i < j && T[x].lzy) {
			T[x].lzy = 0;
			push(T[lt], i, mid, T[x].val);
			push(T[rt], mid + 1, j, T[x].val);
		}
		if(q <= mid) upd(lt, i, mid, p, q, val);
		else if(p > mid) upd(rt, mid + 1, j, p, q, val);
		else {
			upd(lt, i, mid, p, mid, val);
			upd(rt, mid + 1, j, mid + 1, q, val);
		}
		update(T[x], T[lt], T[rt]);
	}
	Segment ask(int x, int i, int j, int p, int q) {
		Segment ret, lres, rres;
		if(T[x].lzy) {
			push(ret, p, q, T[x].val);
			return ret;
		}
		if(i == p && j == q) return T[x];
		int mid = (i + j) >> 1, lt = x << 1, rt = lt | 1;
		if(q <= mid) return ask(lt, i, mid, p, q);
		else if(p > mid) return ask(rt, mid + 1, j, p, q);
		else {
			lres = ask(lt, i, mid, p, mid);
			rres = ask(rt, mid + 1, j, mid + 1, q);
			update(ret, lres, rres);
			return ret;
		}
	}
};

vector< int > G[MAX];
int cost[MAX], lvl[MAX], parent[MAX];
int head[MAX], cnext[MAX], chainid[MAX], chainpos[MAX];

int nchain;
vector< Chain * > chains;

int temp[MAX];

int dfs(int u, int p, int d) {
	int i, v, sz = G[u].size(), tmp, mx, id, tot, hd, k;
	lvl[u] = d, mx = 0, id = u, tot = 1;
	for(i = 0; i < sz; i++) {
		v = G[u][i];
		if(v != p) {
			parent[v] = u;
			tmp = dfs(v, u, d + 1);
			tot += tmp;
			if(tmp > mx) {
				mx = tmp;
				id = v;
			}
		}
	}
	if(tot == 1) cnext[u] = -1;
	else cnext[u] = id;
	for(i = 0; i < sz; i++) {
		v = G[u][i];
		if(v != p && v != id) {
			for(hd = v, k = 0; v != -1; v = cnext[v], k++) {
				head[v] = hd;
				temp[k] = cost[v];
				chainpos[v] = k;
				chainid[v] = nchain;
			}
			chains.push_back(new Chain(temp, k));
			nchain++;
		}
	}
	return tot;
}

void hld(int v) {
	int hd, k;
	nchain = 0; lvl[0] = -1;
	dfs(v, 0, 0);
	for(hd = v, k = 0; v != -1; v = cnext[v], k++) {
		head[v] = hd;
		temp[k] = cost[v];
		chainpos[v] = k;
		chainid[v] = nchain;
	}
	chains.push_back(new Chain(temp, k));
	nchain++;
}

int lca(int a, int b) {
	while(chainid[a] != chainid[b]) {
		if(lvl[head[a]] < lvl[head[b]]) b = parent[head[b]];
		else a = parent[head[a]];
	}
	return (lvl[a] < lvl[b]) ? a : b;
}

void update(int ca, int u, int w) {
	int chid, chpos;
	Chain *ch;
	while(lvl[u] > lvl[ca]) {
		chid = chainid[u]; chpos = chainpos[u]; ch = chains[chid];
		if(lvl[head[u]] > lvl[ca]) ch->upd(1, 0, ch->n - 1, chainpos[head[u]], chainpos[u], w);
		else ch->upd(1, 0, ch->n - 1, chainpos[ca] + 1, chainpos[u], w);
		u = parent[head[u]];
	}
}

Segment query(int ca, int u) {
	int chid, chpos;
	Chain *ch;
	Segment tmpr = {0, 0, 0, 0, 0, 0}, tmpl, root;
	while(lvl[u] > lvl[ca]) {
		chid = chainid[u]; chpos = chainpos[u]; ch = chains[chid];
		if(lvl[head[u]] > lvl[ca]) tmpl = ch->ask(1, 0, ch->n - 1, chainpos[head[u]], chainpos[u]);
		else tmpl = ch->ask(1, 0, ch->n - 1, chainpos[ca] + 1, chainpos[u]);
		ch->update(root, tmpl, tmpr);
		tmpr = root;
		u = parent[head[u]];
	}
	return tmpr;
}

int main() {
	int n, q, i, u, v, w, tt, ca, chid, chpos;
	Segment ltr, rtr, mid, res;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for(i = 1; i <= n; i++) scanf("%d", &cost[i]);
	for(i = 1; i < n; i++) {
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	hld(1);
	scanf("%d", &q);
	while(q--) {
		scanf("%d %d %d", &tt, &u, &v);
		ca = lca(u, v);
		if(tt == 1) {
			ltr = query(ca, u);
			rtr = query(ca, v);
			chid = chainid[ca];
			chpos = chainpos[ca];
			mid = chains[chid]->ask(1, 0, chains[chid]->n - 1, chpos, chpos);
			res.pre = max(0, max(mid.pre, mid.sum + ltr.pre));
			res.max = max(0, max(max(ltr.max, mid.max), ltr.pre + mid.suf));
			ltr = res;
			res.max = max(0, max(max(ltr.max, rtr.max), ltr.pre + rtr.pre));
			printf("%d\n", res.max);
		}
		else {
			scanf("%d", &w);
			update(ca, u, w);
			update(ca, v, w);
			chid = chainid[ca];
			chpos = chainpos[ca];
			chains[chid]->upd(1, 0, chains[chid]->n - 1, chpos, chpos, w);
		}
	}
	return 0;
}