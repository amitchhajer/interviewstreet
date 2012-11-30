from math import factorial,floor
t = input();

for i in range (0, t):
    s = raw_input().split();
    n = floor(long(s[0]))
    r = floor(long(s[1]))
    n0 = n % 142857
    r0 = r % 142857
    print ((factorial(n)/(factorial(r)*factorial(n-r))) * (factorial(n0)/(factorial(r0)*factorial(n0-r0))))%142857