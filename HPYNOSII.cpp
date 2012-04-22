/*
USER: zobayer
TASK: HPYNOSII
ALGO: pre-calculation
*/

#include <cstdio>
using namespace std;

int happy[111] = {
  1,  7, 10, 13, 19, 23, 28, 31, 32, 44, 49, 68, 70, 79, 82, 86, 91, 94, 97,100,103,109,129,130,133,139,167,176,188,190,192,193,203,208,219,226,230,
236,239,262,263,280,291,293,301,302,310,313,319,320,326,329,331,338,356,362,365,367,368,376,379,383,386,391,392,397,404,409,440,446,464,469,478,487,
490,496,536,556,563,565,566,608,617,622,623,632,635,637,638,644,649,653,655,656,665,671,673,680,683,694,700,709,716,736,739,748,761,763,784,790,793
};

int cycle[800], curr;

inline int next(int n) {
	int ret = 0, m;
	while(n) {
		m = n % 10;
		n /= 10;
		ret += m * m;
	}
	return ret;
}

void fill(int n) {
	if(n==1) {
		curr = 0;
		return;
	}
	if(cycle[n]) {
		curr = cycle[n];
		return;
	}
	fill(next(n));
	cycle[n] = ++curr;
}

void calc() {
	for(int i = 110; i; i--) {
		if(!cycle[happy[i]]) {
			fill(happy[i]);
		}
	}
}

static char buff[12960000], *ptr = buff;

inline int nextInt() {
	int ret = 0;
	while(*ptr < '0' || *ptr > '9') ptr++;
	do { ret = ret * 10 + *ptr++ - '0';
	} while(*ptr >= '0' && *ptr <= '9');
	return ret;
}


int main() {
	calc();
	fread_unlocked(buff, 12960000, 1, stdin);
	int n, t = nextInt(), s, f;
	while(t--) {
		n = nextInt();
		f = (n > happy[110]);
		if(f) s = next(n);
		else s = n;
		if(!cycle[s]) printf("-1\n");
		else printf("%d\n", cycle[s] + f);
	}
	return 0;
}
