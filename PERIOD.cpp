/*
USER: zobayer
TASK: PERIOD
ALGO: knuth morris patt
*/

#include <cstdio>
using namespace std;

char *buff;
int *over;

int main() {
	int t, x = 1, len, i, j;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &len);
		buff = new char[len+10];
		over = new int[len+10];
		scanf("%s", buff);
		printf("Test case #%d\n", x++);
		over[0] = over[1] = 0;
		for(i=2; i<=len; i++) {
			j = over[i-1];
			while(true) {
				if(buff[j]==buff[i-1]) {
					over[i] = j + 1;
					break;
				}
				else if(!j) {
					over[i] = j;
					break;
				}
				else j = over[j]; 
			}
			if(over[i] && i%(i-over[i])==0) {
				printf("%d %d\n", i, i/(i-over[i]));
			}
		}
		printf("\n");
		delete[] buff;
		delete[] over;
	}
	return 0;
}
