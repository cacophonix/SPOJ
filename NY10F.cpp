/*
USER: zobayer
TASK: NY10F
ALGO: simulation
*/

#include <cstdio>
using namespace std;

enum {IDLE, INIT, READ, STO, ACK};
int buff[4096];

inline void getstate(int &scl, int &sda) {
	do{scl=getchar();}while(scl<'0');
	do{sda=getchar();}while(sda<'0');
}

int main() {
	int i, test, cs, sample, scl, sda, status, nbytes, nbits, last, data, rdwr;
	scanf("%d", &test);
	while(test--) {
		scanf("%d %d", &cs, &sample);
		for(i = 0; i < sample; i++) {
			getstate(scl, sda); scl-='0'; sda-='0';
			buff[i] = (scl<<1)|sda;
		}
		status = IDLE;
		nbytes = last = 0;
		rdwr = -1;
		for(i = 0; i < sample; i++) {
			if(status==IDLE) {
				if(buff[i]==3) {
					status = INIT;
				}
			}
			else if(status==INIT) {
				if(buff[i]&2) {
					if(!(buff[i]&1)) {
						status = READ;
						nbits = data = 0;
					}
				}
				else status = IDLE;
			}
			else if(status==READ) {
				if(!(buff[i]&2)) status = STO;
				else {
					if(buff[i]==3 && last==0) {
						break;
					}
				}
			}
			else if(status==STO) {
				if(buff[i]&2) {
					nbits++;
					if(!nbytes) data = (data << 1)|(buff[i]&1);
					if(nbits==8) {
						if(!nbytes) {
							data >>= 1;
							rdwr = buff[i]&1;
						}
						status = ACK;
					}
					else status = READ;
				}
			}
			else if(status==ACK) {
				if(buff[i]&2) {
					if(!(buff[i]&1)) {
						status = READ;
						nbytes++;
						nbits = 0;
					}
				}
			}
			last = buff[i]&1;
		}
		if(status==INIT || status==IDLE) printf("%d ERROR NO START BIT\n", cs);
		else if(status==ACK && !nbytes) printf("%d ERROR NO ACK FROM SLAVE %02X\n", cs, data);
		else if(status==ACK) printf("%d ERROR NO ACK FOR DATA\n", cs);
		else if(i==sample) printf("%d ERROR NO STOP BIT\n", cs);
		else if(rdwr==1) printf("%d READ OF %d BYTES FROM SLAVE %02X\n", cs, nbytes-1, data);
		else if(rdwr==0) printf("%d WRITE OF %d BYTES TO SLAVE %02X\n", cs, nbytes-1, data);
	}
	return 0;
}