/*
USER: zobayer
TASK: INUMBER
ALGO: breadth first search
*/

#include <cstdio>
using namespace std;

int vis[1001][1000], cs = 1, st, en;
unsigned pre[1001][1000], Q[1001001];
char num[128];

#define MOD(n,m) (n<m?n:n%m)

inline void readBits(unsigned bits, int &s, int &m, int &i) {
	i = 0xff & bits; bits >>= 8;
	m = 0xfff & bits; if(m==0xfff) m = -1; bits >>= 12;
	s = 0xfff & bits; if(s==0xfff) s = -1;
}

inline unsigned makeBits(int s, int m, int i) {
	return (unsigned)((((s << 12) | m) << 8) | i);
}

unsigned bfs(int n) {
	int i, m, s, s2, m2;
	unsigned u, v;
	st = en = 0;
	for(i = 1; i < 10; i++) {
		m = MOD(i, n);
		vis[i][m] = cs;
		pre[i][m] = 0;
		u = makeBits(i, m, i);
		Q[en++] = u;
	}
	while(st < en) {
		u = Q[st++];
		readBits(u, s, m, i);
		for(i = 0; i < 10; i++) {
			s2 = s + i;
			if(s2 > n) break;
			m2 = MOD((m*10 + i),n);
			if(vis[s2][m2] != cs) {
				vis[s2][m2] = cs;
				v = makeBits(s2, m2, i);
				pre[s2][m2] = u;
				if(s2 == n && m2 == 0) return v;
				Q[en++] = v;
			}
		}
	}
	return 0;
}

int main() {
	int test, n, s, m, d, len, i, j, k;
	unsigned u;
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &n);
		if(n < 10) {
			printf("%d\n", n);
			continue;
		}
		u = bfs(n);
		for(len = 0; ; u = pre[s][m]) {
			readBits(u, s, m, d);
			if(!s) break;
			num[len++] = d + '0';
		}
		for(i = 0, j = len-1; i < j; i++, j--) {
			k = num[i], num[i] = num[j], num[j] = k;
		}
		num[len] = 0; puts(num); cs++;
	}
	return 0;
}
