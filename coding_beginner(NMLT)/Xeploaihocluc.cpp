#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    float a,b,c;
    cin>>a>>b>>c;
    float diemtrungbinh=(a+b+c)/3;
    cout<<setprecision(2)<<fixed<<"DTB = "<<diemtrungbinh<<endl<<endl<<"Loai: ";
    if(diemtrungbinh>=9) cout<<"XUAT SAC";
    else if(diemtrungbinh>=8) cout<<"GIOI";
    else if(diemtrungbinh>=7) cout<<"KHA";
    else if(diemtrungbinh>=6) cout<<"TB KHA";
    else if(diemtrungbinh>=5) cout<<"TB";
    else if(diemtrungbinh>=4) cout<<"YEU";
    else cout<<"KEM";
}
