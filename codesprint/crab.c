#include<stdio.h>
int main()
{
long test=0,v1=0,v2=0,j=0,m=0,t=0,n=0,i=0,count=0,maxcount=0,k=0;
long N[5000][3]={0,0,0}; // should make a sparse matrix
long NC[100][2]={0,1};
scanf("%ld",&test);


for(k=0;k<test;k++)
{
scanf("%ld%ld%ld",&n,&t,&m); // n number of nodes, t  max legs of crab, m number of edges
for(i=0;i<2*m;i++)
{
    scanf("%ld",&v1);
    scanf("%ld",&v2);
    N[i][0]=v1;
    N[i][1]=v2;
    N[i][2]=1;
    NC[v1][0]++; // count based on row
    i++;
    N[i][0]=v2;
    N[i][1]=v1;
    N[i][2]=1;
}
// one head minimum
maxcount=0;
for(i=1;i<=t;i++)
{
    count=0;
    for(j=0;j<n;j++)
    {
        if(NC[j][0]>=i+1 && NC[j][1]!=0)
          {
            NC[j][1]=0;
            count+=t+1;
          }
     }
     if(count>maxcount)
            maxcount=count;    
    for(j=0;j<n;j++)
    {
                NC[j][1]=1;
    }
}
printf("%ld\n",maxcount);
}
return 0;
}
