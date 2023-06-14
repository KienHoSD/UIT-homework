#include <iostream>
using namespace std;
int main(){
    int a,b,n;
    int songuyen=0;
    cin>>a>>b>>n;
    for(int i=1;i<=n;i++){
        songuyen+=a*b;
        a++;
        b++;
    }
    cout<<songuyen;
}
