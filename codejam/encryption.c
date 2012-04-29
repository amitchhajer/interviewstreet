#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    char str[81];
    int maxc,maxr,len,i,j;
    gets(str);
    len=strlen(str);
    maxr=sqrt(len);
    maxc=ceil((float)len/maxr);
    while(abs(maxr-maxc)>1)
    {
    maxr++;
    maxc--;
    } 
   //printf("%d%d",maxr,maxc);
   for(i=0;i<maxc;i++)
   {
    j=i;
    while(j<len)
    {
        printf("%c",str[j]);
        j+=maxc;
    }
    printf(" ");
    
   }
   
    return 0;

}
