#include <iostream>

int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
struct Phanso{
    int tuso,mauso;
};
void Nhap(Phanso &g){
    int a,b;
    std::cin>>a>>b;
    g.tuso=a;
    g.mauso=b;
}
void Rutgon(Phanso &g){
    int gcd_tuso_mauso = gcd(g.tuso,g.mauso);
    g.mauso/=gcd_tuso_mauso;
    g.tuso/=gcd_tuso_mauso;
}
void in_phanso(Phanso g){
    std::cout<<g.tuso<<" "<<g.mauso;
}
int main(){
    Phanso A;
    Nhap(A);
    Rutgon(A);
    in_phanso(A);
}
