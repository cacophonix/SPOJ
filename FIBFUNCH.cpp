#include<cstdio>
#include<cstring>
#define C(d,s) memcpy(d,s,32)
typedef long long i64;i64 f[2][2]={{1,1},{1,0}},u[2][2]={{1,0},{0,1}},x[2][2],y[2][2],r[2][2];int t,p,q,i,j,k,n,m;void M(i64 a[][2],i64 b[][2]){for(i=0;i<2;i++)for(j=0;j<2;j++)for(y[i][j]=k=0;k<2;k++)y[i][j]=(y[i][j]+a[i][k]*b[k][j])%m;C(a,y);}void E(){C(x,f);C(r,u);while(n){if(n&1)M(r,x);M(x,x);n/=2;}}int main(){scanf("%d",&t);while(t--){scanf("%d%d%d%d",&p,&q,&n,&m);E();printf("%lld\n",((q*r[0][0]+p*r[0][1]-q)%m+m)%m);}return 0;}
