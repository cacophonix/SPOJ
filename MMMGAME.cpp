/*
USER: zobayer
TASK: MMMGAME
ALGO: nim game
*/

#include <cstdio>
using namespace std;

int main(){
       int t, n, i, a[50];
       scanf("%d", &t);
       while(t--){
               scanf("%d", &n);
               int cnt = 0;
               for(i=0; i<n; i++){
                       scanf("%d", &a[i]);
                       if(a[i]==1) cnt++;
               }
               if(cnt==n){
                       if(n & 1) puts("Brother");
                       else puts("John");
               }
               else {
                       for(i=1; i<n; i++)a[0]^=a[i];
                       if(a[0]==0) puts("Brother");
                       else puts("John");
               }
       }
       return 0;
}
