/*
USER: zobayer
TASK: SAM
ALGO: priority queue
*/

#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

typedef pair< int, int > pii;

const int MAX = 500005;

int a[MAX], next[MAX], last[MAX];
bool flag[MAX];
priority_queue< pii > Q;

int main() {
	int n, p, k, test, i, moves, cnt;
	pii top;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d %d", &n, &k, &p);
		for(i = 0; i < p; i++) {
			scanf("%d", a + i);
			a[i]--;
		}
		for(i = 0; i < n; i++) {
			last[i] = p;
			flag[i] = false;
		}
		for(i = p - 1; i >= 0; i--) {
			next[i] = last[a[i]];
			last[a[i]] = i;
		}
		while(!Q.empty()) Q.pop();
		for(cnt = moves = i = 0; i < p; i++) {
			if(flag[a[i]]) {
				Q.push(pii(next[i], a[i]));
				continue;
			}
			if(cnt < k) {
				moves++; cnt++;
				flag[a[i]] = true;
				Q.push(pii(next[i], a[i]));
			}
			else {
				top = Q.top(); Q.pop();
				flag[top.second] = false;
				moves++;
				flag[a[i]] = true;
				Q.push(pii(next[i], a[i]));
			}
		}
		printf("%d\n", moves);
	}
	return 0;
}

