/*
USER: zobayer
TASK: EXPRESS
ALGO: breadth first search
*/

#include <cstdio>
#include <cctype>
#include <cstdlib>
using namespace std;

struct Node { int r, l; };

const int MAXLEN = 10001;
char post[MAXLEN], res[MAXLEN];
Node tree[MAXLEN];
int Q[MAXLEN], S[MAXLEN];

int main() {
	int t, i, st, en, tp, a, b;
	t = atoi(gets(post));
	while(t--) {
		gets(post);
		st = en = tp = 0;
		for(i = 0; post[i]; i++) {
			if(islower(post[i])) {
				tree[i].l = tree[i].r = -1;
				S[tp++] = i;
			}
			else {
				tree[i].r = S[--tp];
				tree[i].l = S[--tp];
				S[tp++] = i;
			}
		}
		res[i] = 0;
		Q[en++] = S[--tp];
		while(st < en) {
			a = Q[st++];
			res[--i] = post[a];
			if(tree[a].l > -1) Q[en++] = tree[a].l;
			if(tree[a].r > -1) Q[en++] = tree[a].r;
		}
		puts(res);
	}
	return 0;
}
