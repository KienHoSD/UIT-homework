#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int64_t sochuso;
int xetsochuso(int64_t n){
    sochuso=0;
    while(n!=0){
        n/=10;
        sochuso++;
    }
    return sochuso;
}
int main(){
    int64_t tongchiphi=1;
    int64_t i=0;
    int64_t n;
    cin>>n;
    while(i<=n){
        tongchiphi+=xetsochuso(i);
        i+=10;
    }
    if(n-(n/10)*10!=0) tongchiphi+= xetsochuso(n);
    if(n==1)tongchiphi=1;
    cout<<tongchiphi;

}

