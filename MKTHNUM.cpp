/*
USER: zobayer
TASK: MKTHNUM
ALGO: segment T, merge sort
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int NMAX = 100001;
const int DEPTH = 18;

typedef struct { int lt,rt; } Node;

Node T[1 << 18];
int a[NMAX], seg[DEPTH][NMAX], lesser[DEPTH][NMAX];

void buildtree(int node, int lt, int rt, int d) {
	T[node].lt = lt,T[node].rt = rt;
	if(lt == rt) return;
	int i, mid = (lt + rt) >> 1, lsame = mid - lt + 1, tl = lt, tr = mid + 1, same = 0;
	for(i = lt; i <= rt; i++) if(seg[d][i] < a[mid]) lsame--;
	for(i = lt; i <= rt; i++) {
		if(i == lt) lesser[d][i] = 0;
		else lesser[d][i] = lesser[d][i - 1];
		if(seg[d][i] < a[mid]) lesser[d][i]++, seg[d+1][tl++] = seg[d][i];
		else if(seg[d][i] > a[mid]) seg[d+1][tr++] = seg[d][i];
		else {
			if(same < lsame) same++, lesser[d][i]++, seg[d+1][tl++] = seg[d][i];
			else seg[d+1][tr++] = seg[d][i];
		}
	}
	buildtree(node << 1, lt, mid, d + 1);
	buildtree((node << 1) + 1, mid + 1, rt, d + 1);
}

int Query(int node, int lt, int rt, int d, int cnt) {
	if(lt == rt) return seg[d][lt];
	int s, ss, mid;
	if(lt == T[node].lt) s = lesser[d][rt], ss = 0;
	else s = lesser[d][rt] - lesser[d][lt - 1], ss = lesser[d][lt - 1];
	if(s >= cnt) return Query(node << 1, T[node].lt + ss, T[node].lt + ss + s - 1, d + 1, cnt);
	else {
		mid = (T[node].lt + T[node].rt) >> 1, bb = lt - T[node].lt - ss, b = rt - lt + 1 - s;
		return Query((node << 1)+1, mid + bb + 1, mid + bb + b, d + 1, cnt - s);
	}
}

int main() {
	int i, n, m, lt, rt, k;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		seg[1][i] = a[i];
	}
	sort(a + 1, a + 1 + n);
	buildtree(1, 1, n, 1);
	while(m--) {
        scanf("%d %d %d", &lt, &rt, &k);
        printf("%d\n", Query(1, lt, rt, 1, k));
    }
    return 0;
}
