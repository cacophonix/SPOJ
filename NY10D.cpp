/*
USER: zobayer
TASL: NY10D
ALGO: simulation
*/

#include <cstdio>
using namespace std;

int buff[1048576];

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
	int test, cs, ebytes, i, cnt, chr, msb = 0x80, len;
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d", &cs, &ebytes);
		for(i = len = 0; i < ebytes;) {
			cnt = getbyte(); i++;
			if(cnt & msb) {
				cnt &= (msb-1);
				cnt += 3;
				chr = getbyte(); i++;
				while(cnt--) {
					buff[len++] = chr;
				}
			}
			else {
				cnt += 1;
				while(cnt--) {
					buff[len++] = getbyte();
					i++;
				}
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