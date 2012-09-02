/*
USER: zobayer
TASK: LAZYPROG
ALGO: priority Que
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <utility>
using namespace std;

#define mt(A, B, C) make_pair(A, make_pair(B, C))

typedef pair <int, int> pii;
typedef pair <int, pii> pi3;
typedef pair <int, double> pid;

int main() {
	int num, test;
	scanf("%d", &test);
	while(test--) {
		scanf("%d", &num);
		vector <pi3> vec;
		for(int i = 0; i < num; i++) {
			int za, zb, zc;
			scanf("%d %d %d", &za, &zb, &zc);
			vec.push_back(mt(zc, za, zb));
		}
		sort(vec.begin(), vec.end());
		priority_queue <pii> Q;
		double ret = 0;
		int tim = 0;
		for(int i = 0; i < num; i++) {
			tim += vec[i].second.second;
			Q.push(make_pair(vec[i].second.first, vec[i].second.second));
			if(tim > vec[i].first) {
				for(;;) {
					pii tmp = Q.top();
					Q.pop();
					if(tim - tmp.second <= vec[i].first) {
						tmp.second -= tim - vec[i].first;
						ret += double(tim - vec[i].first) / double(tmp.first);
						tim = vec[i].first;
						Q.push(tmp);
						break;
					}
					else {
						ret += double(tmp.second) / double(tmp.first);
						tim -= tmp.second;
					}
				}
			}
		}
		printf("%.2lf\n", ret);
	}
	return 0;
}
