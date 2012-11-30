from itertools import izip
t = input();
for i in range (0, t):
    s = raw_input().split();
    n = long(s[0])%142857
    r = long(s[1])%142857
    x = reduce(lambda x, y: x * y[0] / y[1], izip(xrange(n - r + 1, n+1), xrange(1, r+1)), 1) % 142857
    print x