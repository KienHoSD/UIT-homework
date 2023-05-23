#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>
using namespace std;
int n;
long long a[1000001];
int main(){

    int64_t Mintong=0,Maxhieu=0,viTri1=0,viTri2=0;
    int64_t tong=0;
    int i;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    Mintong=a[1];
    Maxhieu=a[2];
    for(i=1;i<=n;i++){
        if(a[i]<=Mintong&&i%2!=0){
            Mintong=a[i];
            viTri1=i;
        }
        if(a[i]>=Maxhieu&&i%2==0){
            Maxhieu=a[i];
            viTri2=i;
        }
    }
    if(Maxhieu>Mintong){
        a[viTri1]=Maxhieu;
        a[viTri2]=Mintong;
    }
    for(i=1;i<=n;i++){
        if(i%2!=0)
            tong+=a[i];
        else
            tong-=a[i];
    }
    cout<<tong;


}
