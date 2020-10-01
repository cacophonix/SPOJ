#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n],i;
        long long int s=0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            s=s+a[i];
        }
        if(s%n==0)
            cout<<n<<endl;
        else
            cout<<n-1<<endl;
    }
    return 0;
}
