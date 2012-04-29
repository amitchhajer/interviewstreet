/*
this code reverses a matrix by 90 deg in place

1 2 3 4             3 9 5 1
5 6 7 8     -->     4 0 6 2
9 0 1 2             5 1 7 3
3 4 5 6             6 2 8 4


int a[4][4];
int n=4;
int tmp;
for (int i=0; i<n/2; i++){
        for (int j=i; j<n-i-1; j++){
                tmp=a[i][j];
                a[i][j]=a[j][n-i-1];
                a[j][n-i-1]=a[n-i-1][n-j-1];
                a[n-i-1][n-j-1]=a[n-j-1][i];
                a[n-j-1][i]=tmp;
        }
}
