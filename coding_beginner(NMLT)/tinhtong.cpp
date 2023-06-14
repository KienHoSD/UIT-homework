#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,x,j;
    bool checking=false;
    int hieu;
    int a[100001];
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    cin>>x;
    for(i=1;i<=n-1;i++){
        hieu=x-a[i];
        for(j=i+1;j<=n;j++)
           if(a[j]==hieu){
            checking=true;
            cout<<"YES";
            break;
           }
        if(checking==true) break;
    }
    if(checking==false)cout<<"NO";
}
