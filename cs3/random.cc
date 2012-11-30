#include<stdio.h>
#include<iostream>
using namespace std;

int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int main()
{
    int t,a,b,c,i,temp,rem,probab,g;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>a>>b>>c;
        if(i != 1)
            cout<<"\n";
        if(a+b <= c)
        {
            cout<<"1/1";
        }
        else if(c<a) {
            rem = a - c;
            rem = rem + b;
            g = gcd(rem, (a+b));
            cout<<(a+b -rem)/g<<"/"<<(a+b)/g;
        }
        else if(c<b) {
            rem = b - c;
            rem = rem + a;
            g = gcd(rem, (a+b));
            cout<<(a+b - rem)/g<<"/"<<(a+b)/g;
        }
        else
        {
            if(a > b)
            {
                temp = c - b;
                rem = a - temp;
                g = gcd(rem,(a+b));
                cout<<(a+b - rem)/g<<"/"<<(a+b)/g;
            }
            else
            {
                temp = c - a;
                rem = b - temp;
                g = gcd((rem),(a+b));
                cout<<(a+b - rem)/g<<"/"<<(a+b)/g;
            }
        }
    }
    return 0;
}