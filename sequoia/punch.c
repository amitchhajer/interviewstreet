#include<stdio.h>

int punch(char arr[],int len)
{
    int i,min,adj,ind,adj2;
    
    for(i=1,min=4,adj=0,ind=-1;i<len-1;i++)
    {
           if(arr[i]!=0 && arr[i]<=min)
           {
              if(arr[i]==min)
              {                 
                adj2=0;
                if(!arr[i-1]) 
                    adj2++;
                if(!arr[i+1]) 
                    adj2++;
                if(adj2>adj)
                {
                    adj=adj2;
                    ind=i;
                }
              }  
              else   
              {  
                adj=0;
                ind=i;
                min=arr[i];
                if(!arr[i-1]) 
                    adj++;
                if(!arr[i+1]) 
                    adj++; 
              } 
                
           }
                                      
    }    
    //index 0;
    if(arr[0]<=min && arr[0]!=0)
    {
        adj2=1;
        if(!arr[1])
        adj2++;
        if(arr[0]==min)
        {
           
            if(adj2>adj)
               {
                adj=adj2;
                ind=0;
               }            
        }
        else
        {        
        ind=0;
        min=arr[0];
        adj=adj2;            
        }
    }
    //index len-1
    if(arr[len-1]<=min && arr[len-1]!=0)
    {
        adj2=1;
        if(!arr[len-2])
        adj2++;
        if(arr[len-1]==min)
        {
           
            if(adj2>adj)
               {
                adj=adj2;
                ind=len-1;
               }            
        }
        else
        {        
        ind=len-1;
        min=arr[len-1];
        adj=adj2;            
        }
    }
    
    return ind;
}

void main()
{
    int i,zero=0,len=0,index,p;
    char arr[100];    
    scanf("%s",arr);
    for(i=0,zero=0;arr[i];i++)
        {
            arr[i]-=48;            
            if(!arr[i])
                zero++;
        }
    len=i;    
    p=0;
    while(zero<len)
    {
        index=punch(arr,len);
        arr[index]=0;
        p++;        
        if(index==0)    
            {
                if(arr[index+1])
                   {                     
                        arr[index+1]--;
                    if(!arr[index+1]) 
                        zero++;
                   } 
             }
         else if(index==len)
            {   
                    if(arr[index-1])
                     {  
                            arr[index-1]--;
                        if(!arr[index-1]) 
                            zero++;
                     }   
             }
                   
          else
          {
            if(arr[index-1])
            {        arr[index-1]--;
                if(!arr[index-1]) 
                    zero++;        
            }        
            if(arr[index+1])
            {        arr[index+1]--;
                if(!arr[index+1]) 
                    zero++;       
             }        
        }
        zero++;        
    }
 printf("\n%d\n",p);   
}
