#include <iostream>
struct student{
    char hoten[100];
    double diemtoan,diemvan;
};
void nhap(student &a){
    std::cout<<"Nhap ho va ten:";
    std::cin.getline(a.hoten,100);
    std::cout<<"Nhap diem toan:";
    std::cin>>a.diemtoan;
    std::cout<<"Nhap ho va ten:";
    std::cin>>a.diemvan;
}
void xuat_dtb(student a){
    double diemtb=(a.diemtoan+a.diemvan)/2;
    std::cout<<"Diem trung binh = "<<diemtb;
}
int main(){
    student kien;
    nhap(kien);
    xuat_dtb(kien);
}
