//saddle point
#include<stdio.h>
void saddle(int a[][5],int m ,int n)
{
int i=0,min=0,max=0,j=0,k=0;
for(i=0;i<m;i++)
{
min=a[i][0];
k=0;	
for(j=0;j<n;j++)	
	{
		if(a[i][j] < min)
		{	min=a[i][j];
			k=j;
		}
	}
	for(j=0;j<m;j++)
	{	if(a[j][k]>min)
			break;
	}
	if(j==m)
	{
		printf("%d",min);
		return;
	}
}
printf("NO SADDLE POINT");
}

main()
{int m=5,n=5;
int a[5][5];
int i=0;
for(i=0;i<m;i++)
{	
 scanf("%d%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3],&a[i][4]);
}
saddle(a,m,n);
return 0;
}

