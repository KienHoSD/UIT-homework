#include <iostream>
#include <math.h>
using namespace std;
int main(){
    string n;
    cin>>n;
    int64_t dodaixaun=n.length();
    for(int64_t i=0;i<dodaixaun-1;i++){
        if(n[i]-'0'>n[i+1]-'0'){
            n.erase(n.begin()+i);
            break;
        }
    }
    if(dodaixaun==n.length()){
        n.erase(n.begin()+(dodaixaun-1));
    }
    for(int i=0;i<=dodaixaun;i++);
        if(n[0]=='0')
            n.erase(n.begin());
    cout<<n;

}
