#include <iostream>
using namespace std;
int main(){
    int n;
    int f;cin>>n;
    f=(n%2==0)? 2:1;
    uint64_t tong=1;
    for(int i=f;i<=n;i+=2){
        tong*=i;
    }
    cout<<tong;
}
