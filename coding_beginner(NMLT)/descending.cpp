#include <iostream>
#include <fstream>
using namespace std;
int main(){
    int a[100001];
    int64_t tongkbien[100001];
    int k,n;
    int64_t j,i;
    int64_t Min=1000000000000000;
    int64_t Max=0;
    int64_t Lonnhat;
    int vitri,vitris[10001];
    bool behon=true;
    ifstream ifs("test.txt");
    ifs>>n>>k;
    int e=k;
    for(i=1;i<=n;i++) ifs>>a[i];
    for(i=k;i<=n;i++)
        for(j=i-k+1;j<=i;j++) tongkbien[i]+=a[j];
    for(i=k;i<=n;i++){ //kiểm vị trí từ cao xuống thấp
        Max=0;
        behon=true;
        for(j=i+k;j<=n;j++){
            if(tongkbien[j]>tongkbien[i]){
                behon=false;
                break;
            }
            if(tongkbien[j]>Max) Max=tongkbien[j];
        }
        for(j=i-k;j>=k;j--){
            if(tongkbien[j]>tongkbien[i]){
                behon=false;
                break;
            }
            if(tongkbien[j]>Max) Max=tongkbien[j];
        }
        if(Max<=Min&&Max!=0&&behon==true) Min=Max;
    }
    cout<<Min;
}
