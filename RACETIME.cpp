/*
USER: zobayer
TASK: RACETIME
ALGO: sqrt decomposition
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 100000;
const int LEN = 700;

int num[MAX], seg[MAX];

int lowerbound(int *a, int st, int en, int val) {
	int idx, cnt, stp;
	cnt = en - st;
	while(cnt > 0) {
		stp = cnt >> 1; idx = st + stp;
		if(a[idx] < val) st = ++idx, cnt -= stp+1;
		else cnt = stp;
	}
	return st;
}

int upperbound(int *a, int st, int en, int val) {
	int idx, cnt, stp;
	cnt = en - st;
	while(cnt > 0) {
		stp = cnt >> 1; idx = st + stp;
		if(a[idx] <= val) st = ++idx, cnt -= stp+1;
		else cnt = stp;
	}
	return st;
}

void insert(int st, int en, int j, int v, int x) {
	int i = j; seg[j] = num[x] = v;
	for(i = j; i + 1 < en && seg[i] > seg[i + 1]; i++) swap(seg[i], seg[i + 1]);
	for(i = j; i - 1 >= st && seg[i] < seg[i - 1]; i--) swap(seg[i], seg[i - 1]);
}

int main() {
	int n, q, i, j, k, sz, x, y, v, st, en;
	char op[2];
	scanf("%d %d", &n, &q);
	for(i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		seg[i] = num[i];
	}
	for(i = 0; i < n; i++) {
		j = min(i + LEN, n);
		sort(seg + i, seg + j);
		i = j - 1;
	}
	sz = (n + LEN - 1) / LEN;
	while(q--) {
		scanf("%s", op);
		switch(op[0]) {
		case 'C':
			scanf("%d %d %d", &x, &y, &v);
			st = --x / LEN; en = --y / LEN;
			if(st == en) {
				for(i = x, k = 0; i <= y; i++) k += (num[i] <= v);
				printf("%d\n", k);
			}
			else {
				j = min((st + 1)*LEN, n);
				for(i = x, k = 0; i < j; i++) k += (num[i] <= v);
				for(i = en * LEN; i <= y; i++) k += (num[i] <= v);
				for(i = st + 1; i <= en - 1; i++) k += upperbound(seg, i * LEN, min((i+1) * LEN, n), v) - i * LEN;
				printf("%d\n", k);
			}
		break;
		case 'M':
			scanf("%d %d", &x, &v);
			k = --x / LEN;
			j = lowerbound(seg, st = k*LEN, en = min((k+1)*LEN, n), num[x]);
			insert(st, en, j, v, x);
		}
	}
	return 0;
}
