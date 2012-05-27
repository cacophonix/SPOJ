/*
USER: zobayer
TASK: MKTHNUM
ALGO: segment tree, merge sort
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int NMAX = 100001;
const int DEPTH = 18;

typedef struct { int lt,rt; } Node;

Node tree[1 << 18];
int data[NMAX], seg[DEPTH][NMAX], leftSide[DEPTH][NMAX];

void buildtree(int root,int lt,int rt,int d) {
    tree[root].lt=lt,tree[root].rt=rt;
    if(lt==rt) return;
    int mid=(lt+rt)>>1;
    int lsame=mid-lt+1;
    for(int i=lt;i<=rt;i++) {
        if(seg[d][i]<data[mid]) lsame--;
    }
    int tl=lt,tr=mid+1,same=0;
    for(int i=lt;i<=rt;i++) {
        if(i==lt) leftSide[d][i]=0;
        else leftSide[d][i]=leftSide[d][i-1];
        if(seg[d][i]<data[mid]) leftSide[d][i]++,seg[d+1][tl++]=seg[d][i];
        else if(seg[d][i]>data[mid]) seg[d+1][tr++]=seg[d][i];
        else {
            if(same<lsame) same++,leftSide[d][i]++,seg[d+1][tl++]=seg[d][i];
            else seg[d+1][tr++]=seg[d][i];
        }
    }
    buildtree(root<<1,lt,mid,d+1);
    buildtree((root<<1)+1,mid+1,rt,d+1);
}

int Query(int root,int lt,int rt,int d,int cnt) {
    if(lt==rt) return seg[d][lt];
    int s;
    int ss;
    if(lt==tree[root].lt) s=leftSide[d][rt],ss=0;
    else s=leftSide[d][rt]-leftSide[d][lt-1],ss=leftSide[d][lt-1];
    if(s>=cnt) return Query(root<<1,tree[root].lt+ss,tree[root].lt+ss+s-1,d+1,cnt);
    else {
        int mid=(tree[root].lt+tree[root].rt)>>1;
        int bb=lt-tree[root].lt-ss;
        int b=rt-lt+1-s;
        return Query((root<<1)+1,mid+bb+1,mid+bb+b,d+1,cnt-s);
    }
}

int main() {
    int n, m;
	scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&data[i]);
        seg[1][i]=data[i];
    }
    sort(data+1,data+1+n);
    buildtree(1,1,n,1);
    while(m--) {
        int lt,rt,k;scanf("%d%d%d",&lt,&rt,&k);
        int res=Query(1,lt,rt,1,k);
        printf("%d\n",res);
    }
    return 0;
}
