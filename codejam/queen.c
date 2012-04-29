// Can Queen Attack
#include<stdio.h>
#include<math.h>

int canAttack(int i,int j,int x,int y)
{
    if(i==x||j==y||abs(i-j)==abs(x-y))
	    return 1;
    return 0;
}
int main()
{
int n=0,i,j,x,y;

//while(n)
{
	scanf("%d%d",&i,&j);
	scanf("%d%d",&x,&y);
	if(canAttack(i,j,x,y))
	{	
		printf("ATTACKING");
	}
	else
	{
		printf("NON ATTACKING");
	}
	n--;
}
return 0;
}
