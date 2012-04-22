/*
USER: zobayer
TASK: IPCELLS
ALGO: expression evaluation
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

const double EPS = 1e-9;
const double BIG = 1e15;
const int NIL = 0;
const int INF = 0x3f3f3f3f;
const int MAX = 300;

struct data {
	int type; //1 var, 2 const, 3 oper
	int id; // for var, id of var
	string item; // item itself
};

char buff[1024];
map< string, int > M;
map< string, int > :: iterator it;
vector< data > def[MAX];
int val[MAX], n;
bool flag[MAX];

int preced(char ch) {
	switch(ch) {
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
	}
	return INF;
}

int getval(int u) {
	if(flag[u]) return val[u];
	flag[u] = true;
	
	int i, ax, bx, cx;
	data a, b, d;
	char temp[128];
	vector< data > expr;
	stack< data > S;
	
	// make postfix
	for(i = 0; i < SZ(def[u]); i++) {
		if(def[u][i].type==3) {
			while(!S.empty() && preced(S.top().item[0])>=preced(def[u][i].item[0])) {
				expr.PB(S.top());
				S.pop();
			}
			S.push(def[u][i]);
		}
		else expr.PB(def[u][i]);
	}
	while(!S.empty()) {
		expr.PB(S.top());
		S.pop();
	}
	
	// evaluate
	for(i = 0; i < SZ(expr); i++) {
		if(expr[i].type == 3) {
			b = S.top(); S.pop();
			a = S.top(); S.pop();
			if(a.type==1) ax = val[a.id] = getval(a.id);
			else ax = atoi(a.item.c_str());
			if(b.type==1) bx = val[b.id] = getval(b.id);
			else bx = atoi(b.item.c_str());
			switch(expr[i].item[0]) {
				case '+': cx = ax + bx; break;
				case '-': cx = ax - bx; break;
				case '*': cx = ax * bx; break;
				case '/': cx = ax / bx; break;
			}
			sprintf(temp, "%d", cx);
			d.item = temp;
			d.type = 2;
			S.push(d);
		}
		else S.push(expr[i]);
	}
	
	return atoi(S.top().item.c_str());
}

int main() {
	int t = atoi(fgets(buff, 1024, stdin)), i, idx, u;
	string cell, dump;
	data d;
	
	while(t--) {
		fgets(buff, 1024, stdin);
		n = atoi(fgets(buff, 1024, stdin));
		idx = 0;
		M.clear();
		for(i = 0; i < n; i++) {
			def[i].clear();
			flag[i] = false;
		}
		
		for(i = 0; i < n; i++) {
			fgets(buff, 1024, stdin);
			stringstream ss(buff);
			ss >> cell >> dump;
			it = M.find(cell);
			if(it==M.end()) M.insert(make_pair(cell, u=idx++));
			else u = it->ss;
			while(ss >> cell) {
				d.item = cell;
				if(isalpha(cell[0])) {
					d.type = 1;
					it = M.find(cell);
					if(it==M.end()) M.insert(make_pair(cell, d.id=idx++));
					else d.id = it->ss;
				}
				else if(isdigit(cell[0])) d.type = 2;
				else d.type = 3;
				def[u].PB(d);
			}
		}
		
		for(i = 0; i < n; i++) if(!flag[i]) val[i] = getval(i);
		for(it = M.begin(); it != M.end(); it++) cout << it->ff << " = " << val[it->ss] << '\n';
		if(t) cout << '\n';
	}
	return 0;
}
