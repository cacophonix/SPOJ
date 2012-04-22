/*
USER: zobayer
TASK: POSTERS
ALGO: binary search tree
*/

#include <set>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 100000001
#define pii pair< int, int >
#define piii pair< pii, int >
#define ff first.first
#define ss first.second
#define MAX 40004

bool flag[MAX];

class comp {
public:
	inline bool operator() (const piii &a, const piii &b) const {
		return a.ff < b.ff && a.ss < b.ss;
	}
};

inline bool inside(const piii &a, int x) {
	return a.ff <= x && x <= a.ss;
}

int main() 
{
	set< piii, comp > S;
	set< piii, comp > :: iterator st, en;
	piii stp, enp;
	int test, n, i, lt, rt, ans;
	scanf("%d", &test);
	while(test--) {
		S.clear();
		S.insert(piii(pii(0,0), 0)), S.insert(piii(pii(INF,INF),0));
		memset(flag, 0, sizeof flag);
		scanf("%d", &n);
		for(i = 1; i <= n; i++) {
			scanf("%d%d", &lt, &rt);
			stp = *(st = S.lower_bound(piii(pii(lt, lt), i)));
			enp = *(en = S.lower_bound(piii(pii(rt, rt), i)));
			S.erase(st, ++en);
			if(inside(stp, lt)) {
				if(lt - stp.ff > 0) S.insert(piii(pii(stp.ff, lt-1), stp.second));
			}
			else {
				if(stp.ff > rt) S.insert(stp);
			}
			if(inside(enp, rt)) {
				if(rt + 1 <= enp.ss) S.insert(piii(pii(rt+1, enp.ss), enp.second));
			}
			else S.insert(enp);
			S.insert(piii(pii(lt, rt), i));
		}
		for(st=S.begin(), ans = 0; st != S.end(); st++) {
			if(st->second) {
				ans += !flag[st->second];
				flag[st->second] = true;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
