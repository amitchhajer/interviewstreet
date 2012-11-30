#include<stdio.h>
#include<iostream>
using namespace std;

int min(int x, int y)
{
    return x>y?y:x;
}

int max(int x, int y)
{
    return x>y?x:y;
}

int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}
// TODO::a>b else swap, multiply by 100 and gcd

int main()
{
    int t,a,b,c,i,area,probab, point, point2, point3,g;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>a>>b>>c;
        if(a<b)
        {
            int temp;
            temp = a;
            a = b;
            b = temp;
        }
        if(i != 1)
            cout<<"\n";
        if(c <= min(a,b))
        {
            area = c * c;
            g = gcd(area, a*b*2);
            cout<<area/g<<"/"<<(a*b*2)/g;
        }
        else if(c >= a+b)
        {
            cout << "1/1";
        }
        else if( c > min(a,b) && c <= max(a,b) )
        {
            point = c - b;
            area = ((c-point) * b) + (point * b * 2);
            g = gcd(area, a*b*2);
            cout<<area/g<<"/"<<(a*b*2)/g;
        }
        else if( c < (a+b) && c > max(a,b) )
        {
            point = c - b;
            area = (b * point * 2);
            point2 = c - a;
            point3 = a - point;
            area = area + (point3 * point2 * 2) + ((b- point2) * point3);
            g = gcd(area, a*b*2);
            cout<<area/g<<"/"<<(a*b*2)/g;
        }

    }
    return 0;

}