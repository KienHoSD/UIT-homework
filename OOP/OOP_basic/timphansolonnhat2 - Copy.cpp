#include <iostream>
#include <string.h>
using namespace std;
class sinhVien{
protected:
    int MSSV;
    string name;
    string diachi;
    int tongsotinchi;
    float gba;
public:
    sinhVien(int MSSV, string name, string diachi, int tongsotinchi,float gba){
        this->MSSV=MSSV;
        this->name = name;
        this->diachi=diachi;
        this->tongsotinchi=tongsotinchi;
        this->gba=gba;
    }
    virtual bool xetDKtotnghiep() = 0;
};

class sinhVienDaiHoc: public sinhVien{
private:
    string tenluanvan;
    float diemluanvan;
public:
    sinhVienDaiHoc(int MSSV, string name, string diachi, int tongsotinchi,float gba, string tenluanvan, float diemluanvan)
        :sinhVien(MSSV,name,diachi,tongsotinchi,gba){
        this->tenluanvan= tenluanvan;
        this->diemluanvan= diemluanvan;
    }
    bool xetDKtotnghiep(){
        if(tongsotinchi>=170&&gba>=5&&diemluanvan>=5)
            return 1;
        return 0;
    }
};

class sinhVienCaoDang: public sinhVien{
private:
    float diemthitotnghiep;
public:
    sinhVienCaoDang(int MSSV, string name, string diachi, int tongsotinchi,float gba, float diemthitotnghiep)
        :sinhVien(MSSV,name,diachi,tongsotinchi,gba){
        this->diemthitotnghiep= diemthitotnghiep;
    }
    bool xetDKtotnghiep(){
        if(tongsotinchi>=120&&gba>=5&&diemthitotnghiep>=5)
            return 1;
        return 0;
    }
};
int main(){
    int n; cin>>n;
    for(int i=0;i<=n;i++){

    }
    sinhVienDaiHoc a(22520704,"Ho Trung Kien","K5",170,5.4,"Sieu lord",5.4);
    sinhVienCaoDang b(22520703,"Ho Trung Wien","K1",125,5,5.4);

    sinhVien* p=&b;
    cout<<p->xetDKtotnghiep();

}
