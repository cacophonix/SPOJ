/*
USER: zobayer
TASK: PRO
ALGO: simulation
*/

#include <set>
#include <ios>
using namespace std;

#define i64 long long
#define FS "%lld\n"

multiset< int > S;
multiset< int > :: iterator fwd, rev;

int main() {
	i64 sum = 0;
	int n, i, j, p,m;
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%d", &m);
		for(j=0; j<m; j++) {
			scanf("%d", &p);
			S.insert(p);
		}
		fwd = S.begin();
		rev = S.end(); rev--;
		sum += (*rev - *fwd);
		S.erase(fwd);
		S.erase(rev);
	}
	printf(FS, sum);
	return 0;
}
