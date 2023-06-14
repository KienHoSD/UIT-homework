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
    while (true){
        std::cin>>a;
        std::cin>>b;
        if(b!=0) break;
        std::cout<<"mau so phai khac 0!\nNhap lai tu so va mau so hop le: ";
    }
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
    else std::cout<<g.tuso<<"/"<<g.mauso;
}
Phanso toancong(Phanso a,Phanso b){
    Phanso temp;
    temp.tuso=a.tuso*b.mauso+b.tuso*a.mauso;
    temp.mauso=a.mauso*b.mauso;
    return temp;
}
Phanso toantru(Phanso a,Phanso b){
    Phanso temp;
    temp.tuso=a.tuso*b.mauso-b.tuso*a.mauso;
    temp.mauso=a.mauso*b.mauso;
    return temp;
}
Phanso toannhan(Phanso a,Phanso b){
    Phanso temp;
    temp.tuso=a.tuso*b.tuso;
    temp.mauso=a.mauso*b.mauso;
    return temp;
}
Phanso toanchia(Phanso a,Phanso b){
    Phanso temp;
    temp.tuso=a.tuso*b.mauso;
    temp.mauso=a.mauso*b.tuso;
    return temp;
}
void tinhtoan(Phanso a,Phanso b){
    Phanso temp;
    Rutgon(temp = toancong(a,b));
    std::cout<<"Tong cua phan so a va b la:"; in_phanso(temp);
    std::cout<<"\n";
    Rutgon(temp = toantru(a,b));
    std::cout<<"Hieu cua phan so a va b la:"; in_phanso(temp);
    std::cout<<"\n";
    Rutgon(temp = toannhan(a,b));
    std::cout<<"Tich cua phan so a va b la:"; in_phanso(temp);
    std::cout<<"\n";
    Rutgon(temp = toanchia(a,b));
    std::cout<<"Thuong cua phan so a va b la:"; in_phanso(temp);
}
int main(){
    Phanso A,B;
    std::cout<<"Nhap tu so va mau so a:"; Nhap(A);
    std::cout<<"Nhap tu so va mau so b:"; Nhap(B);
    tinhtoan(A,B);
}
