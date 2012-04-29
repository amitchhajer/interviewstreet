#include<stdio.h>
#include<math.h>
long fact(long n)
{
    long k;
    if(n==0)
    return(1);
    else
    {
        k=(n*fact(n-1))%1000000007;
    }
    return(k);
}
int main()
{
long n=0,array[50000],i=0,temp=0,j=0,test=0,k=0,f=1;
scanf("%ld",&test);
for(k=0;k<test;k++)
{
scanf("%ld",&n);

for(i=0;i<n;i++)
{
    scanf("%ld",&array[i]);
}
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(array[i]<array[j])
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
              }
          }
    }

        for(i=0;i<n;i++)
        {
            if(i<array[i])
            {
                printf("0");
                break;
            }
                        
        }
if(i!=n)
continue;

f=1;
for(i=n-1;i>=0;i--)
{

    if(i!=n-1 && array[i]==array[i+1])
        continue;
    
    temp=i-array[i]+1;
    f=f%1000000007*fact(temp%1000000007)%1000000007;
}
printf("%ld\n",f%1000000007);
}
return 0;
}               

