/*
USER: zobayer
TASK: MULTQ3
ALGO: segment tree
*/

#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

#define ALL(c) c.begin(), c.end()
#define PB(x) push_back(x)
#define UB(s, e, x) upper_bound(s, e, x)
#define LB(s, e, x) lower_bound(s, e, x)
#define REV(s, e) reverse(s, e);
#define SZ(c) c.size()
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define i64 long long
#define ff first
#define ss second
#define DEBUG if(0)

struct FastRead {
	char *buff, *ptr;
	FastRead(int size) {
		buff = new char[size];
		ptr = buff;
		fread(buff, size, 1, stdin);
	}
	~FastRead() {
		delete[] buff;
	}
	inline int nextInt() {
		int ret = 0;
		while(*ptr < '0' || *ptr > '9') ptr++;
		do { ret = ret * 10 + *ptr++ - '0';
		} while(*ptr >= '0' && *ptr <= '9');
		return ret;
	}
};

const double EPS = 1e-9;
const double BIG = 1e15;
const int NIL = 0;
const int INF = 0x3f3f3f3f;
const int MAX = (1<<18);

struct NODE { int d[3], flip; } Tree[MAX];

void init(int Node, int S, int E) {
	if(S == E) {
		Tree[Node].d[0] = 1;
		return;
	}
	int L, R, M;
	L = Node << 1; R = L + 1; M = (S + E) >> 1;
	init(L, S, M);
	init(R, M+1, E);
	Tree[Node].d[0] = Tree[L].d[0] + Tree[R].d[0];
}

void update(int Node, int S, int E, int i, int j) {
	if(i==S && j==E) {
		Tree[Node].flip++;
		swap(Tree[Node].d[0], Tree[Node].d[1]);
		swap(Tree[Node].d[0], Tree[Node].d[2]);
		return;
	}
	int L, R, M;
	L = Node << 1; R = L + 1; M = (S + E) >> 1;
	if(j <= M) update(L, S, M, i, j);
	else if(i > M) update(R, M+1, E, i, j);
	else {
		update(L, S, M, i, M);
		update(R, M+1, E, M+1, j);
	}
	Tree[Node].d[0] = Tree[L].d[0] + Tree[R].d[0];
	Tree[Node].d[1] = Tree[L].d[1] + Tree[R].d[1];
	Tree[Node].d[2] = Tree[L].d[2] + Tree[R].d[2];
	switch(Tree[Node].flip % 3) {
		case 1:
			swap(Tree[Node].d[0], Tree[Node].d[1]);
			swap(Tree[Node].d[0], Tree[Node].d[2]);
		break;
		case 2:
			swap(Tree[Node].d[0], Tree[Node].d[1]);
			swap(Tree[Node].d[1], Tree[Node].d[2]);
		break;
	}
}

int query(int Node, int S, int E, int i, int j, int flips) {
	if(S==i && E==j) {
		switch(flips % 3) {
			case 0: return Tree[Node].d[0];
			case 1: return Tree[Node].d[2];
			case 2: return Tree[Node].d[1];
		}
		return 0;
	}
	int L, R, M;
	L = Node << 1; R = L + 1; M = (S + E) >> 1;
	flips += Tree[Node].flip;
	if(j <= M) return query(L, S, M, i, j, flips);
	else if(i > M) return query(R, M+1, E, i, j, flips);
	else return query(L, S, M, i, M, flips) + query(R, M+1, E, M+1, j, flips);
}

int main() {
	int n, q, t, i, j;
	FastRead r(4194304);
	n = r.nextInt(); q = r.nextInt();
	init(1, 0, n-1);
	while(q--) {
		t = r.nextInt(); i = r.nextInt(); j = r.nextInt();
		switch(t) {
			case 0: update(1, 0, n-1, i, j); break;
			case 1: printf("%d\n", query(1, 0, n-1, i, j, 0)); break;
		}
	}
	return 0;
}
