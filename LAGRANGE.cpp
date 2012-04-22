/*
USER: zobayer
TASK: LAGRANGE
ALGO: pre-calculation
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int MAX = 1 << 15;
char buff[4096], *p;
int sqr[192], ways[1<<15];

int main() {
	int n, i, j, k, l;
	for(i = 0; i < 192; i++) sqr[i] = i*i;
	for(i = 0; 4*sqr[i] < MAX; i++)
		for(j = i; sqr[i]+3*sqr[j] < MAX; j++)
			for(k = j; sqr[i]+sqr[j]+2*sqr[k] < MAX; k++)
				for(l = k; sqr[i]+sqr[j]+sqr[k]+sqr[l] < MAX; l++)
					ways[sqr[i]+sqr[j]+sqr[k]+sqr[l]]++;
	/*fread_unlocked(buff, 4096, 1, stdin);
	p = strtok(buff,"\n");
	while(p && (n=atoi(p))) {
		printf("%d\n", ways[n]);
		p = strtok(0, "\n");
	}*/
	while(fgets(buff, 8, stdin)) {
		n = atoi(buff);
		if(!n) break;
		printf("%d\n", ways[n]);
	}
	return 0;
}
