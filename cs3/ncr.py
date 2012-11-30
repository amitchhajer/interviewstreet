from math import factorial,floor
t = input();

for i in range (0, t):
    s = raw_input().split();
    n = long(s[0])
    r = long(s[1])
    c = n-r
    if(c>r):
        temp = r;
        r = c;
        c = temp
    num = den = 1
    for j in range(r+1, n+1):
        num = (num * j)
    for j in range(2, c+1):
        den = (den * j)
    print (num/den)%142857