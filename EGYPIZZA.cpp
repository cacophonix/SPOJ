#include <iostream>
#include<cstring>

using namespace std;

int main()
{
    int n;
    cin>>n;
    char *a = new char[n*3+1];
    char b[3];
    for(int i=0; i<n; i++)
    {
            cin>>b;
            strcpy(&a[i*3],b);
    }
    for(int i=0; i<n; i++)
    {
            cout<<a[i*3];
    }


    return 0;
}
