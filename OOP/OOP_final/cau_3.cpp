#include <iostream>
#include <string>
using namespace std;
class Malware{
protected:
    string name;
    string file;
public:
    virtual void Nhap(){
        cout<<"Nhap ten malware: ";
        cin>>name;
        cout<<"Nhap ten file: ";
        cin>>file;
    }
    virtual void Xuat(){
        cout<<"ten malware: "<<name<<'\n';
        cout<<"ten file: "<<file<<'\n';
    }
};
class Virus:public Malware{
private:
    string signature;
    string behavior;
public:
    void Nhap(){
        cout<<"Nhap ten malware: ";
        cin>>name;
        cout<<"Nhap ten file: ";
        cin>>file;
        cout<<"Nhap signature: ";
        cin>>signature;
        cout<<"Nhap behavior: ";
        cin>>behavior;
    }
    void Xuat(){
        cout<<"ten malware: "<<name<<'\n';
        cout<<"ten file: "<<file<<'\n';
        cout<<"signature: "<<signature<<'\n';
        cout<<"behavior: "<<behavior<<'\n';
    }
};
class Trojan:public Malware{
private:
    string payload;
    string disguise;
public:
    void Nhap(){
        cout<<"Nhap ten malware: ";
        cin>>name;
        cout<<"Nhap ten file: ";
        cin>>file;
        cout<<"Nhap payload: ";
        cin>>payload;
        cout<<"Nhap disguise: ";
        cin>>disguise;
    }
    void Xuat(){
        cout<<"ten malware: "<<name<<'\n';
        cout<<"ten file: "<<file<<'\n';
        cout<<"signature: "<<payload<<'\n';
        cout<<"behavior: "<<disguise<<'\n';
    }
};
class Ransomware:public Malware{
private:
    string encrypKey;
    string ransomAmount;
public:
    void Nhap(){
        cout<<"Nhap ten malware: ";
        cin>>name;
        cout<<"Nhap ten file: ";
        cin>>file;
        cout<<"Nhap encrypKey: ";
        cin>>encrypKey;
        cout<<"Nhap ransomAmount: ";
        cin>>ransomAmount;
    }
    void Xuat(){
        cout<<"ten malware: "<<name<<'\n';
        cout<<"ten file: "<<file<<'\n';
        cout<<"encrypKey: "<<encrypKey<<'\n';
        cout<<"ransomAmount: "<<ransomAmount<<'\n';
    }
};
int main(){
    Ransomware test;
    test.Nhap();
    test.Xuat();
}