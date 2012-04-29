#include<stdio.h>
#include<math.h>
int main()
{
    long n=0,i=0,temp=0,j=0,y=0,c=0;
    long a[200000],b[200000];
    unsigned long long r=0;
    scanf("%ld",&n);
    for(i=0;i<n;i++)
    {   scanf("%ld",&c);
        for(j=0;j<c;j++)
        {
            scanf("%ld",&a[j]);
        }
        r=0;     
        for(j=0;j<c;j++)
        {
            scanf("%ld",&b[j]);
            y=0;
            while (y<j)
            {
              temp=abs(a[j]-a[y]);
              if (b[j]>b[y])
                r=(r+temp*b[j])%1000000007;
              else
                r=(r+temp*b[y])%1000000007;
              y=y+1;
             }
        }
        printf("\n%llu",r);   
   }
return 0;
}
