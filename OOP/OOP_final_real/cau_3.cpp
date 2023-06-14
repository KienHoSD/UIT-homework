#include <iostream>
#include <string>
using namespace std;
class Malware{
protected:
    string name;
    string file;
    double detection_rate;
public:
    Malware(){
        detection_rate=0;
    }
    virtual void Nhap(){
        cout<<"Nhap ten malware: ";cin>>name;
        cout<<"Nhap ten file: ";cin>>file;
    }
    virtual void Xuat(){
        cout<<"ten malware: "<<name<<'\n';
        cout<<"ten file: "<<file<<'\n';
    }
    virtual void Determine_DetectionRate() = 0;
};
class Virus:public Malware{
private:
    string signature;
    string behavior;
public:
    void Nhap(){
        cout<<"Nhap ten Virus: "; getline(cin, name);
        cout<<"Nhap ten file: "; getline(cin, file);
        cout<<"Nhap chu ky virus: "; getline(cin, signature);
        cout<<"Nhap hanh vi virus: "; getline(cin, behavior);
    }
    void Xuat(){
        cout<<"------------------------------------\n";
        cout<<"Ten Virus: "<<name<<'\n';
        cout<<"Ten file: "<<file<<'\n';
        cout<<"Ti le phat hien virus: "<<detection_rate<<'\n';
        cout<<"Chu ky virus: "<<signature<<'\n';
        cout<<"Hanh vi virus: "<<behavior<<'\n';
        cout<<"------------------------------------\n";
    }
    void Determine_DetectionRate(){
        if(signature=="ILoveYou") detection_rate=99.99;
        else detection_rate=0.01;
    }

};
class Ransomware:public Malware{
private:
    string encrypKey;
    long ransomAmount;
public:
    void Nhap(){
        cout<<"Nhap ten Ransomware: "; getline(cin, name);
        cout<<"Nhap ten file: "; getline(cin, file);
        cout<<"Nhap khoa ma hoa: "; getline(cin, encrypKey);
        do{
            cout<<"Nhap so tien chuoc (USD): "; cin>>ransomAmount;     
            if(ransomAmount<0) cout<<"\nSo tien chuoc khong duoc am!\n";       
        } while(ransomAmount<0);

    }
    void Xuat(){
        cout<<"------------------------------------\n";
        cout<<"Ten Ransomware: "<<name<<'\n';
        cout<<"Ten file: "<<file<<'\n';
        cout<<"Ti le phat hien virus: "<<detection_rate<<'\n';
        cout<<"Khoa ma hoa: "<<encrypKey<<'\n';
        cout<<"So tien chuoc: "<<ransomAmount<<'\n';
        cout<<"------------------------------------\n";
    }
    void Determine_DetectionRate(){
        if(encrypKey.length()<8) detection_rate=96.69;
        else detection_rate=3.31;
    }
};
int main(){
    Malware* A;
    Virus B;
    Ransomware C;
    A=&B;
    A->Nhap();
    A->Determine_DetectionRate();
    A->Xuat();
    A=&C;
    A->Nhap();
    A->Determine_DetectionRate();
    A->Xuat();
}