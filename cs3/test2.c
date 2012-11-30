#include<iostream>
using namespace std;
#include<vector>

int countFact(int n, int p)
{
    int k=0;
    while (n>=p)
    {
        k+=n/p;
        n/=p;
    }
    return k;
}

long long pow(int a, int b, int MOD=142857)
{
    long long x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

long long InverseEuler(int n, int MOD=142857)
{
    return pow(n,MOD-2,MOD);
}

long long factMOD(int n, int MOD)
{
    long long res = 1;
    while (n > 1)
    {
        long long cur = 1;
        for (int i=2; i<MOD; ++i)
            cur = (cur * i) % MOD;
        res = (res * pow(cur, n/MOD, MOD)) % MOD;
        for (int i=2; i<=n%MOD; ++i)
            res = (res * i) % MOD;
        n /= MOD;
    }
    return int (res % MOD);
}

long long C(int n, int r, int MOD=142857)
{
    if (countFact(n, MOD) > countFact(r, MOD) + countFact(n-r, MOD))
        return 0;

    return (factMOD(n, MOD) *
            ((InverseEuler(factMOD(r, MOD), MOD) *
            InverseEuler(factMOD(n-r, MOD), MOD)) % MOD)) % MOD;
}

int main()
{
  int n,r,m,t,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        cin>>r;
    if(i!=0)
      cout<<"\n";
    cout<<C(n,r,142857);
    }
}