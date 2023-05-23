#include <iostream>
using namespace std;
class String {
private:
    char* chuoi;
    int StringLength();
public:
    String();
    ~String();
    void NhapChuoi();
    void XuatChuoi();
    void ChieuDaiChuoi();
    void NoiHaiChuoi();
    void DaoChuoi();
};
String::String() {
    chuoi = new char[10000];
}
String::~String() {
    delete[] chuoi;
    chuoi = NULL;
}
int String::StringLength() {
    int i, dem;
    i = dem = 0;
    while (chuoi[i] != '\0') {
        dem++;
        i++;
    }
    return dem;
}
void String::NhapChuoi() {
    cout << "Vui long nhap chuoi ky tu: ";
    cin.getline(chuoi, 10000);
}
void String::ChieuDaiChuoi() {
    cout << "Chieu dai cua chuoi la: ";
    cout << this->StringLength() << endl;
}
void String::NoiHaiChuoi() {
    String temp;
    cout << "Chuoi ky tu thu hai: " << endl;
    temp.NhapChuoi();
    int so1, so2;
    so1 = so2 = 0;
    while (this->chuoi[so1] != '\0') so1++;
    chuoi[so1++] = ' ';
    while (temp.chuoi[so2] != '\0') {
        chuoi[so1] = temp.chuoi[so2];
        so1++;
        so2++;
    }
    chuoi[so1] = '\0';
    cout << "Ket qua khi noi 2 chuoi: ";
    this->XuatChuoi();

}
void String::DaoChuoi() {
    int dodai = this->StringLength();
    reverse(this->chuoi, this->chuoi + dodai);
    cout << "Ket qua sau khi dao chuoi la: ";
    this->XuatChuoi();
}
void String::XuatChuoi() {
    cout << chuoi << endl;
}

int main()
{
    String A;
    A.NhapChuoi();
    A.ChieuDaiChuoi();
    A.NoiHaiChuoi();
    A.DaoChuoi();
}
