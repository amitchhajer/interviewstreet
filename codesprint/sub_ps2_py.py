from collections import deque
t=input();
for i in range(0,t):
    n=input();
    a = [0] * n;
    b = [0] * n;
    f=deque();
    v=deque();
    j=0;
    s=0;
    a=raw_input().split();
    for str in raw_input().split():
        b[j]=long(str);
        if not f:
            f.append(a[j]);
            v.append(b[j]);
            s=s+b[j];
        else:
            m=f[-1];
            if m<a[j] :
                f.append(a[j]);
                v.append(b[j]);                
                s=s+b[j];
            else:
                st=0;
                li=0;
                lf=len(f);
                cnt=0
                for lt in range(li,lf):
                    if f[lt]>=a[j]:
                        st=+b[lt];
                        cnt=cnt+1;
                if st<b[j]:
                    while cnt :
                        f.pop();
                        v.pop();
                        cnt=cnt-1;
                    f.append(a[j]);
                    v.append(b[j]);
                    s=s-st;
                    s=s+b[j];
        j=j+1;
    s=0;
    while v:
        s=s+v.popleft();
    print s;

