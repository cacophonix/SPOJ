/*
USER: zobayer
TASK: RRSCHED
ALGO: segment tree
*/

#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long i64;

const int MAX = 1 << 16;
const int TMAX = 1 << 17;
const int INF = 0x7f7f7f7f;

int a[MAX], s[MAX], t[MAX];
int cnt[TMAX], rmq[TMAX];
i64 res[MAX];

void init(int node, int i, int j) {
	if(i == j) {
		cnt[node] = 1;
		rmq[node] = i;
		return;
	}
	int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1;
	init(lt, i, mid);
	init(rt, mid + 1, j);
	cnt[node] = cnt[lt] + cnt[rt];
	rmq[node] = a[rmq[lt]] < a[rmq[rt]] ? rmq[lt] : rmq[rt];
}

void remove(int node, int i, int j, int pos) {
	if(i == j) {
		cnt[node] = 0;
		a[i] = INF;
		return;
	}
	int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1;
	if(pos <= mid) remove(lt, i, mid, pos);
	else remove(rt, mid + 1, j, pos);
	cnt[node] = cnt[lt] + cnt[rt];
	rmq[node] = a[rmq[lt]] < a[rmq[rt]] ? rmq[lt] : rmq[rt];
}

int qcnt(int node, int i, int j, int p, int q) {
	if(i == p && j == q) return cnt[node];
	int mid = (i + j) >> 1, lt = node << 1, rt = lt | 1;
	if(q <= mid) return qcnt(lt, i, mid, p, q);
	else if(p > mid) return qcnt(rt, mid + 1, j, p, q);
	else return qcnt(lt, i, mid, p, mid) + qcnt(rt, mid + 1, j, mid + 1, q);
}

bool comp(const int &x, const int &y) {
	return a[x] < a[y];
}

int main() {
	int n, i, j, lowpos, st, en, pos, last;
	i64 ttime;
	//freopen("in", "r", stdin);
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		s[i] = a[i];
		t[i] = i;
	}
	sort(t, t + n, comp);
	sort(s, s + n);
	init(1, 0, n-1);
	last = 0; ttime = 0;
	while(a[rmq[1]] < INF) {
		lowpos = rmq[1];
		st = lower_bound(s, s + n, a[lowpos]) - s;
		en = upper_bound(s, s + n, a[lowpos]) - s;
		for(j = st; j < en; j++) {
			pos = qcnt(1, 0, n-1, 0, t[j]);
			res[t[j]] = (i64)cnt[1] * (a[lowpos] - last - 1) + pos + ttime;
		}
		ttime = (i64)cnt[1] * (a[lowpos] - last) + ttime;
		last = a[lowpos];
		for(j = st; j < en; j++) remove(1, 0, n-1, t[j]);
	}
	for(i = 0; i < n; i++) printf("%lld\n", res[i]);
	return 0;
}
