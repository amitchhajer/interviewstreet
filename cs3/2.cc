#include<iostream>
using namespace std;
void solut();
int R;
int n,m,k;
struct inp {
    short int i;
    short int j;
    int c;
}sinp[2000000],temp;
void stac(int position)
{
    int small = sinp[position].c;
    int i,flag = position;
    for(i = position+1;i <= m;i++) {
        if(small > sinp[i].c) {
            small = sinp[i].c;
            flag=i;
        }
    }
    temp = sinp[flag];
    sinp[flag] = sinp[position];
    sinp[position] = temp;
}
void solut()
{
    int x, cost=0, node = n, p=1, p1,p2, over[2100]={0};
    while(k < node && p <= m) {
        stac(p);
        p1 = over[sinp[p].i];
        p2 = over[sinp[p].j];
        if(p1!=0 && (p1 == p2));

        else {
        if(p1 == 0 && p2 == 0) {
            over[sinp[p].i] = sinp[p].i;
            over[sinp[p].j] = sinp[p].i;
            node--;
        }
        else if(p1 == 0) {
            over[sinp[p].i]=p2; node--;
        }
        else if(p2==0) {
            over[sinp[p].j]=p1; node--;
        }
        else {
            node--;
            for(x = 1;x <= n; x++) {
                if(over[x] == p2)
                    over[x] = p1;
            }
        }
            cost += sinp[p].c;
        }
        p++;
    }
    if(k >= node)
        cout<<cost<<"\n";
    else
        cout<<"Impossible!\n";
}

int main()
{
    int p,q;
    cin>>R;
    for(q=1;q<=R;q++) {
        cin>>n>>m>>k;
        for(p=1;p<=m;p++)
            cin>>sinp[p].i>>sinp[p].j>>sinp[p].c;
        if(k>=n)
            cout<<"0\n";
        else if(k==0)
            cout<<"Impossible!\n";
        else
            solut();
    }
    return 0;
}