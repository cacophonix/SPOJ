/*
USER: zobayer
TASK: JMFILTER
ALGO: disjoint set
*/

#include <cstdio>
#include <set>
using namespace std;

const int MAX = 11000000;

int root[MAX], fmap[MAX];
set< int > S;

int find(int p) {
	if(p != root[p]) root[p] = find(root[p]);
	return root[p];
}

int main() {
	//freopen("in.txt", "r", stdin);
	int n, m, i, last, a, b, pa, pb, cs = 1;
	char com[2];
	while(scanf("%d %d", &n, &m) == 2 && (n | m)) {
		for(i = 0; i < n; i++) root[i] = fmap[i] = i;
		for(last = n, i = 0; i < m; i++) {
			scanf("%s", com);
			if(com[0] == 'M') {
				scanf("%d %d", &a, &b);
				pa = find(fmap[a]);
				pb = find(fmap[b]);
				if(pa != pb) root[pa] = root[pb];
			}
			else {
				scanf("%d", &a);
				fmap[a] = root[last] = last;
				last++;
			}
		}
		S.clear();
		for(i = 0; i < n; i++) S.insert(find(fmap[i]));
		printf("Case #%d: %d\n", cs++, (int)S.size());
	}
	return 0;
}
