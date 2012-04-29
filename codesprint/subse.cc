#include<iostream>
using namespace std;
#define SIZE 25
#define MAXSIZE 25
struct pw
{
    float p,w;
};

void dknap(int n, float p1[], float w1[],float totalweight,int x[])
{
    struct pw pair[SIZE];
    int buffer[MAXSIZE];
    int next,start,end,i,j,k,up;
    float newprofit,newweight;
    pair[1].p=pair[1].w=0.0;
    buffer[0]=1;
    start=end=1;
    buffer[1]=next=2;
    for(i=1;i<n-1;i++)
    {
        k=start;
        for(j=start;j<=up;j++)
        {
            newprofit=pair[j].p+p1[i];
            newweight=pair[j].w+w1[i];
            while(k<=end && pair[k].w<newweight)
            {
                pair[next].p=pair[k].p;
                pair[next].w=pair[k].w;
                next++;
                k++;
            }
            if(k<=end && pair[k].w==newweight)
            {
                if(pair[k].p>newprofit)
                {
                    newprofit=pair[k].p;
                }
                k++;
            }
            if(newprofit>pair[next-1].p)
            {
             pair[next].p=newprofit;
             pair[next].w=newweight;
             next++;   
            }
            while(k<=end)
            {
            if(pair[k].p<=pair[next-1].p && pair[k].w>=pair[next-1].w)
                k++;
            }
                        
        }
        while(k<=end)
        {
            pair[next].p=pair[k].p;
            pair[next].w=pair[k].w;
            next++;k++;
        }
        start=end+1;
        end=next-1;
        buffer[i+1]=next;
     }
for(i=0;i<n;i++)
{
cout<<buffer[i];
}
//tracesol(p1,w1,pair,x,totalwieght,n,buffer);
}
int main()
{
float p[SIZE]={2,5,8,1};
float w[SIZE]={10,15,6,9};
int x[SIZE]={0},n=4;
float m=30;
dknap(n,p,w,m,x);
return 0;
}
