/*
USER: zobayer
TASK: EQ2
ALGO: dynamic programming
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
#define SZ(c) (i64)c.size()
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
#define pii pair< i64, i64 >
#define psi pair< string, i64 >

const double EPS = 1e-9;
const i64 INF = 0x7f7f7f7f;
char a[20],b[20],c[20],str[100];
i64 la,lb,lc,l;
i64 dp[20][5];

i64 func(i64 pos,i64 carry){
    if(pos==l){
        if(lc==l)return carry==0;
        else if(lc==l+1){
            if(c[pos]=='?')return carry>0;
            return c[pos]-'0'==carry;
        }
        return 0;
    }
    if(pos>=lc)return 0;
    i64 &ret=dp[pos][carry],i,j,sa,ea,sb,eb,sum,ncarry;
    if(ret!=-1)return ret;
    ret=0;
    if(a[pos]=='?'){
        sa=0;
        ea=9;
        if(pos==la-1 && la>1)sa++;
    }
    else sa=ea=a[pos]-'0';

    if(b[pos]=='?'){
        sb=0;
        eb=9;
        if(pos==lb-1 && lb>1)sb++;
    }
    else sb=eb=b[pos]-'0';

    for(i=sa;i<=ea;i++){
        for(j=sb;j<=eb;j++){
            sum=(i+j+carry)%10;
            ncarry=(i+j+carry)/10;
            if(c[pos]=='?' || c[pos]==sum+'0')ret+=func(pos+1,ncarry);
        }
    }
    return ret;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	i64 i,t=1;
	while(scanf("%s",str)==1){
	    for(i=0;str[i];i++)if(str[i]=='+' || str[i]=='=')str[i]=' ';
	    CLR(a);
	    CLR(b);
	    sscanf(str,"%s %s %s",a,b,c);
	    la=strlen(a);
	    lb=strlen(b);
	    lc=strlen(c);
	    int flag=0;
	    if(a[0]=='0' && la>1)flag=1;
	    if(b[0]=='0' && lb>1)flag=1;
	    if(c[0]=='0' && lc>1)flag=1;
	    if(!flag){
	        reverse(a,a+la);
            reverse(b,b+lb);
            reverse(c,c+lc);
            for(i=la;i<lb;i++)a[i]='0';
            for(i=lb;i<la;i++)b[i]='0';
            l=_max(la,lb);
            SET(dp);
            printf("Case %lld: %lld\n",t++,func(0,0));
	    }
	    else{
	           printf("Case %lld: 0\n",t++);
	    }
	}
	return 0;
}
