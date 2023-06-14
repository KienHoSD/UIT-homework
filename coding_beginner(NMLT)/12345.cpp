
#include <iostream>
using namespace std;
struct PhanSo{
    int tuso,mauso;
};
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
void Rutgon(PhanSo &m){
    int d=gcd(m.tuso,m.mauso);
    m.tuso/=d;
    m.mauso/=d;
}
int main(){
    PhanSo m;
    cin>>m.tuso>>m.mauso;
    Rutgon(m);
    cout<<m.mauso<<m.tuso;

}
