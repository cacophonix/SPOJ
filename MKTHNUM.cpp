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

const int NMAX = 101000;
const int DEPTH = 20;

typedef struct { int l,r; } Node;

Node tree[NMAX*4];
int data[NMAX], seg[DEPTH][NMAX], LessMid[DEPTH][NMAX];

void buildtree(int root,int l,int r,int d) {
    tree[root].l=l,tree[root].r=r;
    if(l==r) return;
    int mid=(l+r)>>1;
    int lsame=mid-l+1;
    for(int i=l;i<=r;i++) {
        if(seg[d][i]<data[mid]) lsame--;
    }
    int tl=l,tr=mid+1,same=0;
    for(int i=l;i<=r;i++) {
        if(i==l) LessMid[d][i]=0;
        else LessMid[d][i]=LessMid[d][i-1];
        if(seg[d][i]<data[mid]) LessMid[d][i]++,seg[d+1][tl++]=seg[d][i];
        else if(seg[d][i]>data[mid]) seg[d+1][tr++]=seg[d][i];
        else {
            if(same<lsame) same++,LessMid[d][i]++,seg[d+1][tl++]=seg[d][i];
            else seg[d+1][tr++]=seg[d][i];
        }
    }
    buildtree(root<<1,l,mid,d+1);
    buildtree((root<<1)+1,mid+1,r,d+1);
}

int Query(int root,int l,int r,int d,int cnt) {
    if(l==r) return seg[d][l];
    int s;
    int ss;
    if(l==tree[root].l) s=LessMid[d][r],ss=0;
    else s=LessMid[d][r]-LessMid[d][l-1],ss=LessMid[d][l-1];
    if(s>=cnt) return Query(root<<1,tree[root].l+ss,tree[root].l+ss+s-1,d+1,cnt);
    else {
        int mid=(tree[root].l+tree[root].r)>>1;
        int bb=l-tree[root].l-ss;
        int b=r-l+1-s;
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
        int l,r,k;scanf("%d%d%d",&l,&r,&k);
        int res=Query(1,l,r,1,k);
        printf("%d\n",res);
    }
    return 0;
}
