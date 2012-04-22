/*
USER: zobayer
TASK: UPSUB
ALGO: dynamic programming
*/

#include <stdio.h>
#include <string.h>

const int MAX = 111;
char str[MAX], word[MAX];
int slen, maxlen, order[MAX], curr[MAX];

void lis() {
	int rev[MAX], i, j;
	slen = strlen(str);
	rev[slen-1] = 1;
	maxlen = 1;
	for(i=slen-2; i>=0; i--) {
		rev[i] = 1;
		for(j=i+1; j<slen; j++) {
			if(str[j]>=str[i]) {
				if(rev[j]+1 > rev[i]) {
					rev[i] = rev[j] + 1;
				}
			}
		}
		if(rev[i] > maxlen) maxlen = rev[i];
	}
	order[0] = 1;
	for(i=1; i<slen; i++) {
		order[i] = 1;
		for(j=0; j<i; j++) {
			if(str[j] <= str[i]) {
				if(order[j]+1 > order[i]) {
					order[i] = order[j] + 1;
				}
			}
		}
	}
	for(i=0; i<slen; i++) {
		if(order[i] + rev[i] <= maxlen) {
			order[i] = 0;
		}
	}
}

void print(int n) {
	int i;
	if(n > maxlen) {
		puts(word);
		return;
	}
	for(i=slen-1; i>curr[n-1]; i--) {
		if(order[i]==n) {
			if(n>1 && str[i]<word[n-2]) continue;
			curr[n] = i;
			word[n-1] = str[i];
			print(n+1);
		}
	}
}

int main() {
	int cases;
	scanf("%d", &cases);
	while(cases--) {
		scanf("%s", str);
		lis();
		word[maxlen] = 0;
		curr[0] = -1;
		print(1);
	}
	return 0;
}
