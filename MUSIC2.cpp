/*
USER: zobayer
TASK: MUSIC2
ALGO: ad-hoc
*/

#include <cstdio>

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	char a[16], b[16];
	int t=1,x;
	while(scanf("%s %s", a, b) == 2) {
	    if(!a[1]) printf("Case %d: UNIQUE\n", t++);
	    else {
	        if(a[1]=='b') {
	            a[1]='#';
	            x=-1;
	        }
	        else {
	            a[1]='b';
	            x=1;
	        }
	        a[0]=(a[0]-'A'+7+x)%7+'A';
	        printf("Case %d: %s %s\n", t++, a, b);
	    }
	}
	return 0;
}
