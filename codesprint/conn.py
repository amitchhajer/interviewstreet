n=input();
for i in range(0,n):
    k=input();
    a = [0] * k;
    b = [0] * k;
    j=0;
    #    
    a=raw_input().split();
    b=raw_input().split();
    t=k-1;
    r=0;
    while t>0 :
        y=t-1;
        while y>=0 :
              temp=abs(long(a[t])-long(a[y]));
              if long(b[t])>long(b[y]):
                r=r+temp*long(b[t]);
              else:
                r=r+temp*long(b[y]);
              
              y=y-1;
        t=t-1;
    print r%1000000007;
    
    
    #for str in raw_input().split():
    #    a[j]=long(str);
    #    j=j+1;
    #j=0;   
    #for str in raw_input().split():
    #    b[j]=long(str);
    #    j=j+1;

