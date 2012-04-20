/*
USER: zobayer
TASK: HEPNUM
ALGO: ad-hoc
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 100032;
char num1[MAX], num2[MAX];

int main() {
	int i, j, len1, len2, d;
	char a, b;
	while(scanf("%s%s", num1, num2)==2) {
		if(num1[0]=='*' && num2[0]=='*') break;
		len1 = strlen(num1);
		len2 = strlen(num2);
		for(i = j = d = 0; !d && i < len1 && j < len2; ) {
			if(len2 - j > len1 - i) {
				a = '0';
				b = num2[j];
				j++;
			}
			else if(len2 - j < len1 - i) {
				a = num1[i];
				b = '0';
				i++;
			}
			else {
				a = num1[i];
				b = num2[j];
				i++; j++;
			}
			d = a - b;
		}
		if(d < 0) printf("<\n");
		else if(d > 0) printf(">\n");
		else printf("=\n");
	}
	return 0;
}
