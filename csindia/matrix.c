#include<stdio.h>
typedef struct mybit
{
 int a:1;
}mat;

int test(mat x[800][800],mat y[800][800],mat z[800][800],int an)
{
mat r[800][800];
 
        int i,j,k;
        for(i=0;i<an;i++)
        {
          for(j=0;j<an;j++)
           {  
             r[i][j].a=0;
             for(k=0;k<an;k++)
            {
              r[i][j].a+=x[i][k].a*y[k][j].a;             
            } 
         if(!((r[i][j].a>0 && z[i][j].a>0)||(z[i][j].a==0 && r[i][j].a==0)))
             return 0;
        }
        }
return 1;            
}
void disp(int a[800][800],int n)
{
int i,j;
    for(i=0;i<n;i++)
           {for(j=0;j<n;j++)
               printf("%d",a[i][j]);
           }
}
int main()
{
    int n=0;
    mat mat1[800][800],mat2[800][800],mat3[800][800];
    int an=0;
    char ck[5];
    int i=0,j=0;
     scanf("%d",&n);
        while(n)
        {  scanf("%d",&an);
           for(i=0;i<an;i++)
           {for(j=0;j<an;j++)
               scanf("%d",&mat1[i][j].a);
           }
         
            for(i=0;i<an;i++)
           {
           for(j=0;j<an;j++)
               scanf("%d",&mat2[i][j].a);
           }
         
         for(i=0;i<an;i++)
           {for(j=0;j<an;j++)
               scanf("%d",&mat3[i][j].a);
           }
         if(test(mat1,mat2,mat3,an))
             {printf("yes\n");
             }
         else
         {printf("no\n");
         }
            n--;
        }
    return 0;
}
