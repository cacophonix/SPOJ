/*
USER: zobayer
TASK: LLCA
ALGO: ad-hoc
*/

#include<stdio.h>
int main(){
	int c,t,a,b;
	scanf("%d",&c);
	while(c--){
		scanf("%d%d%d",&t,&a,&b);
		while(a!=b){
			if(a>b)a=(a+t-2)/t;
			else b=(b+t-2)/t;
		}
		printf("%d\n",a);
	}
	return 0;
}