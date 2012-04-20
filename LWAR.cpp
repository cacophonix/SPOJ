/*
USER: zobayer
TASK: LWAR
ALGO: simulation
*/

#include <cstdio>
#include <cctype>
using namespace std;

const int MAX = 30003;
char str[MAX];

void readStr(char *s, int &len) {
	char ch;
	while(!isdigit(ch=getchar()));
	s[(len=0)++] = ch;
	while(isdigit(ch=getchar())) s[len++] = ch;
	s[len] = 0;
}

int main() {
	int t, len, i, invc, done, next, ch;
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	while(t--) {
		readStr(str, len);
		done = invc = next = 0;
		for(i=0; i<len; i++) {
			ch = str[i];
			if(invc&1) ch = '1'-ch+'0';
			if(next) {
				if(ch=='0') {
					ch = '1';
				}
				else {
					ch = '0';
					invc++;
					done = 1;
				}
				next = 0;
			}
			else if(!done) {
				if(ch=='0') done = 1;
				else next = 1;
			}
			putchar(ch);
		}
		putchar('\n');
	}
	return 0;
}
