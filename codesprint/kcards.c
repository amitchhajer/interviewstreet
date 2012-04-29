#include<iostream>
using namespace std;
int main()
{
       int test;
       cin>>test;
       int counter,count1,j;
       for(j=0;j<test;j++)
       {
       cin>>counter;
       long long answer;
       int passes;
       int i;
       int a[50000]={0};
       int temp;
       for(i=0;i<counter;i++)
       {
               cin>>temp;
               a[temp]++;
       }
       count1=counter;
       passes=0;
       answer=1;
       do
       {
               if(a[passes]==0)
               {
                       answer=0;
                       count1=1;
               }
               else
               {
                       answer*=a[passes];
                       a[passes+1]+=(a[passes]-1);
               }
               passes++;
               count1--;
               answer%=1000000007;
       }while(count1);
       cout<<answer%1000000007<<"\n";
       }
return 0;
}
