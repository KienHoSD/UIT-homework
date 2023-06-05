#include <iostream>
#include "CDate.h"
#include "CDate.cpp"
int main(){
    int ngay1,ngay2,thang1,thang2,nam1,nam2,ngay;
    std::cout<<"Nhap ngay a :"; std::cin>>ngay1>>thang1>>nam1;
    CDate a(ngay1,thang1,nam1);
    CDate b(1,1,1);
    std::cout<<"Nhap ngay b :\n"; b.Nhap();
    std::cout<<"So ngay cach nhau cua a va b :"<<a.so_ngay_cach_nhau(b)<<"\n";
    b.them_1_ngay();a.them_1_ngay();
    std::cout<<"Ngay cua a sau khi them 1 ngay la :";a.Xuat();
    std::cout<<"Ngay cua b sau khi them 1 ngay la :";b.Xuat();
    b.tru_1_ngay();a.tru_1_ngay();
    std::cout<<"Ngay cua a sau khi bot 1 ngay la :";a.Xuat();
    std::cout<<"Ngay cua b sau khi bot 1 ngay la :";b.Xuat();
    std::cout<<"Nhap so ngay muon them vao a va b :";std::cin>>ngay;
    b.Cong(ngay);a.Cong(ngay);
    std::cout<<"Ngay cua a sau khi them vao "<<ngay<<" ngay la :";a.Xuat();
    std::cout<<"Ngay cua b sau khi them vao "<<ngay<<" ngay la :";b.Xuat();
    std::cout<<"Nhap so ngay muon bot ra a va b :";std::cin>>ngay;
    b.Tru(ngay);a.Tru(ngay);
    std::cout<<"Ngay cua a sau khi bot ra "<<ngay<<" ngay la :";a.Xuat();
    std::cout<<"Ngay cua b sau khi bot ra "<<ngay<<" ngay la :";b.Xuat();
}
