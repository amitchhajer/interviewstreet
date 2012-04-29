#include<stdio.h>
#include<math.h>
void main()
{
    long double n=0.0,i=0.0,a=0.0,b=0.0,o=0.0;
    scanf("%Lf",&n);
    for(i=0;i<n;i++)
    {
        scanf("%Lf%Lf",&a,&b);
        o=(pow(2,a+1)-2)-(pow(2,b+1)-2);
        printf("%.2Lf\n",o);
    }
}
