#include <iostream>

using namespace std;

int main()
{   int a[10001];
    int n;
    int i;
    int s=0;
    while(1)
    {
        i=0;
        s=0;
        cin>>n;
        int t=n;
        if(n==-1) break;
        while(t--)
        {
            int x;
            cin>>x;
            a[i++]=x;
            s+=x;

        }
        if(s%n!=0) cout<<-1<<endl;
        else{
            int o=0;
            for(int k=0;k<n;k++) if(a[k] - (s/n)>0) o += a[k] - (s/n);
            cout<<o<<endl;
        }
    }
}
