#include<stdio.h>
int main()
{
int test=0,v1=0,v2=0,j=0,m=0,t=0,n=0,i=0,count=0,maxcount=0,k=0,kc=0,ct=0,at=0;
int N[50][50]={0,0}; // shoud make a sparse matrix
int NN[100]={0};
//long NC[100][2]={0,1};
scanf("%d",&test);

for(k=0;k<test;k++)
{
scanf("%d%d%d",&n,&t,&m); // n number of nodes, t  max legs of crab, m number of edges
for(i=0;i<m;i++)
{
    scanf("%d",&v1);
    scanf("%d",&v2);
    N[v1][v2]=N[v2][v1]=1;
}
// one head minimum
maxcount=0;
for(i=2;i<=t;i++)       //range of legs
{
    count=0;
    for(j=1;j<n;j++)    //check all row
    {
        ct=0;
        if(N[j][0]==0)          
        {
            for(kc=1;kc<n;kc++)         //check column
            {
              if(N[0][kc]==0)
              {
                 if(N[j][kc]==1)
                   {
                        ct++;
                        NN[kc]=1;
                        if(ct>=i)
                        {
                          count+=i+1;
                          N[j][0]=1;
                          N[0][j]=1;
                          for(at=0;at<n;at++)
                          {
                            if(NN[at]==1)
                              N[at][0]=N[0][at]=1;
                              
                          }
                          break;                                        
                        }
                   }
              }
            }
            
        }
     }
     for(at=0;at<n;at++)
    {
                N[at][0]=N[0][at]=0;
                NN[at]=0;
                
    }
     
        if(count>maxcount)
           maxcount=count;    
    
}
printf("%d\n",maxcount);
}
return 0;
}
