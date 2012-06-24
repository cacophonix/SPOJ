/*
USER: zobayer
TASK: PHONELST
ALGO: prefix tree, trie
*/

#include <stdio.h>

#define IOR(x) freopen(x,"r",stdin);

struct trie {
	trie *next[10];
	bool end;
	trie() {
		for(int i=0; i<10; i++) next[i] = NULL;
		end = 0;
	}
};

int main() {
	int t, n, i, p;
	char str[15];
	bool flag;
	//IOR("in.txt");
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		trie *head, *tail;
		head = new trie;
		flag = 1;
		while(n--) {
			scanf("%s", str);
			if(flag) {
				tail = head;
				for(i=0; str[i]; i++) {
					if(tail->end) {
						flag = 0;
						break;
					}
					p = str[i]-'0';
					if(tail->next[p]==NULL) tail->next[p] = new trie;
					tail = tail->next[p];
				}
				tail->end = 1;
				for(i=0; i<10; i++) {
					if(tail->next[i]) {
						flag = 0;
						break;
					}
				}
			}
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
