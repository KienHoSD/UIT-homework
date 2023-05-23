#include <bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long n,L;
    cin>>n>>L;
    unsigned long long m =1000000007;
    unsigned long long dientich=L*L;
    unsigned long long tong=0;
    for(int i=n;i>=0;i--){
        tong=tong+dientich;
        dientich=(dientich*4);
    }
    cout<<tong%m;
}
