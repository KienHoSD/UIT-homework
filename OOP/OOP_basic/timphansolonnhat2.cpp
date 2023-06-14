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
    if(g.tuso==0) std::cout<<0;
    else if(g.tuso%g.mauso==0) std::cout<<g.tuso/g.mauso;
    else if(g.mauso<0&&g.tuso<0) std::cout<<abs(g.tuso)<<"/"<<abs(g.mauso);
    else if(g.mauso<0&&g.tuso>0) std::cout<<"-"<<g.tuso<<"/"<<abs(g.mauso);
    else
        std::cout<<g.tuso<<"/"<<g.mauso;
}
void in_phanso_lonnhat(Phanso a,Phanso b){
    std::cout<<"Phan so lon nhat la:";
    if((a.tuso*b.mauso-a.mauso*b.tuso)>=0) in_phanso(a);
    else in_phanso(b);
}
int main(){
    Phanso A,B;
    std::cout<<"Nhap tu so va mau so a:"; Nhap(A);
    std::cout<<"Nhap tu so va mau so b:"; Nhap(B);
    in_phanso_lonnhat(A,B);
}
