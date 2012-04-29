#include<stdio.h>
#include<deque>
#include<iostream>
#define MAX 786
using namespace std;
long N[MAX*MAX]={0};
deque<int> a;
deque<int> b;
long n;
int pos(int x,int y)
{
    return x*n+y;
}
long sum(deque<int> d)
{   long s=0;
    int ix=0,iy=0;
    deque<int> temp;
    temp=a;
    if(temp.empty()==false)
    {
        ix=temp.front();
        temp.pop_front();
        while(temp.empty()==false)
        {   
            iy=temp.front();
            temp.pop_front();
            s+=N[ix*n+iy];
            ix=iy;
        }
    }
    return s;
}
int main()
{
    long i=0,j=0,nsc=0,temp;
    scanf("%ld",&n);
    long N1[MAX*MAX][2]={0,-1};
    //long Ns[MAX][2];
    //long NS[51][3]={0,0,0};
    for(i=0;i<n*n;i++)
    {
      scanf("%ld", &N[i]);
      if(i/n!=i)
      {
        N1[i][0]=N[i];
        N1[i][1]=i;
       }
    }
    
    for(i=0;i<MAX;i++)
     {
        for(j=0;j<n*n;j++)
        {
            //if(j/n!=j||!(i*j))
            {
                if(N1[j][0]<N1[j+1][0])
                {
                    temp=N1[j][0];
                    N1[j][0]=N1[j+1][0];
                    N1[j+1][0]=temp;
                    
                    temp=N1[j][1];
                    N1[j][1]=N1[j+1][1];
                    N1[j+1][1]=temp;
                    
                    
                }
            }
        }
     }
     int px,py;
     for(i=0;i<MAX;i++)
     {      
            //long st=0;
            //long sm=0;
            px=N1[i][1]/n;
            py=N1[i][1]%n; 
            a.push_front(px);
            a.push_back(py);
            for(j=0;j<n;j++)
            {   if(j!=px&&j!=py)
                {
                    if(N[pos(j,px)]>N[pos(py,j)])
                    {
                        a.push_front(j);  
                    }
                    else
                    {
                        a.push_back(j);  
                    }
                }
            }
            if(b.empty()==true)
            {
                b=a;
            }
            else
            {
                if(sum(a)>sum(b))
                {
                    b=a;
                }
            }
            a.clear();
     }          
 
        
         while(b.empty()==false)
        {   
            cout<<b.front()<<" ";
            b.pop_front();
           
         }
       
    return 0;
}
