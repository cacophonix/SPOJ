/*
USER: zobayer
TASK: TRIP
ALGO: dynamic programming
*/

#include <ios>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100;
int dp[MAX][MAX], lcslen, len1, len2;
char s1[MAX], s2[MAX], s3[MAX];

int lcs(int i, int j) {
	int &ret = dp[i][j];
	if(i==len1 || j==len2) return ret = 0;
	if(ret != -1) return ret;
	ret = 0;
	if(s1[i]==s2[j]) ret = 1 + lcs(i+1, j+1);
	else ret = max(lcs(i+1, j), lcs(i, j+1));
	return ret;
}

void printAll(int na, int nb, int d) {
	if(d==lcslen) {
		s3[d] = 0;
		puts(s3);
		return;
	}
	if(na==len1 || nb==len2) return;
	for(char ch='a'; ch<='z'; ch++) {
		bool done = false;
		for(int i=na; i<len1; i++) {
			if(ch==s1[i]) {
				for(int j=nb; j<len2; j++) {
					if(ch==s2[j] && lcs(i, j)==lcslen-d) {
						s3[d] = ch;
						printAll(i+1, j+1, d+1);
						done = true;
						break;
					}
				}
			}
			if(done) break;
		}
	}
}

int main() {
	int t, i, j;
	scanf("%d", &t);
	while(t--) {
		scanf("%s%s", s1, s2);
		len1 = strlen(s1);
		len2 = strlen(s2);
		for(i=0; i<len1; i++)
			for(j=0; j<len2; j++)
				dp[i][j] = -1;
		lcslen = lcs(0, 0);
		printAll(0, 0, 0);
		if(t) puts("");
	}
	return 0;
}
