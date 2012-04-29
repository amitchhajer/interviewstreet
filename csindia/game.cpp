/* Enter your code here. Read input from STDIN. Print output to STDOUT */
#include<stdio.h>
void split (int &p1 ,int &p2)
{
	if(p2>5)
	{	p1=p2-5;
		p2=5;		
	}
else
if(p2>3)
{
	p1=p2-3;
	p2=3;
}
else
{
split(p2,p1);
}
}

int play(int p1,int p2,int ch)
{
		 while(p1+p2>5)
         {
                if(p1==1)
                {	
                        split(p2,p1);
                }
                if(p2==1)
                {	split(p1,p2);
                }
                else
                if(p1>p2)
                {
                        split(p2,p1);			
                }
                else
                {
                        split(p1,p2);
                }
                 ch=1-ch;         
         }
switch(p1+p2)
{
case 2:
case 4:return 1-ch;
break;
case 3:
case 5:return ch;
break;
default: return ch;
}
    return ch;
}

int main()
{
    int n;
    int p1,p2;
    int ch=0;
     scanf("%d",&n);
        while(n)
        {  scanf("%d",&p1);
           scanf("%d",&p2);
             if( play(p1,p2,0) )
             {
                 printf("Bob\n");
             }
             else
             {
                 printf("Alice\n");
             } 
              n--;
        }
    return 0;
}
