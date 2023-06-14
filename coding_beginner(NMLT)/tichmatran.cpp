#include <bits/stdc++.h>
#define MAX 400
using namespace std;
void nhapmang(float a[][MAX],int m, int n){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }
}
void tinhtich(float a[][MAX],float b[][MAX],float c[][MAX],int m, int n, int k){
    for(int i=1;i<=m;i++)
        for(int j=1;j<=k;j++)
            for(int e=1;e<=n;e++)
                c[i][j]+=a[i][e]*b[e][j];

    for(int i=1;i<=m;i++){
        for(int j=1;j<=k;j++)
            cout<<c[i][j]<<" ";
        cout<<endl;
    }
}
int main(){
    float a[MAX][MAX];
    float b[MAX][MAX];
    float c[MAX][MAX];
    int m,n,k;
    cin>>m>>n;
    nhapmang(a,m,n);
    cin>>n>>k;
    nhapmang(b,n,k);
    tinhtich(a,b,c,m,n,k);
}
