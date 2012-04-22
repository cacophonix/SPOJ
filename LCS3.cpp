/*
USER: zobayer
TASK: LCS3
ALGO: binary search
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 10001;

int *N[MAX];
int cnt[MAX], deg[MAX];
int *buff;
int a[5], best[5], nbest, temp[5], ntemp;
char charbuff[0x800000], *ptr;

#define nextint(x) while(*ptr<48)ptr++;x=0;do{x=x*10+*ptr++-48;}while(*ptr>47)

inline int upperbound(int *a, int first, int last, int val) {
	int it, cnt, stp;
	cnt = last - first;
	while(cnt > 0) {
		stp = cnt >> 1, it = first + stp;
		if(val >= a[it]) first = ++it, cnt -= stp+1;
		else cnt = stp;
	}
	return first;
}

int main() {
	int n, i, j, v, q, m, last, batil, it;
	fread_unlocked(charbuff, 1, 0x800000, stdin); ptr = charbuff;
	nextint(n);
	buff = new int[n];
	for(i = 0, last = -1; i < n; i++) {
		nextint(buff[i]);
		last = buff[i] > last? buff[i] : last;
		cnt[buff[i]]++;
	}
	for(i = 0; i <= last; i++) if(cnt[i]) N[i] = new int[cnt[i]];
	for(i = 0; i < n; i++) N[buff[i]][deg[buff[i]]++] = i;
	nextint(q);
	while(q--) {
		nextint(m);
		for(i = 0; i < m; i++) {nextint(a[i]);}
		nbest = 0;
		for(i = 1; i < (1<<m); i++) {
			last = -1; batil = ntemp = 0;
			for(j = 0; j < m; j++) {
				if(i & (1<<j)) {
					it = upperbound(N[a[j]], 0, cnt[a[j]], last);
					if(it == cnt[a[j]]) {
						batil = 1;
						break;
					}
					temp[ntemp++] = a[j];
					last = N[a[j]][it];
				}
			}
			if(!batil) {
				if(ntemp > nbest) {
					nbest = ntemp;
					memcpy(best, temp, sizeof(int)*ntemp);
				}
				else if(ntemp == nbest) {
					for(j = 0; j < nbest && temp[j] == best[j]; j++);
					if(j < nbest && temp[j] < best[j]) memcpy(best, temp, sizeof(int)*ntemp);
				}
			}
		}
		printf("%d", nbest);
		for(i = 0; i < nbest; i++) printf(" %d", best[i]); printf("\n");
	}
	return 0;
}
