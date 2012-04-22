/*
USER: zobayer
TASK: HMRO
ALGO: topological sort
*/

#include <cstdio>
#include <cstring>
#include <queue>
#include <list>
using namespace std;

typedef long long i64;
const int HASHMOD = 123457, MAX = 222222, HASHMUL = 153637;

struct HashItem {
	i64 key;
	int val, next;
	HashItem() {}
	HashItem(i64 k, int v, int n) : key(k), val(v), next(n) {}
};

struct Node {
	int indeg, firstEdge;
	Node() {}
	Node(int i, int f) : indeg(i), firstEdge(f) {}
};

struct Edge {
	int to, nextEdge;
	Edge() {}
	Edge(int t, int n) : to(t), nextEdge(n) {}
};

Node node[MAX];
Edge edge[MAX>>1];
HashItem hashItem[HASHMOD];
int edges, hashCnt, firstHash[HASHMOD], redir[MAX];

inline int getHash(i64 n) {
	n *= HASHMUL;
	n %= HASHMOD;
	return (int)n;
}

inline void init() {
	memset(firstHash, 0, sizeof(firstHash));
	hashCnt = 0;
}

inline void add(i64 key, int val) {
	int h = getHash(key);
	hashItem[++hashCnt] = HashItem(key, val, firstHash[h]);
	firstHash[h] = hashCnt;
}

inline int find(i64 key) {
	int h = getHash(key), e;
	for(e = firstHash[h]; e; e = hashItem[e].next)
		if(hashItem[e].key==key)
			return hashItem[e].val;
	return -1;
}

void topoSort() {
	int from, to, e;
	queue< int > Q;
	list< int > L;
	list< int > :: iterator i;
	for(from = 0; from < MAX; from++) node[from] = Node(0, -1);
	edges = 0;
	for(to = 0; to < MAX; to++) {
		if((from = redir[to]) != to) {
			edge[edges] = Edge(to, node[from].firstEdge);
			node[from].firstEdge = edges++;
			node[to].indeg++;
		}
	}
	for(from = 0; from < MAX; from++)
		if(!node[from].indeg && node[from].firstEdge >= 0)
			Q.push(from);
	while(!Q.empty()) {
		from = Q.front(); Q.pop();
		L.push_back(from);
		for(e = node[from].firstEdge; e >= 0; e = edge[e].nextEdge) Q.push(edge[e].to);
	}
	for(i = L.begin(); i != L.end(); i++) redir[*i] = redir[redir[*i]];
}

int main() {
	int t, boys, redirs, queries, m;
	char mro[8];
	i64 psel;
	scanf("%d", &t);
	while(t--) {
		init();
		scanf("%d", &boys);
		while(boys--) {
			scanf("%lld %s", &psel, mro);
			m = mro[3]-'0' + 10*(mro[2]-'A' + 26*(mro[1]-'A' + 26*(mro[0]-'A')));
			add(psel, m);
		}
		for(m = 0; m < MAX; m++) redir[m] = m;
		scanf("%d", &redirs);
		while(redirs--) {
			scanf("%s", mro);
			m = mro[3]-'0' + 10*(mro[2]-'A' + 26*(mro[1]-'A' + 26*(mro[0]-'A')));
			scanf("%s", mro);
			redir[m] = mro[3]-'0' + 10*(mro[2]-'A' + 26*(mro[1]-'A' + 26*(mro[0]-'A')));
		}
		topoSort();
		scanf("%d", &queries);
		while(queries--) {
			scanf("%lld", &psel);
			m = redir[find(psel)];
			mro[4] = 0;
			mro[3] = m % 10 + '0'; m /= 10;
			mro[2] = m % 26 + 'A'; m /= 26;
			mro[1] = m % 26 + 'A'; m /= 26;
			mro[0] = m + 'A';
			printf("%011lld %s\n", psel, mro);
		}
		if(t) printf("\n");
	}
	return 0;
}
