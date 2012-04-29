/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include<iostream>
using namespace std;
int main()
{
    int test=0;
    cin>>test;
    for(int k=0;k<test;k++)
    {   int v1=0,v2=0,j=0,m=0,t=0,n=0,i=0,count=0,maxcount=0,kc=0,ct=0;//,at=0;
        int N[50][50]={0,0}; // shoud make a sparse matrix
        int NN[100]={0};
        int flag=0;
        
        flag=0;
        cin>>n>>t>>m; // n number of nodes, t  max legs of crab, m number of edges
        for(i=0;i<m;i++)
        {
            cin>>v1;
            cin>>v2;
            N[v1][v2]=N[v2][v1]=1;
        }
        // one head minimum
        maxcount=0;
        for(i=2;i<=t;i++)       //range of legs
        {
            count=0;
            int row=-1;
            int rowct=-1;
            flag=0;
            int checkleg=i;
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
                                    
                               }
                          }
                    }
                }
                if(ct==checkleg)
                {     //cout<<i+1;
                      count+=i+1;
                      N[j][0]=1;
                      N[0][j]=1;
                     for(int rst=0,rsi=0;rst<ct;rsi++)
                     {
                        if(N[j][0]==0&&N[0][rsi]==0&&N[j][rsi]==1)
                        {   rst++;
                            N[j][0]==1;
                            N[0][rsi]==1;                            
                        }
                     }
                     // NN[at]=0;                      
                      flag=1;
                }
                else
                {   if(row==-1||ct>i && rowct>ct)
                    {    row=j;
                         rowct=ct;
                    }
                }                
                if(j==n-1 && flag==0)
                {
                    j=row-1;
                    checkleg=ct;
                    row=rowct=-1;
                }
            }
            if(count>maxcount)
                     maxcount=count;    
        }
        cout<<maxcount;
    }
return 0;
}
