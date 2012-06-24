/*
USER: zobayer
TASK: MAKESUM
ALGO: greedy
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector< int > A, B, T;
vector< int >::iterator it;
int N[50], b[50], n, m;

bool construct(int init) {
	A.resize(n), B.resize(m); A[0] = init;
	for(int i = 0; i < m; i++) B[i] = b[i];
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i - 1; j++) {
			it = find(B.begin(), B.end(), A[j] + A[i-1]);
			if(it == B.end()) return false;
			B.erase(it);
		}
		A[i] = B[0] - A[0];
		if(A[i] < 0) return false;
	}
	return true;
}

int main() {
	for(int i = 1; i*(i-1) <= 100; i++) N[i * (i-1) / 2] = i;
	scanf("%d", &m); n = N[m];
	for(int i = 0; i < m; i++) scanf("%d", b + i);
	for(int i = 1; i <= b[0]/2; i++) {
		if(construct(i)) {
			sort(A.begin(), A.end());
			if(T.empty()) T = A;
			else if(A < T) T = A;
		}
	}
	printf("%d", T[0]);
	for(int i = 1; i < n; i++) printf(" %d", T[i]);
	printf("\n");
	return 0;
}
