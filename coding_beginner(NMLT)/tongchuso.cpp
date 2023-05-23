#include <iostream>
#include <strings.h>
using namespace std;
int main(){
    string n;
    int tong=0,i;
    cin>>n;
    for(i=1;i<=n.length();i++){
        tong+=(n[i-1]-48);
    }
    cout<<tong;
}
