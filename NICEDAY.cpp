/*
USER: zobayer
TASK: NICEDAY
ALGO: sweep
*/

#include <algorithm>
#include <set>
#include <vector>
#include <iterator>
#include <cstdio>
using namespace std;

typedef pair< int, int > pii;
typedef pair< int, pii > pip;

vector< pip > scores;
set< pii > coastline;
set< pii >::iterator iter, last;

int main() {
	int t, n, a, b, c, ans;
	scanf("%d", &t);
	while(t--) {
		coastline.clear();
		scanf("%d", &n);
		scores.resize(n);
		for(int i=0; i<n; i++) {
			scanf("%d%d%d", &a, &b, &c);
			scores[i] = pip(a, pii(b, c));
		}
		sort(scores.begin(), scores.end());
		coastline.insert(scores[0].second);
		ans = 1;
		for(int i=1; i<n; i++) {
			b = scores[i].second.first, c = scores[i].second.second;
			iter = coastline.lower_bound(scores[i].second);
			if(iter==coastline.begin() || c < (--iter)->second) {
				ans++;
				coastline.insert(scores[i].second);
				iter = coastline.upper_bound(scores[i].second);
				for(; iter!=coastline.end(); ) {
					if(iter->first > b && iter->second > c) {
						last = ++iter;
						coastline.erase(--iter);
						iter = last;
					}
					else break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
