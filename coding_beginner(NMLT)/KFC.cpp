#include <iostream>
using namespace std;
int main(){
    float K,F,C;
    cin>>F;
    C= (F-32)*5/9;
    K= (F-32)*5/9+273.15;
    cout<<C<<" "<<K;

}
