/*
USER: zobayer
TASK: BOOKS1
ALGO: binary search
*/

#include <iostream>

#define M 500

using namespace std;

int p[M+1], a[M+1];

long long search_result(const int& m, const int& n, long long begin_p, long long end_p);
bool feasible(const int& m, const int& n, const long long& thre);
void print_result(const int& m, const int& n, const long long& thre);

int main()
{
    int num_of_cases;
    long long sum, avg, max_value, thre;
    
    cin >> num_of_cases;
    
    for(int counter = 0; counter < num_of_cases; counter++)
    {
        int m, n;
        
        cin >> m >> n;
        a[0] = sum = max_value = 0;
        
        for(int i = 1; i <= m; i++)
        {
            cin >> p[i];
            max_value = ((max_value > p[i])? max_value : p[i]);
            sum += p[i];
            a[i] = a[i-1] + p[i];
        }
        
        avg = sum / n;
        avg = ((avg > max_value)? avg : max_value);
        thre = search_result(m, n, avg, sum);
        print_result(m, n, thre);
    }
    
    return 0;
}
long long search_result(const int& m, const int& n, long long begin_p, long long end_p)
{
    long long temp;
    
    while(begin_p < end_p)
    {
        temp = (begin_p + end_p) / 2;
        
        if(feasible(m, n, temp))
            end_p = temp;
        else
            begin_p = temp + 1;
    }
    
    return end_p;
}
bool feasible(const int& m, const int& n, const long long& thre)
{
    int k = 0;
    
    for(int i = m; i >= 1;)
    {
        long long temp = 0;
        
        for(int j = i-1; j >= 0; j--)
        {
            if(a[i] - a[j] > thre)
            {
                temp = j + 1;
                break;
            }
        }
        
        i = temp, k++;
    }
    
    return (k <= n);
}
void print_result(const int& m, const int& n, const long long & thre)
{
    int k = 0;
    long long temp;
    bool seq[m];
    
    for(int i = 0; i < m; i++)
        seq[i] = false;
    
    for(int i = m; i >= 1;)
    {
        temp = 0;
        
        for(int j = i-1; j >= 0; j--)
        {
            if(a[i] - a[j] > thre)
            {
                temp = j + 1;
                break;
            }
        }
        
        i = temp, k++;
        seq[i] = true;
    }
    
    temp = 1;
    
    while(k < n)
    {
        if(!seq[temp])
            seq[temp] = true, k++;
        
        temp++;
    }
    
    for(int j = 1; j < m; j++)
    {
        cout << p[j] << ' ';
        
        if(seq[j])
            cout << "/ ";
    }
    
    cout << p[m] << endl;
}

