#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int f1,f2,fn=1;
    f1=1,f2=1;
    for(int i=3;i<=n;i++){
        fn=f1+f2;
        f2=f1;
        f1=fn;
    }
    cout<<fn;
}
