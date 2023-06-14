#include <iostream>
#include "CDate.h"
bool isLeap(int year){
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}
bool kiem_tra_ngay(int d, int m, int y){
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > 31)
        return false;
    if (m == 2){
        if (isLeap(y))
        return (d <= 29);
        else
        return (d <= 28);
    }
    if (m == 4 || m == 6 || m == 9 || m == 11)
        return (d <= 30);
    return true;
}
CDate::CDate(int d,int m,int y){
    while (!kiem_tra_ngay(d,m,y)){
        std::cout<<"Ngay khong hop le!\nVui long nhap lai :";
        std::cin>>d>>m>>y;
    }
    ngay=d,thang=m,nam=y;
}
void CDate::Nhap(){
    std::cout<<"Nhap ngay :";std::cin>>ngay;
    std::cout<<"Nhap thang :";std::cin>>thang;
    std::cout<<"Nhap nam :";std::cin>>nam;
}
void CDate::Xuat(){
    std::cout<<ngay<<"/"<<thang<<"/"<<nam<<"\n";
}

int CDate::so_ngay_cach_nhau(CDate other){
    int demngay=0;
    CDate temp1=*this;
    CDate temp2= other;
    while (temp1.nam > temp2.nam ||temp1.thang > temp2.thang || temp1.ngay > temp2.ngay){
        temp1.tru_1_ngay();
        demngay++;
    }
    while (temp2.nam > temp1.nam ||temp2.thang > temp1.thang || temp2.ngay > temp1.ngay){
        temp2.tru_1_ngay();
        demngay++;
    }
    return demngay;
}
void CDate::them_1_ngay(){
    if(!kiem_tra_ngay(ngay+1,thang,nam)){
        if(!kiem_tra_ngay(1,thang+1,nam)){
            if(!kiem_tra_ngay(1,1,nam+1))
                std::cout<<"Out of bound! not changing date\n";
            else ngay=1,thang=1,nam++;
        }
        else ngay=1,thang++;
    }
    else ngay++;
}
void CDate::tru_1_ngay(){
    int daysInMonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(isLeap(nam))daysInMonth[2]=29;
    if(!kiem_tra_ngay(ngay-1,thang,nam)){
        if(!kiem_tra_ngay(daysInMonth[thang-1],thang-1,nam)){
            if(!kiem_tra_ngay(31,12,nam-1))
                std::cout<<"Out of bound! not changing date\n";
            else ngay=31,thang=12,nam--;
        }
        else ngay=daysInMonth[thang-1],thang--;
    }
    else ngay--;
}
void CDate::Cong(int days){
    for(int i=0;i<days;i++)
        this->them_1_ngay();
}
void CDate::Tru(int days){
    for(int i=0;i<days;i++)
        this->tru_1_ngay();
}
