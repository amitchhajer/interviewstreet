#include<stdio.h>
#include<math.h>
#include <iostream>
using namespace std;
int main()
{
    unsigned long long int t,i,n,r,c,num = 1,den = 1,temp;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        cin>>r;
        if(r > n) cout<<"\n0";
        if(n == 0) cout<<"\n0";
        c = n-r;
        if(c > r)
        {
            temp = r;
            r = c;
            c = temp;
        }
        for(i=r+1;i<=n; i++)
        {
            num = (num * i)%142857;
        }
        cout<<num<<"\n";
        for(i=2;i<=c;i++)
        {
            den = (den * i)%142857;
        }
        cout<<den;
        cout<<"\n";
        cout<<num/den;
    }
    return 0;
}