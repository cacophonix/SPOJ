/*
USER: zobayer
TASK: EPALIN
ALGO: manachar
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100001;

char buff[MAX << 1];
int lengths[MAX << 1];

int main() {
	int len, i, s, e, pallen, found, j, d, total, k;
	while(gets(buff)) {
		len = strlen(buff);
		k = 0;
		pallen = 0;
		for(i = 0; i < len; ) {
			if(i > pallen && buff[i-pallen-1] == buff[i]) {
				pallen += 2, i++;
				continue;
			}
			lengths[k++] = pallen;
			s = k - 2, e = s - pallen, found = 0;
			for(j = s; j > e; j--) {
				d = j - e - 1;
				if(lengths[j] == d) {
					pallen = d;
					found = 1;
					break;
				}
				lengths[k++] = (d < lengths[j]? d : lengths[j]);
			}
			if(!found) { pallen = 1; i++; }
		}
		lengths[k++] = pallen;
		total = (len << 1) - lengths[k-1];
		strncpy(buff + len, buff, total - len); buff[total] = 0;
		reverse(buff + len, buff + total);
		puts(buff);
	}
	return 0;
}
