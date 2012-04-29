/*
Simple Program for string reverse
*/
#include<stdio.h>
#include<string.h>
void stringReverse(char st[])
{
char temp;
int i;
    for(i=0;i<strlen(st)/2;i++)
    {
        temp=st[i];
        st[i]=st[strlen(st)-i-1];
        st[strlen(st)-i-1]=temp;
    }
}
int main()
{
char str[]="Hello";
printf("%s",str);
stringReverse(str);
printf("%s",str);
}
