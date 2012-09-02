/*
USER: zobayer
TASK: CITY2
ALGO: segment tree
*/

//#pragma warning (disable: 4786)
//#pragma comment (linker, "/STACK:0x800000")
//#define _CRT_SECURE_NO_WARNINGS 1

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }

#define ALL(p) p.begin(),p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define cllft lft,st,mid
#define clrgt rgt,mid+1,ed
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >
#define MX 100009

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;

int nd[4*MX],pre[MX],a[MX];
map<int,int> mp;

void insert(int idx,int st,int ed,int s,int val){
    if(st==s && ed==s){
        nd[idx]=val;
        return;
    }
    int mid=(st+ed)/2;
    if(s<=mid)insert(cllft,s,val);
    else insert(clrgt,s,val);
    nd[idx]=_min(nd[lft],nd[rgt]);
}

int query(int idx,int st,int ed,int s,int e){
    if(st==s && ed==e)return nd[idx];
    int mid=(st+ed)/2;
    if(e<=mid)return query(cllft,s,e);
    else if(s>mid)return query(clrgt,s,e);
    else return _min(query(cllft,s,mid),query(clrgt,mid+1,e));
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int n,i,res,x,t=1;
	while(cin>>n){
	    mp.clear();
	    CLR(pre);
	    CLR(nd);
	    for(i=1;i<=n;i++){
	        scanf("%d",&a[i]);
	        pre[i]=mp[a[i]];
	        mp[a[i]]=i;
	        insert(root,1,n,i,a[i]);
	    }
	    res=0;
	    for(i=1;i<=n;i++){
	        if(a[i] && pre[i]){
	            x=query(root,1,n,pre[i],i);
	            //cout<<i<<" "<<pre[i]<<" "<<x<<endl;
	            if(x<a[i])res++;
	        }
	        else if(a[i])res++;
	    }
	    printf("Case %d: %d\n",t++,res);
	}
	return 0;
}
