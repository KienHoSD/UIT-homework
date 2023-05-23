#include <bits/stdc++.h>
using namespace std;
double tinhpi(int n){
    double tong=0;
    for(int i=0;i<=n;i++) tong+=pow(-1,i)/((2*i)+1);
    return 4*tong;
}
int main(){
    int n;cin>>n;
    cout<<tinhpi(n)<<" ";
}
