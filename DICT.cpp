/*
USER: zobayer
TASK: DICT
ALGO: trie
*/

#include <cstdio>
#include <cstring>

struct Node {
	int next[27];
};

Node trie[200000];
int tail, root, qlen, printed;
char buff[32];

void insert(char *s) {
	int i, k, curr = root;
	for(i = 0; s[i]; i++) {
		k = s[i] - 'a';
		if(trie[curr].next[k] == -1) {
			trie[curr].next[k] = tail;
			memset(trie[tail].next, -1, sizeof(int)*27);
			tail++;
		}
		curr = trie[curr].next[k];
	}
	trie[curr].next[26] = 0;
}

int find(char *s) {
	int i, k, curr = root;
	for(i = 0; s[i]; i++) {
		k = s[i] - 'a';
		if(trie[curr].next[k] == -1) return -1;
		curr = trie[curr].next[k];
	}
	return curr;
}

void print(int curr, int len) {
	if(trie[curr].next[26] == 0 && len > qlen) {
		buff[len] = 0;
		puts(buff);
		printed++;
	}
	for(int i = 0; i < 26; i++) {
		if(trie[curr].next[i] != -1) {
			buff[len] = i + 'a';
			print(trie[curr].next[i], len + 1);
		}
	}
}

int main() {
	int n, i, cs, test, ret;
	char word[32];
	root = 0, tail = 1;
	memset(trie[root].next, -1, sizeof(int)*27);
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%s", word);
		insert(word);
	}
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%s", word);
		printf("Case #%d:\n", cs);
		ret = find(word);
		if(ret == -1) printf("No match.\n");
		else {
			strcpy(buff, word); printed = 0;
			print(ret, qlen = strlen(word));
			if(!printed) printf("No match.\n");
		}
	}
	return 0;
}