#include<stdio.h>
#define FULL 999

int k;
int num[FULL];
int mat[FULL][FULL];
int parent[FULL];
int temp2=200;
int min;
int main()
{
	int p,q,r,s;
	char t;
	int temp;
	scanf("%d", &k);
	for(p=0;p<k;p++)
	{
		scanf("%d", &num[p]);
	}

	for(p=0;p<k;p++)
	{
		scanf("%c",&t);
		for(q=0;q<k;q++)
		{
			scanf("%c",&t);
			mat[p][q]=((t=='Y')?num[p]:FULL);
			if(p==q)
				mat[p][q]=num[p];
		}
		parent[p]=p;
	}

	for(p=0;p<k;p++)
	{
		temp=parent[p];
		for(q=p+1;q<k;q++) 			//compare each q with p only 1s
		{
				if(parent[q]==q)	//moved elseware
				{
					for(r=0;r<k;r++) //compare
					{
						if(mat[r][temp]==mat[r][q]&&mat[r][temp]!=FULL)//same
						{
							for(s=0;s<k;s++)//copy
							{
								if(mat[s][q]!=FULL)
									mat[s][temp]=mat[s][q];
							}
							parent[q]=temp;
							r=k;
						}
					}
				}
		}
	}
	for(p=0;p<k;p++)
	{
		temp = parent[p];
		temp2 = FULL;
		for(q=0;q<k;q++)
		{
			if(temp2>mat[q][temp])
			{
				temp2=mat[q][temp];
				min=q;
			}
		}
		mat[min][temp]=FULL;
		printf("%d ",temp2);
	}
	return 0;
}