/*
USER: zobayer
TASK: LCS2
ALGO: suffix automaton
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

const int ALPH = 26;
const int MAX = 1 << 17;
const int INF = 0x7f7f7f7f;

typedef struct {
	int pos, len, link, v, w, next[ALPH];
} State;

typedef struct {
	int len, idx;
} Data;

char s[10][MAX];
int b[MAX << 1], n1, cnt, last;
State st[MAX << 1];
Data a[MAX << 1];

inline int max(const int &a, const int &b) { return a > b ? a : b; }
inline int min(const int &a, const int &b) { return a < b ? a : b; }
inline void setmax(int &a, const int &b) { if(a < b) a = b; }
inline void setmin(int &a, const int &b) { if(a > b) a = b; }
inline bool comp(const Data &p, const Data &q) { return (p.len == q.len)? p.idx > q.idx : p.len > q.len; }


void extend(int pos, char ch) {
	int nlast = cnt++, p, q;
	st[nlast].len = st[last].len + 1, st[nlast].pos = pos, st[nlast].w = INF;
	memset(st[nlast].next, -1, sizeof(int)*ALPH);
	for(p = last; p != -1 && st[p].next[ch] == -1; p = st[p].link) st[p].next[ch] = nlast;
	if(p == -1) st[nlast].link = 0;
	else {
		q = st[p].next[ch];
		if(st[p].len + 1 == st[q].len) st[nlast].link = q;
		else {
			st[cnt].len = st[p].len + 1;
			memcpy(st[cnt].next, st[q].next, sizeof(int)*ALPH);
			st[cnt].link = st[q].link, st[cnt].pos = -1, st[cnt].w = INF;
			for(; p != -1 && st[p].next[ch] == q; p = st[p].link) st[p].next[ch] = cnt;
			st[q].link = st[nlast].link = cnt; cnt++;
		}
	}
	last = nlast;
}

void buildDFA(int n, char *ss) {
	st[0].link = st[0].pos = -1, st[0].w = INF, cnt = 1, last = 0;
	memset(st[0].next, -1, sizeof(int)*ALPH);
	for(int i = 0; i < n; i++) extend(i, ss[i] - 'a');
}

void lcs(char *ss, int n2) {
	int p = 0, len = 0, i, cur;
	for(i = 0; i < n2; i++) {
		cur = ss[i] - 'a';
		if(st[p].next[cur] == -1) {
			for(; p != -1 && st[p].next[cur] == -1; p = st[p].link);
			if(p == -1) { p = len = 0; continue; }
			len = st[p].len;
		}
		len++; p = st[p].next[cur];
		setmax(st[p].v, len);
	}
	for(i = 0; i < cnt; i++) {
		if(!b[i]) continue;
		setmax(st[st[b[i]].link].v, st[b[i]].v);
	}
	for(i = 0; i < cnt; i++) {
		setmin(st[i].w, st[i].v);
		st[i].v = 0;
	}
}

int main() {
	int i, k = 0, m = 0, res = 0, len[10];
	while(fgets(s[k], MAX, stdin)) {
		len[k] = strlen(s[k])-1;
		if(len[k] < len[m]) m = k;
		k++;
	}
	buildDFA(len[m], s[m]);
	n1 = len[m];
	for(i = 0; i < cnt; i++) a[i].len = st[i].len, a[i].idx = i;
	std::sort(a, a + cnt, comp);
	for(i = 0; i < cnt; i++) b[i] = a[i].idx;
	for(i = 0; i < k; i++) if(i != m) lcs(s[i], len[i]);
	for(i = 0; i < cnt; i++) setmax(res, min(st[i].len, st[i].w));
	printf("%d\n", res);
	return 0;
}
