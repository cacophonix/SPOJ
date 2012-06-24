/*
USER: zobayer
TASK: TWINSNOW
ALGO: hashing
*/

#include <ios>
#include <algorithm>
using namespace std;

#define MAX 100001
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(i,n) for(int i=0;i<n;i++)

struct TWINSNOW {
	int f[6], idx;
};

TWINSNOW orig[MAX], sorted[MAX];

bool comp(TWINSNOW a, TWINSNOW b) {
	REP(i,6)
		if(a.f[i] < b.f[i]) return true;
		else if(a.f[i] > b.f[i]) return false;
	return true;
}

bool isEqualSorted(TWINSNOW a, TWINSNOW b) {
	REP(i,6) if(a.f[i]!=b.f[i]) return false;
	return true;
}

bool isEqualOrig(TWINSNOW a, TWINSNOW b) {
	bool ret;
	// check forward
	REP(p,6) {
		ret = 1;
		REP(i,6) {
			if(a.f[i]!=b.f[(i+p)%6]) {
				ret = 0;
				break;
			}
		}
		if(ret) return ret;
	}
	// check backword
	REP(p,6) {
		ret = 1;
		REP(i,6) {
			if(a.f[i]!=b.f[(6-i+p)%6]) {
				ret = 0;
				break;
			}
		}
		if(ret) return ret;
	}
	return false;
}

bool match(int N) {
	int i = 0, j;
	while(i < N-1) {
		j = i+1;
		while(j < N && isEqualSorted(sorted[i], sorted[j])) j++;
		FOR(m,i,j-2)
			FOR(n,m+1,j-1)
				if(isEqualOrig(orig[sorted[m].idx],orig[sorted[n].idx]))
					return true;
		i = j;
	}
	return false;
}

int main() {
	int N, a;

	scanf("%d", &N);

	REP(i,N) {
		REP(j,6) {
			scanf("%d", &a);
			orig[i].f[j] = sorted[i].f[j] = a;
			orig[i].idx = sorted[i].idx = i;
		}
		sort(sorted[i].f, sorted[i].f + 6);
	}
	sort(sorted, sorted + N, comp);
	
	if(match(N)) printf("Twin snowflakes found.\n");
	else printf("No two snowflakes are alike.\n");

	return 0;
}
