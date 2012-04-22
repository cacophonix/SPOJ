/*
USER: zobayer
TASK: HACKRNDM
ALGO: binary search
*/

#include <cstdio>
#include <map>
using namespace std;

map< int, int > M;
map< int, int > :: iterator it, p;

int main() {
	int n, k, ans = 0, i, v;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++) {
		scanf("%d", &v);
		M[v]++;
	}
	for(it = M.begin(); it != M.end(); it++) {
		p = M.find(it->first + k);
		if(p != M.end()) ans += p->second;
	}
	printf("%d\n", ans);
	return 0;
}