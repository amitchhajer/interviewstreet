#include<stdio.h>

int main()
{
   int a[4][4],count[4],i=0,j=0,sum=0,k;
      float count1[4],temp,max;
   char  can[4];
      scanf("\n%c\n%c\n%c\n%c",&can[0],&can[1],&can[2],&can[3]);
   
   for(i=0;i<4;i++)
     {
	    scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	 }
	 
   /*for(i=0;i<4;i++)
     {
	    printf("%d%d%d%d",a[i][0],a[i][1],a[i][2],a[i][3]);
	 }*/
	 
   for(j=0;j<4;j++)
     {
	    count[j]=0;
		for(i=0;i<4;i++)
		 {
		    count[j]+=a[j][i];
		 }
	 
	  }
	  for(i=0;i<4;i++)
	  {
	    sum+=count[i];
	    printf("\%d",count[i]);
	    }
	  
	  for(i=0;i<4;i++)
		{
		   count1[i]=(count[i]/(float)sum)*100;
		    printf("\n%c:%d%f",can[i],count[i],count1[i]);
		}
		max=count1[0];
		for (i=0;i<4;i++)
		   if(max<count1[i])
		     {
		      max=count1[i];
		      k=i;
		     }
		      
	  
	  printf("%c",can[k]);
}
