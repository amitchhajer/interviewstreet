#include<stdio.h>

void main()
{
    int a,i;
    long c;
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%ld",&c);
        if((c%2==1 && (c/2)%2==0) || (c%4==0))
            printf("YES");
        else
            printf("NO");            
            
        printf("\n");    
    }
}
