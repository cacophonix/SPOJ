#include<ios>
int a[105][105],i,j,t,n;
main(){scanf("%d",&t);while(t--){scanf("%d",&n);for(i=1;i<=n;i++)for(j=1;j<=i;j++){scanf("%d",&a[i][j]);a[i][j]=std::max(a[i-1][j-1],a[i-1][j])+a[i][j];}j=0;for(i=1;i<=n;i++)j=std::max(j,a[n][i]);printf("%d\n",j);}}
