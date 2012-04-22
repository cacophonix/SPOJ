/*
USER: zobayer
TASK: ARCTAN
ALGO: math
*/

#include <ios>
#include <algorithm>
int main(){long long a,c,t,b;scanf("%lld",&t);while(t--){scanf("%lld",&a);c=1;c<<=60;
for(b=a+1;b<=2*a+1;b++)if((a*b+1)%(b-a)==0)c=std::min(c,b+(a*b+1)/(b-a));printf("%lld\n",c);}return 0;}