#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int64_t sochuso;
int xetsochuso(int64_t n){
    sochuso=1;
    while(n/10!=0){
        n/=10;
        sochuso++;
    }
    return sochuso;
}
int64_t muso(int64_t a,int b){
    for(int i=2;i<=b;i++)
        a*=10;
    if(b==0)
        return 1;
    return a;
}
int64_t sosomu(int64_t e,int64_t g,int64_t tongchiphi){
    for(int i=e;i>=2&&g>0;i--){
        if(i==e) tongchiphi+=e*muso(10,i-2)*((g/(muso(10,i-1)))-1);
        else tongchiphi+=e*muso(10,i-2)*(g/(muso(10,i-1)));
        g-=((g/muso(10,i-1))*muso(10,i-1));
    }
    return(tongchiphi);
}
int main(){
    int64_t tongchiphi=0;
    int64_t i=0;
    int64_t n;
    cin>>n;
    int64_t e=xetsochuso(n);
    if(e==5) tongchiphi=sosomu(e,n,3894);
    if(e==6) tongchiphi=sosomu(e,n,48895);
    if(e==7) tongchiphi=sosomu(e,n,588896);
    if(e==8) tongchiphi=sosomu(e,n,6888897);
    if(e==9) tongchiphi=sosomu(e,n,78888898);
    if(e==10)tongchiphi=sosomu(e,n,888888899);
    if(e==11) tongchiphi=sosomu(e,n,9888888900);
    if(e==12) tongchiphi=sosomu(e,n,108888888901);
    if(e==13) tongchiphi=sosomu(e,n,1188888888902);
    if(e<=4){
        while(i<=n){
            tongchiphi+=xetsochuso(i);
            i+=10;
        }
    }
    if(n-((n/10)*10)!=0) tongchiphi+= xetsochuso(n);
    if(n==1)tongchiphi=1;
    cout<<tongchiphi;
}

