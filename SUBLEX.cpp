/*
USER: zobayer
TASK: SUBLEX
ALGO: suffix array
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX = 90016;
char str[MAX];
int c[MAX], height[MAX], s[MAX], SA[MAX], sbstr[MAX];

#define GetI() (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2)

inline bool leq(int a1, int a2, int b1, int b2) {
	return(a1 < b1 || (a1 == b1 && a2 <= b2));
}

inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
	return(a1 < b1 || (a1 == b1 && leq(a2,a3, b2,b3)));
}

static void radixPass(int* a, int* b, int* r, int n, int K) {
	int i, sum, t;
	for(i = 0;  i <= K;  i++) c[i] = 0;
	for(i = 0;  i < n;  i++) c[r[a[i]]]++;
	for(i = 0, sum = 0;  i <= K;  i++) {
		t = c[i];
		c[i] = sum;
		sum += t;
	}
	for(i = 0;  i < n;  i++) b[c[r[a[i]]]++] = a[i];
}

void suffixArray(int* s, int* SA, int n, int K) {
	int n0 = (n+2)/3, n1 = (n+1)/3, n2 = n/3, n02 = n0+n2;
	int* s12 = new int[n02 + 3];
	int* SA12 = new int[n02 + 3];
	int* s0 = new int[n0];
	int* SA0 = new int[n0];
	int i, j, name, c0, c1, c2, p, t, k;
	s12[n02] = s12[n02+1] = s12[n02+2] = 0;
	SA12[n02] = SA12[n02+1] = SA12[n02+2] = 0;
	for(i=0, j=0; i < n+(n0-n1); i++) if(i%3 != 0) s12[j++] = i;
	radixPass(s12, SA12, s+2, n02, K);
	radixPass(SA12, s12, s+1, n02, K);
	radixPass(s12, SA12, s, n02, K);
	name = 0, c0 = -1, c1 = -1, c2 = -1;
	for(i = 0; i < n02; i++) {
		if(s[SA12[i]] != c0 || s[SA12[i]+1] != c1 || s[SA12[i]+2] != c2) {
			name++;
			c0 = s[SA12[i]];
			c1 = s[SA12[i]+1];
			c2 = s[SA12[i]+2];
		}
		if(SA12[i] % 3 == 1) s12[SA12[i]/3] = name;
		else s12[SA12[i]/3 + n0] = name;
	}
	if(name < n02) {
		suffixArray(s12, SA12, n02, name);
		for(i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
	}
	else for(i = 0; i < n02; i++) SA12[s12[i] - 1] = i;
	for(i=0, j=0; i < n02; i++) if(SA12[i] < n0) s0[j++] = 3*SA12[i];
	radixPass(s0, SA0, s, n0, K);
	for(p=0, t=n0-n1, k=0; k < n; k++) {
		i = GetI(); j = SA0[p];
		if(SA12[t] < n0 ? leq(s[i], s12[SA12[t] + n0], s[j], s12[j/3]) : leq(s[i], s[i+1], s12[SA12[t]-n0+1], s[j], s[j+1], s12[j/3+n0])) {
			SA[k] = i; t++;
			if(t == n02) for(k++; p < n0; p++, k++) SA[k] = SA0[p];
		}
		else {
			SA[k] = j; p++;
			if(p == n0) for(k++; t < n02; t++, k++) SA[k] = GetI();
		}
	}
	delete[] s12; delete[] SA12; delete[] SA0; delete[] s0;
}

void Suffix_Array(int &n){
	int m, i;
	for(i = 0, m = -1; 'a' <= str[i] && str[i] <= 'z'; i++) {
		s[i] = str[i]-'a'+1;
		m = m > s[i]? m : s[i];
	}
	n = i;
	for(i = n; i < n + 3; i++) s[i] = SA[i] = 0;
	suffixArray(s, SA, n, m);
}

void getHeight(int n) {
	int h, i, j;
	for(i=0; i<n; i++) s[SA[i]] = i;
	height[0] = 0;
	for(i=0, h=0; i<n; i++){
		if(s[i] > 0){
			j = SA[s[i]-1];
			while(i + h < n && j + h < n && str[i+h] == str[j+h]) h++;
			height[s[i]] = h;
			if(h > 0) h--;
		}
	}
}

int lowerBound(int s, int e, int v, int *a) {
	int i, cnt, stp;
	cnt = e - s;
	while(cnt > 0) {
		i = s; stp = cnt>>1; i += stp;
		if(a[i] < v) {
			s = ++i;
			cnt -= stp+1;
		}
		else cnt = stp;
	}
	return s;
}

int main() {
	int sz, i, q, idx, pos, len;
	char num[20], *p;
	fgets(str, MAX, stdin);
	Suffix_Array(sz);
	getHeight(sz);
	sbstr[0] = sz - SA[0] - height[0];
	for(i = 1; i < sz; i++) sbstr[i] += (sz-SA[i]-height[i]+sbstr[i-1]);
	q = atoi(fgets(num, 20, stdin));
	while(q--) {
		idx = atoi(fgets(num, 20, stdin));
		pos = lowerBound(0, sz, idx, sbstr);
		idx -= (pos? sbstr[pos-1] : 0);
		len = height[pos] + idx;
		p = &str[SA[pos]];
		for(i = 0; i < len; i++) putchar(*(p+i));
		putchar('\n');
	}
	return 0;
}
