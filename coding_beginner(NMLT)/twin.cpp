#include <iostream>
using namespace std;
int xetsonguyento(int i){
    for (int dem = 2; dem < static_cast<float>(i / 2); ++dem){
        if ((i % dem) == 0)
            return false;
    }
    return true;
}
int main(){
    int n;
    int dem = 0;
    cin>>n;
    for (int i = 5 ; i < n ; ++i){
        if ((xetsonguyento(i) == true) && (xetsonguyento(i-2)== true)){
            cout<<(i-2)<<", "<<i<<"\n";
            dem +=1;
        }
    }
    cout<<"Tong: "<<dem<<" cap so sinh doi < "<<n;
}
