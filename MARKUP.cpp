/*
USER: zobayer
TASK: MARKUP
ALGO: ad-hoc
*/

#include <cstdio>
#include <cctype>
using namespace std;

void eatnumber() {
	char ch;
	while(isdigit(ch=getchar()));
	if(ch=='.') while(isdigit(ch=getchar()));
	ungetc(ch, stdin);
}

bool enabled() {
	char ch;
	while((ch=getchar())!=EOF) {
		if(ch=='\\') {
			switch(ch=getchar()) {
				case 'b':
				case 'i': break;
				case 's': eatnumber(); break;
				case '*': return true;
				default: putchar(ch);
			}
		}
		else putchar(ch);
	}
	return false;
}

bool disabled() {
	char ch;
	while((ch=getchar())!=EOF) {
		if(ch=='\\') {
			if((ch=getchar())=='*') return true;
			ungetc(ch, stdin);
			putchar('\\');
		}
		else putchar(ch);
	}
	return false;
}

int main() {
	while(enabled() && disabled());
	return 0;
}