/*
USER: zobayer
TASK: PLD
ALGO: hashing
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <set>
#define SIZE 234567
using namespace std;

vector< multiset<int> > array;
int N,K,th,total;
char str[40000];

void check(int hval,int place)
{
    int i;
    if(array[hval].find(place-(K%2?2:1))!=array[hval].end())
    {
        if(th<=30)
        {
            for(i=0;i<th;i++)
            {
                if(str[place+i]!=str[place-i-(K%2?2:1)]) return;
            }
        }
        total++;
    }
}

int main()
{
    int i,mod,hval;
    array.resize(SIZE);
    scanf("%d%s", &K, str);
    N=strlen(str);
    if(K>N) {printf("0\n"); return 0;}
    if(K==1) {printf("%d\n",N); return 0;}
    th=K/2;
    mod=1;
    hval=0;
    for(i=0;i<N;i++) str[i]-='a';
    for(i=th-1;i>=0;i--)
    {
        hval+=(str[i])*mod;
        if(i!=0)
        mod*=27;
        mod%=SIZE;
        hval%=SIZE;
    }
    array[hval].insert(th-1);
    for(i=th;i<N;i++)
    {
        hval-=mod*str[i-th];
        while(hval<0) hval+=SIZE;
        hval*=27;
        hval+=str[i];
        hval%=SIZE;
        array[hval].insert(i);
    }
    mod=1;
    hval=0;
    for(i=N-th;i<=N-1;i++)
    {
        hval+=(str[i])*mod;
        if(i!=N-1)
        mod*=27;
        mod%=SIZE;
        hval%=SIZE;
    }
    check(hval,N-th);
    for(i=N-th-1;i>=0;i--)
    {
        hval-=mod*str[i+th];
        while(hval<0) hval+=SIZE;
        hval*=27;
        hval+=str[i];
        hval%=SIZE;
        check(hval,i);
    }
    printf("%d\n",total);
    return 0;
}
