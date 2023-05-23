#include <iostream>
#include <cstdlib> // for rand() function
#include <ctime> // for time() function

using namespace std;

class GiaSuc {
public:
    virtual void keu()= 0;
    virtual int sinhCon() = 0;
    virtual int choSua() = 0;
};

class Bo : public GiaSuc {
public:
    void keu() {
        cout << "Tieng keu: Boooo!" << endl;
    }
    int sinhCon() {
        int tile = (rand() % 101);
        if(tile>=97) return 2;
        return 1;
    }
    int choSua() {
        int litSua = rand() % 21;
        return litSua;
    }
};

class Cuu : public GiaSuc {
public:
    void keu() {
        cout << "Tieng keu: Meeee!" << endl;
    }
    int sinhCon() {
        int tile = (rand() % 101);
        if(tile>=97) return 3;
        if(tile>=65) return 2;
        return 1;
    }
    int choSua() {
        int litSua = rand() % 6;
        return litSua;
    }
};

class De : public GiaSuc {
public:
    void keu() {
        cout << "Tieng keu: Maaa!" << endl;
    }
    int sinhCon() {
        int tile = rand() % 101;
        if(tile>50) return 2;
        return 1;
    }
    int choSua() {
        int litSua = rand() % 11;
        return litSua;
    }
};

class quanly{
private:
    int slBo, slCuu, slDe;
    int tongsogiasuc;
    GiaSuc **ds;
public:
    quanly(int soBo,int soCuu,int soDe){
        slBo=soBo;slCuu=soCuu;slDe=soDe;
        tongsogiasuc=slBo+slCuu+slDe;
        ds = new GiaSuc*[tongsogiasuc];
        for (int i=0;i<slBo;i++)
            ds[i]= new Bo;
        for (int i=slBo;i<slCuu+slBo;i++)
            ds[i]= new Cuu;
        for (int i=slBo+slCuu;i<tongsogiasuc;i++)
            ds[i]= new De;
    }
    void update(int soBo,int soCuu,int soDe){
        // Free the memory allocated to previous livestock objects
        for (int i = 0; i < tongsogiasuc; i++)
            delete ds[i];
        delete[] ds;
        // Update
        slBo=soBo;slCuu=soCuu;slDe=soDe;
        tongsogiasuc=slBo+slCuu+slDe;
        ds = new GiaSuc*[tongsogiasuc];
        for (int i=0;i<slBo;i++)
            ds[i]= new Bo;
        for (int i=slBo;i<slCuu+slBo;i++)
            ds[i]= new Cuu;
        for (int i=slBo+slCuu;i<tongsogiasuc;i++)
            ds[i]= new De;
    }
    void tiengkeu(){
        if(slBo) ds[0]->keu();
        if(slCuu) ds[slBo]->keu();
        if(slDe) ds[slBo+slCuu]->keu();
    }
    void sinhcon(){
        int tongBoCon=0,tongDeCon=0,tongCuuCon=0;
        for(int i=0;i<slBo;i++)
            tongBoCon+=ds[i]->sinhCon();
        for(int i=slBo;i<slCuu+slBo;i++)
            tongCuuCon+=ds[i]->sinhCon();
        for(int i=slCuu+slBo;i<tongsogiasuc;i++)
            tongDeCon+=ds[i]->sinhCon();
        cout<<"so luong sinh cua Bo la: "<<tongBoCon<<endl;
        cout<<"so luong sinh cua Cuu la: "<<tongCuuCon<<endl;
        cout<<"so luong sinh cua De la: "<<tongDeCon<<endl;
        update(slBo+tongBoCon,slCuu+tongCuuCon,slDe+tongDeCon);
    }
    void laysua(){
        int tongsuacuaBo=0,tongsuacuaCuu=0,tongsuacuDe=0;
        for(int i=0;i<slBo;i++)
            tongsuacuaBo+=ds[i]->choSua();
        for(int i=slBo;i<slCuu+slBo;i++)
            tongsuacuaCuu+=ds[i]->choSua();
        for(int i=slCuu+slBo;i<tongsogiasuc;i++)
            tongsuacuDe+=ds[i]->choSua();
        cout<<"so luong sua cua Bo la: "<<tongsuacuaBo<<endl;
        cout<<"so luong sua cua Cuu la: "<<tongsuacuaCuu<<endl;
        cout<<"so luong sua cua De la: "<<tongsuacuDe<<endl;
        int tongsoluongsua=tongsuacuaBo+tongsuacuaCuu+tongsuacuDe;
        cout<<"tong so luong sua cua tat ca gia suc la: "<<tongsoluongsua<<endl;

    }
};
int main() {
    srand(time(0)); // seed the random number generator with the current time
    int slBo, slCuu, slDe;
    cout << "Nhap so luong bo: ";
    cin >> slBo;
    cout << "Nhap so luong cuu: ";
    cin >> slCuu;
    cout << "Nhap so luong de: ";
    cin >> slDe;
    quanly nongtrai(slBo,slCuu,slDe);
    nongtrai.tiengkeu();
    nongtrai.sinhcon();
    nongtrai.laysua();
    return 0;
}
