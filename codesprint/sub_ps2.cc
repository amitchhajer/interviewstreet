/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include<iostream>
#include<deque>
#include<algorithm>
#include <cassert>
using namespace std;
deque<long> f;
deque<long> v;

int main()
{
    long n=0,t=0,s=0,st=0,m=0;
    long *a=NULL;
    long *b=NULL;
    cin>>t;
    deque<long>::iterator I;
    for(long i=0;i<t;i++)
    {   s=0;
        cin>>n;
        a=new long[n];
        b=new long[n];
        f.clear();
        v.clear();
        for(long j=0;j<n;j++)
        {   cin>>a[j];
        }
        for(long j=0;j<n;j++)
        {   cin>>b[j];        
            if(f.empty()==true)
            {   f.push_back(a[j]);
                v.push_back(b[j]);
                s+=b[j];
            }
            else
            {   m=f.back();
                if(m<a[j])
                {   f.push_back(a[j]);
                    v.push_back(b[j]);                
                    s+=b[j];
                }
                else
                {   deque<long>::iterator where = find(f.begin(), f.end(), a[j]);
                    st=0;
                    long li=*where;
                    long lf=f.size();
                    for(int lt=li;lt<lf;lt++)//while(I<f.end())
                    {   st+=b[lt];
                    }
                    if(st<b[j])
                    {   I=f.end();
                        while(I>where)
                        {
                            f.pop_back();
                            v.pop_back();
                            I--;
                        }
                        f.push_back(a[j]);
                        v.push_back(b[j]);
                        s-=st;
                        s+=b[j];
                    }
                }
            }
        }   
        s=0;
        while(v.empty()==false)
        {
            s+=v.front();
            v.pop_front();
        }
        cout<<s<<endl;
    }
    return 0;
}
