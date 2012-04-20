/*
USER: zobayer
TASK: MZVRK
ALGO: math
*/

#include <iostream>
using namespace std;

typedef long long i64;

const int MAX = 50;
i64 sumd[MAX];

void calc() {
	sumd[0] = 1;
	for(int i=1; i<MAX; i++) sumd[i] = (sumd[i-1]<<1) + (1LL<<i);
}

i64 getSum(i64 n) {
	int i;
	i64 v, sum = 0;
	while(n) {
		for(i=0; i<MAX; i++)
			if((1LL<<i) > n)
				break;
		i--; v = 1LL<<i;
		sum += sumd[i] - ((i>0)?sumd[i-1]:0);
		n -= v;
	}
	return sum;
}

int main() {
	i64 a, b;
	cin >> a >> b;
	calc();
	cout << getSum(b)-getSum(a-1) << endl;
	return 0;
}
