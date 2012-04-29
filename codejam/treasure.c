//Treasure hunt
#include<stdio.h>
typedef struct pos 
{
    int x, y;
}pos;
#define MAXR 5
#define MAXC 5

int main()
{
int m=5,n=5;
int a[5][5];
int b[25];
int i=0,j=0,ri=0;
for(i=0;i<m;i++)
{	
 scanf("%d%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
}

i=0,j=0;
while(a[i][j]!=(i+1)*10+(j+1))
{
//b[ri]=a[i][j];
b[ri]=(i+1)*10+(j+1);
ri++;
m=a[i][j];
j=m%10-1;
i=m/10-1;
}
if(a[i][j]==(i+1)*10+(j+1))
{
    b[ri]=(i+1)*10+(j+1);
    ri++;
}
if(a[i][j]==(i+1)*10+(j+1))
{
for(i=0;i<ri;i++)
	printf("%d %d\n",b[i]/10,b[i]%10);
}
else
{
	printf("NO TREASURE");
}
return 0;
}
