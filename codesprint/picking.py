from math import factorial;
n=input();

for i in range(0,n):
    k=input();
    a = [0] * k;
    j=0;
    for str in raw_input().split():
        a[j]=long(str);
        j=j+1;
           
    a.sort();
    j=0;
    #for j in range(0,k-1):
    while j<k :
          #print long(a[j]);
          if j<long(a[j]):
              print '0';
              break;
          j=j+1;
    
    if j!=k:
       continue;
          
    f=1;
    t=k-1;
    while t>=0 :
        if t!=k-1 and long(a[t])==long(a[t+1]):
          t=t-1;
          continue;
        temp=t-long(a[t])+1;
        f=f%1000000007*factorial(temp%1000000007)%1000000007;
        t=t-1;
    print f;
