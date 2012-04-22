/*
USER: zobayer
TASK: EMOTICON
ALGO: knuth morris patt
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair< int, int > pii;

char emoticon[101][20], line[101];
int failure[101][20], len[101];
vector< pii > interval;

void computeOverlap(int *overlap, char *pattern, int &i) {
	overlap[0] = -1;
	for(i=0; pattern[i]; i++) {
		overlap[i+1] = overlap[i] + 1;
		while(overlap[i+1]>0 && pattern[i] != pattern[overlap[i+1]-1]) {
			overlap[i+1] = overlap[overlap[i+1]-1] + 1;
		}
	}
}

void kmpMatcher(char *ch, char *pattern, int *overlap, int m) {
	int i, j;
	for(i=j=0; ch[i]; i++) {
		while(true) {
			if(ch[i]==pattern[j]) {
				j++;
				if(j==m) {
					interval.push_back(pii(i-m+1, i));
					j = overlap[j];
				}
				break;
			}
			else if(!j) break;
			else j = overlap[j];
		}
	}
}

bool comp(pii a, pii b) {
	return a.second < b.second;
}

int main() {
	int n, m, i, j, sz, last, total;
	while(scanf("%d%d", &n, &m)==2 && m && n) {
		gets(line);
		for(i=0; i<n; i++) {
			gets(emoticon[i]);
			memset(failure[i], 0, sizeof failure[i]);
			computeOverlap(failure[i], emoticon[i], len[i]);
		}
		total = 0;
		for(i=0; i<m; i++) {
			gets(line);
			interval.clear();
			for(j=0; j<n; j++) {
				kmpMatcher(line, emoticon[j], failure[j], len[j]);
			}
			sort(interval.begin(), interval.end(), comp);
			sz = interval.size();
			last = -1;
			for(j=0; j<sz; j++) {
				if(interval[j].first > last) {
					total++;
					last = interval[j].second;
				}
			}
		}
		printf("%d\n", total);
	}
	return 0;
}
