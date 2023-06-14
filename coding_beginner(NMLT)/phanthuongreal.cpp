#include <iostream>
using namespace std;
int main(){
    int64_t a[100001],tongkbien[100001],k,n,vitri=0;
    cin>>n>>k;
    bool behon=true;
    int j,i;
    int64_t Min=100000000000;
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=k;i<=n;i++)
        for(j=i-k+1;j<=i;j++) tongkbien[i]+=a[j];
    int64_t Max=0;
    for(i=k;i<=n;i++){
        Max=0;
        bool behon=true;
        for(j=i+k;j<=n;j++){
            if(tongkbien[j]>tongkbien[i]){
                behon=false;
                break;
            }
            if(tongkbien[j]>Max) Max=tongkbien[j];
        }
        for(j=i-k;j>=1;j--){
            if(tongkbien[j]>tongkbien[i]){
                behon=false;
                break;
            }
            if(tongkbien[j]>Max) Max=tongkbien[j];
        }
        if(Max<=Min&&Max!=0&&behon==true) {
            Min=Max;
        }
    }
    cout<<Min;

}
