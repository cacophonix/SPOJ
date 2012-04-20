/*
USER: zobayer
TASK: POUR1
ALGO: simulation
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	while(b) b ^= a ^= b ^= a %= b;
	return a;
}

int cnt(int A, int B, int C) {
	int move = 1, a = A, b = 0, pour;
	while(a != C && b != C) {
		pour = min(a, B-b);
		b += pour;
		a -= pour;
		move++;
		if(a == C || b == C) break;
		if(b==B) b = 0, move++; 
		else if(a==0) a = A, move++;
	}
	return move;
}

int main() {
	int a, b, c, t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &a, &b, &c);
		if(c > a && c > b) printf("-1\n");
		else if(!c) printf("0\n");
		else if(c == a || c == b) printf("1\n");
		else if(c % gcd(a, b)) printf("-1\n");
		else printf("%d\n", min(cnt(a, b, c), cnt(b, a, c)));
	}
	return 0;
}
