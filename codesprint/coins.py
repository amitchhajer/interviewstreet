import math;
n=input();
for i in range(0,n):
    s=raw_input().split();
    a=long(s[0]);
    b=long(s[1]);
    o=(pow(2,a+1)-2)-(pow(2,b+1)-2);
    s=str(o)+'.00';
    print s;
    



