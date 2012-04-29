#include<iostream>
using namespace std;
#include<math.h>
/*
1 <= N <= 20,000
1 <= Q <= 20,000
4 <= Mi <= 20
Each co-ordinate would have a value of atmost 200,000 
*/
int main()
{   long poly[20000][2]={-1,-1},N=0,query[20000][4]={-1,-1,0,0},Q=0,TQ=0,temp[20000]={0},tc=0,tempq[20000]={0},tqc=0;
    int min_x_q=0,min_x_p=0,max_x_q=0,max_x_p=0,min_y_q=0,min_y_p=0,max_y_q=0,max_y_p=0;
    long i=0,j=0,ti=0;
    cin>>N;
    cin>>TQ;
    for(i=0;i<N;i++)
    {
        cin>>poly[i][0];    //take scatter points
        cin>>poly[i][1];
        
        if(min_x_p>poly[i][0])
            min_x_p=poly[i][0];
        if(min_y_p>poly[i][1])
            min_y_p=poly[i][1];
        if(max_x_p<poly[i][0])
            max_x_p=poly[i][0];
        if(max_y_p<poly[i][1])
            max_y_p=poly[i][1];
            
    }
    for(i=0;i<TQ;i++)       //take query poly
    {
        cin>>Q;
        int qi=0;
        for(j=0;j<Q;j++)
        {   int qx=0,qy=0;
            cin>>qx;       
            cin>>qy;       
             if(qi!=0 && (qx-query[qi-1][0])!=0)          //include all intermediate points
             {  int li=0,lm=0,J=qy;
                int step=0;
                if(qx-query[qi-1][0]>0)
                {
                    step=1;
                }
                else
                {
                    step=-1;
                }
                li=query[qi-1][0]+step;
                lm=qx;
                ti=li;
                while(ti!=lm)
                {   int spcl=0;    
                    for(spcl=0;spcl<N;spcl++)
                    {
                        if(poly[spcl][0]==ti && poly[spcl][1]==J)
                            break;
                    }
                    if(spcl!=N)
                        query[qi][3]=1;
                       
                       query[qi][0]=ti;
                       query[qi++][1]=J;
                       ti=ti+step;
                }                
             }
             else
             if(qi!=0 && (qy-query[qi-1][1])!=0)
             {  int li=0,lm=0,X=qx;
                int step=0;
                if(qy-query[qi-1][1]>0)
                {
                    step=1;
                }
                else
                {
                    step=-1;
                }
                li=query[qi-1][1]+step;
                lm=qy;
                ti=li;
                while(ti!=lm)
                {      
                int spcl=0;    
                    for(spcl=0;spcl<N;spcl++)
                    {
                        if(poly[spcl][1]==ti && poly[spcl][0]==X)
                            break;
                    }
                    if(spcl!=N)
                        query[qi][3]=1;

                       query[qi][1]=ti;
                       query[qi][2]=1;                       
                       query[qi++][0]=X;
                       ti+=step;
                }                
             }
             int spcl=0;    
                    for(spcl=0;spcl<N;spcl++)
                    {
                        if(poly[spcl][1]==qy && poly[spcl][0]==qx)
                            break;
                    }
                    if(spcl!=N)
                        query[qi][3]=1;

             query[qi][0]=qx;
             query[qi][1]=qy;
             query[qi][2]=1;
             if(min_x_q>query[qi][0])
                min_x_q=query[qi][0];
            if(min_y_q>query[qi][1])
                min_y_q=query[qi][1];
            if(max_x_q<query[qi][0])
                max_x_q=query[qi][0];
            if(max_y_q<query[qi][1])
                max_y_q=query[qi][1];
             qi++;   

        }
        
        //cover first and last
              if(qi!=0 && (query[0][0]-query[qi-1][0])!=0)          //include all intermediate points
             {  int li=0,lm=0,J=query[0][1];
                int step=0;
                
                if(query[0][0]-query[qi-1][0]>0)
                {
                    step=1;
                }
                else
                {
                    step=-1;
                }
                li=query[qi-1][0]+step;
                lm=query[0][0];
                ti=li;
                while(ti!=lm)
                {      int spcl=0;    
                    for(spcl=0;spcl<N;spcl++)
                    {
                        if(poly[spcl][0]==ti && poly[spcl][1]==J)
                            break;
                    }
                    if(spcl!=N)
                        query[qi][3]=1;

                        query[qi][0]=ti;
                       query[qi++][1]=J;
                       ti=ti+step;
                }                
             }
             else
             if(qi!=0 && (query[0][1]-query[qi-1][1])!=0)
             {  int li=0,lm=0,X=query[0][0];
                int step;
                if(query[0][1]-query[qi-1][1]>0)
                {
                    step=1;
                }
                else
                {
                    step=-1;
                }
                li=query[qi-1][1]+step;
                lm=query[0][1];
                ti=li;
                while(ti!=lm)
                {      int spcl=0;    
                    for(spcl=0;spcl<N;spcl++)
                    {
                        if(poly[spcl][1]==ti && poly[spcl][0]==X)
                            break;
                    }
                    if(spcl!=N)
                        query[qi][3]=1;

                        query[qi][1]=ti;
                        query[qi][2]=1;
                       query[qi++][0]=X;
                       ti+=step;
                }                
             }        
 /*       for(int k=0;k<qi;k++)
        {
            cout<<"\n("<<query[k][0]<<","<<query[k][1]<<","<<query[k][2]<<")";
        }       
   */     
        
        int count=0;
        for(int y=min_y_q+1;y<max_y_q;y++)
        {
            tc=0;
            for(int k=0;k<N;k++)
            {
                if(poly[k][1]-y==0)             //shift x-axis
                {
                    temp[tc++]=poly[k][0];      //store Points on shifted axis
                }
            }
            tqc=0;
            for(int k=0;k<qi;k++)
            {
                //cout<<"\ny"<<y<<"("<<query[k][0]<<","<<query[k][1]<<","<<query[k][2]<<")";
                if(query[k][1]-y==0 && query[k][2]==1)             //shift x-axis
                {
                    tempq[tqc++]=query[k][0];      //store Points on shifted axis
                }
            }
            //cout<<"\ntqc:"<<tqc;
            for(int si=0;si<tqc-1;si++)             //store sorted x of query
            {   if(tempq[si]>tempq[si+1])
                {   
                    int stemp=tempq[si];
                    tempq[si]=tempq[si+1];
                    tempq[si+1]=stemp;
                    if(si!=0)
                        si-=2;
                }    
            }
            /*
            for(int k=0;k<tqc;k++)
            {
                cout<<"\n"<<tempq[k];
            }
              */          
            for(int k=0;k<tqc;k+=2)
            {   int si=0;
                for(si=0;si<qi;si++)                            //find edge
                {   if(query[si][0]==tempq[0] && query[si][1]==y)
                        break;
                }
                if(query[(si+1)%qi][1]==y||query[(si-1)%qi][1]==y)              //check if first line is original line
                {   k++;
                }
                int ci=tempq[k]+1;
                if(tqc-k>1)                         //if even intersection
                {   
                    while(ci<tempq[k+1])
                    {       int it=0;
                            for(it=0;it<tc;it++)
                            {
                                if(temp[it]==ci)
                                    break;
                            }
                            if(it!=tc)
                                count++;
                            ci++;
                    }
                }
                else
                if(tqc-k==1)                        //if odd intersection,then last
                {   ci=tempq[k-1]+1;
                    while(ci<tempq[k])
                    {       int it=0;
                            for(it=0;it<tc;it++)
                            {
                                if(temp[it]==ci)
                                    break;
                            }
                            if(it!=tc)
                                count++;
                            ci++;
                    }
                
                }
                //}
            }   
        }
        int bc=0,spcl=0;    
        for(spcl=0;spcl<qi;spcl++)
        {
            if(query[spcl][3]==1)
                bc++;
        }

    cout<<"\n"<<count+bc;
     }
   
return 0;
}
