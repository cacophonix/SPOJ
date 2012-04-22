/*
USER: zobayer
TASK: NY10C
ALGO: simulation
*/

#include <cstdio>
using namespace std;

int buff[1048576];
int bytes[8192];
int runcnt[8192];

inline int h2d(char ch) {
	if(ch>'9') return ch-'A'+10;
	return ch-'0';
}

inline int getbyte() {
	char ch; int byte = 0;
	do{ch=getchar();}while(ch<'0');
	byte = (byte<<4) | h2d(ch);
	do{ch=getchar();}while(ch<'0');
	byte = (byte<<4) | h2d(ch);
	return byte;
}

int main() {
	int test, cs, ebytes, i, j, k, m, cnt, chr, len, last;
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d", &cs, &ebytes);
		for(i = 0; i < ebytes; i++) {
			bytes[i] = getbyte();
		}
		for(i = len = 0, last = 0; i < ebytes; i++) {
			chr = bytes[i], cnt = 0;
			for(j = i; j < ebytes && cnt < 130; j++) {
				if(bytes[j]==chr) cnt++;
				else break;
			}
			if(cnt >= 3) {
				while(i-last > 0) {
					if(i-last >= 128) {
						buff[len++] = 127;
						for(k = last, m = 0; m < 128; m++) {
							buff[len++] = bytes[k++];
						}
						last = k;
					}
					else {
						buff[len++] = i-last - 1;
						for(k = last; k < i; k++) {
							buff[len++] = bytes[k];
						}
						last = k;
					}
				}
				buff[len++] = cnt - 3; buff[len-1] |= 0x80;
				buff[len++] = chr;
				last = j;
			}
			i = j-1;
		}
		while(i-last > 0) {
			if(i-last >= 128) {
				buff[len++] = 127;
				for(k = last, m = 0; m < 128; m++) {
					buff[len++] = bytes[k++];
				}
				last = k;
			}
			else {
				buff[len++] = i-last - 1;
				for(k = last; k < i; k++) {
					buff[len++] = bytes[k];
				}
				last = k;
			}
		}
		printf("%d %d\n", cs, len);
		for(i = 0; i < len; i++) {
			if(i && i%40==0) printf("\n");
			printf("%02X", buff[i]);
		}
		printf("\n");
	}
	return 0;
}