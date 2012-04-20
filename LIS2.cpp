/*
USER: zobayer
TASK: LIS2
ALGO: binary search
*/

#include <ios>
#include <set>
using namespace std;

typedef pair< int, int > pii;

const int MAX = 100001;
set< pii > S[MAX];

bool comp(set< pii > &s, pii &p) {
	set< pii >::iterator it;
	for(it=s.begin(); it!=s.end(); it++) {
		if(it->first < p.first && it->second < p.second) return true;
		if(it->first >= p.first) return false;
	}
	return false;
}

int find_pos(int start, int end, pii val) {
	int cnt = end - start, idx, stp;
	while(cnt > 0) {
		idx = start, stp = cnt>>1, idx += stp;
		if(comp(S[idx], val)) start = ++idx, cnt -= ++stp;
		else cnt = stp;
	}
	return start;
}

int main() {
	int x, y, n, pos, i, cnt;
	pii p;
	set< pii >::iterator it, pr;
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%d%d", &x, &y);
		p = pii(x, y);
		pos = find_pos(0, n, p);
		if(pos < n) {
			S[pos].insert(p);
			it = S[pos].find(p);
			it++;
			while(it!=S[pos].end()) {
				if(it->first > p.first && it->second > p.second) {
					pr = ++it; --it;
					S[pos].erase(it);
					it = pr;
				}
				else it++;
			}
		}
	}
	for(i=cnt=0; i<n; i++) {
		if(S[i].empty()) break;
		else cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
