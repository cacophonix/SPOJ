/*
USER: zobayer
TASK: CLONE
ALGO: trie
*/

#include <cstdio>
#include <algorithm>
using namespace std;

struct trie {
	int cnt;
	trie *next[4];
	trie() {
		next[0]=next[1]=next[2]=next[3]=NULL;
		cnt = 0;
	}
};

const int MAX = 20002, LEN = 22;
trie *ppl[MAX];
char name[LEN];
int total[MAX];

inline int cnv(char ch) {
	switch(ch) {
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
	}
	return -1;
}

trie *insert(trie *curr, char *str, int len) {
	for(int k, i=0; i<len; i++) {
		k = cnv(str[i]);
		if(curr->next[k]==NULL) curr->next[k] = new trie;
		curr = curr->next[k];
	}
	curr->cnt++;
	return curr;
}

bool comp(trie *a, trie *b) {
	return (a->cnt==b->cnt)? a < b : a->cnt < b->cnt;
}

int main() {
	int n, m, i;
	while(scanf("%d%d", &n, &m)==2 && (n+m)) {
		trie *p = NULL, *t = new trie;
		for(i=0; i<n; i++) {
			scanf("%s", name);
			ppl[i] = insert(t, name, m);
			total[i+1] = 0;
		}
		sort(ppl, ppl+n, comp);
		for(i=0; i<n; i++) {
			if(ppl[i]!=p) total[ppl[i]->cnt]++;
			p = ppl[i];
		}
		for(i=1; i<=n; i++) printf("%d\n", total[i]);
	}
	return 0;
}
