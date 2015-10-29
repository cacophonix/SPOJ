#include<stdio.h>
int main()
{
    int t;
    int a[200]; //array will have the capacity to store 200 digits.
    int n,i,j,temp,m,x;

    scanf("%d",&t);
    while(t--)
    {
       scanf("%d",&n);
       a[0]=1;  //initializes array with only 1 digit, the digit 1.
       m=1;    // initializes digit counter

       temp = 0; //Initializes carry variable to 0.
       for(i=1;i<=n;i++)
       {
            for(j=0;j<m;j++)
            {
               x = a[j]*i+temp; //x contains the digit by digit product
               a[j]=x%10; //Contains the digit to store in position j
               temp = x/10; //Contains the carry value that will be stored on later indexes
            }
             while(temp>0) //while loop that will store the carry value on array.
             {
               a[m]=temp%10;
               temp = temp/10;
               m++; // increments digit counter
             }
      }
              for(i=m-1;i>=0;i--) //printing answer
              printf("%d",a[i]);
              printf("\n");
    }
    return 0;
}
