/*
USER: zobayer
TASK: CMEXPR
ALGO: expression tree
*/

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
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

#define DEBUG if(0)
#define PAUSE system("pause")
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(c) c.begin(), c.end()
#define PB(x) push_back(x)
#define UB(s, e, x) upper_bound(s, e, x)
#define LB(s, e, x) lower_bound(s, e, x)
#define REV(s, e) reverse(s, e);
#define SZ(c) c.size()
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define i64 long long
#define ff first
#define ss second

template< class T > T sq(T &x) { return x * x; }
template< class T > T abs(T &n) { return (n < 0 ? -n : n); }
template< class T > T max(T &a, T &b) { return (!(a < b) ? a : b); }
template< class T > T min(T &a, T &b) { return (a < b ? a : b); }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T mod(T &a, T &b) { return (a < b ? a : a % b); }
template< class T > bool inside(T &a, T &b, T &c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

const double EPS = 1e-9;
const int INF = 0x3f3f3f3f;
const int MAXLEN = 256;

struct Node {
	int left, right;
	char token;
};

char infix[MAXLEN], result[MAXLEN], postfix[MAXLEN];
Node Tree[MAXLEN];
int pidx;

inline bool isoper(char ch) {
	return (ch=='+'||ch=='-'||ch=='*'||ch=='/');
}

inline bool isvar(char ch) {
	return (ch>='a' && ch<='z');
}

inline int precd(char ch) {
	switch(ch) {
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		default : return 3;
	}
}

void getPostfix(char *post, int &plen, char *inp, int len) {
	plen = 0;
	stack< char > S;
	for(int i = 0; i < len; i++) {
		if(isvar(inp[i])) post[plen++] = inp[i];
		else if(inp[i]=='(') S.push('(');
		else if(inp[i]==')') {
			while(!S.empty() && S.top()!='(') {
				post[plen++] = S.top();
				S.pop();
			}
			if(!S.empty()) S.pop();
		}
		else {
			while(!S.empty() && S.top() != '(' && precd(S.top()) >= precd(inp[i])) {
				post[plen++] = S.top();
				S.pop();
			}
			S.push(inp[i]);
		}
	}
	while(!S.empty()) {
		post[plen++] = S.top();
		S.pop();
	}
}

int buildTree(char *post, int len) {
	stack< int > S;
	int idL, idR, nodes = 0;
	for(int i = 0; i < len; i++) {
		if(islower(post[i])) {
			Tree[nodes].left = Tree[nodes].right = -1;
			Tree[nodes].token = post[i];
			S.push(nodes++);
		}
		else {
			idR = S.top(); S.pop();
			idL = S.top(); S.pop();
			Tree[nodes].left = idL;
			Tree[nodes].right = idR;
			Tree[nodes].token = post[i];
			S.push(nodes++);
		}
	}
	return S.top();
}

void print(int root) {
	bool br;
	char ch;
	switch(Tree[root].token) {
		case '+':
			print(Tree[root].left);
			result[pidx++] = '+';
			print(Tree[root].right);
		break;
		case '-':
			print(Tree[root].left);
			result[pidx++] = '-';
			ch = Tree[Tree[root].right].token;
			br = (ch=='+') | (ch=='-');
			if(br) result[pidx++] = '(';
			print(Tree[root].right);
			if(br) result[pidx++] = ')';
		break;
		case '*':
			ch = Tree[Tree[root].left].token;
			br = (ch=='+') | (ch=='-');
			if(br) result[pidx++] = '(';
			print(Tree[root].left);
			if(br) result[pidx++] = ')';
			result[pidx++] = '*';
			ch = Tree[Tree[root].right].token;
			br = (ch=='+') | (ch=='-');
			if(br) result[pidx++] = '(';
			print(Tree[root].right);
			if(br) result[pidx++] = ')';
		break;
		case '/':
			ch = Tree[Tree[root].left].token;
			br = (ch=='+') | (ch=='-');
			if(br) result[pidx++] = '(';
			print(Tree[root].left);
			if(br) result[pidx++] = ')';
			result[pidx++] = '/';
			ch = Tree[Tree[root].right].token;
			br = !islower(ch);
			if(br) result[pidx++] = '(';
			print(Tree[root].right);
			if(br) result[pidx++] = ')';
		break;
		default : result[pidx++] = Tree[root].token;
	}
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int t = atoi(fgets(infix, MAXLEN, stdin));
	int ilen, plen, root;
	while(t--) {
		fgets(infix, MAXLEN, stdin);
		for(ilen = 0; infix[ilen] > ' '; ilen++);
		getPostfix(postfix, plen, infix, ilen);
		//puts(postfix);
		root = buildTree(postfix, plen);
		pidx = 0; print(root); result[pidx] = 0;
		puts(result);
	}
	return 0;
}
