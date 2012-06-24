/*
USER: zobayer
TASK: SQRROOT
ALGO: big integer
*/

#include<stdio.h>
#include<string.h>

#define BASE 100000000
#define FALSE 0
#define TRUE 1

typedef long long LL;

struct BigInt{
	int n;
	int d[130];
}Y,X,S,M,Snew;

void PrintBI(BigInt X){
	int i,n = X.n;
	printf("%d",X.d[n-1]);
	for(i=n-2;i>=0;i--)
		printf("%08d",X.d[i]);
	printf("\n");
}    

int greater(BigInt A,BigInt B){
	int i;
	if(A.n > B.n)
		return TRUE;
	if(A.n < B.n)
		return FALSE;
	for(i=A.n-1;i>=0;i--){
		if(A.d[i] > B.d[i])
			return TRUE;
		if(A.d[i] < B.d[i])
			return FALSE;
	}
	return TRUE;
}    

void cut_lead_zero(BigInt *X){
	int i,n;
	n = X->n;
	for(i=n-1;i>0;i--)
		if(X->d[i])
			break;
	X->n = i+1;
}    

int solve(int digit,int k){
    int i,j,a,carry,take;
    LL tot;
    if(digit==0){
    	for(i=0;i<S.n;i++)
    		Snew.d[i] = S.d[i];
		Snew.n = S.n;
		return TRUE;
    }    
	carry = 0;
	M.d[0] = digit;
	for(i=k+1,j=1;i<X.n || carry;i++,j++){
	    if(i<X.n)	a = X.d[i];
	    else		a = 0;
		tot = a * 2 + carry;
		M.d[j] = tot % BASE;
		carry = tot / BASE;
 	}    
 	M.n = j;
 	for(carry=i=0;i<M.n || carry;i++){
	    if(i<M.n)	a = M.d[i];
	    else		a = 0;
 	    tot = ((LL)(digit)) * ((LL)(a)) + carry;
		M.d[i] = tot % BASE;
		carry = tot / BASE;
 	}
 	M.n = i;
 	if( !greater(S,M) )
 		return FALSE;
 	take = 0;
 	for(i=0;i<S.n;i++){
	    if(i<M.n)	a = M.d[i];
	    else		a = 0;
 		tot = S.d[i] - a - take;
 		if(tot < 0){
 			tot+=BASE;
 			take = 1;
   		}
   		else
   			take = 0;
		Snew.d[i] = tot % BASE;
  	}    
 	Snew.n = i;
  	return TRUE;
}    

int main(){
    char ss[1005];
    int N,ks,L,i,j,k,digit;
    int ux,lx,x ,f;
    scanf("%d",&ks);
    for(N=0;N<ks;N++){
        scanf("%s",ss);
        L = strlen(ss);
		Y.n = 0;
        for(i=L;i>0;i-=8){
            k = i-8;
            if(k<0) k = 0;
        	digit = 0;
        	for(j=k;j<i;j++)
        		digit = digit*10 + ss[j]-'0';
			Y.d[Y.n++] = digit;
        }            
		X.n = (Y.n+1) / 2;
		S.n = 0;
		k = Y.n-1;
		if(k%2==1){
			S.d[1] = Y.d[k--];
			S.n++;
		}			
		S.d[0] = Y.d[k--];
		S.n++;
		for(i=X.n - 1;i>=0;i--){
			lx = 0;
			ux = BASE;
			while(lx<ux){
			    x = (lx+ux)/2;
			    f = solve(x,i);
			    if( f == TRUE && (x==BASE-1 || solve(x+1,i) == FALSE) )
			    	break;
   				if( f == TRUE )
   					lx=x+1;
				else
					ux=x;
   			}    
			X.d[i] = x;
			S.d[1] = Y.d[k--];
			S.d[0] = Y.d[k--];
   			for(j=0;j<Snew.n;j++)
   				S.d[j+2] = Snew.d[j];
			S.n = Snew.n + 2;
			cut_lead_zero(&S);
  		}
    	PrintBI(X);
    }    
	return 0;
}    
