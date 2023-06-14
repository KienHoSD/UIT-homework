#include <iostream>
#include <string>
#include <vector>
using namespace std;
class SUBJECT_POINT{
private:
    string Name;
    double point_of_process;
    double midterm_point;
    double final_point;
    double point_average_of_subject;
public:
    SUBJECT_POINT(){
        Name="";
        point_average_of_subject=0;
        midterm_point=0;
        final_point=0;
        point_average_of_subject=0;
    }
    double get_point_average_of_subject(){
        return point_average_of_subject;
    }
    void cal_point_average_of_subject(){
        point_average_of_subject = point_of_process*0.2 + midterm_point*0.3 + final_point*0.5;
    }
    void Nhap(){

        cin>>Name;

        cin>>point_of_process;

        cin>>midterm_point;

        cin>>final_point;
    }
    void Xuat(){
        cout<<"------------------------------";
        cout<< "Ten mon hoc: "<<Name<<'\n';
        cout<< "Diem qua trinh: "<<point_of_process<<'\n';
        cout<< "Diem giua ki: "<<midterm_point<<'\n';
        cout<< "Diem cuoi ki: "<<final_point<<'\n';
        cout<< "Diem trung binh: "<<point_average_of_subject<<'\n';
        cout<<"------------------------------";
    }
    friend istream& operator>>(istream& is, SUBJECT_POINT& temp){
        is>>temp.Name;

        is>>temp.point_of_process;

        is>>temp.midterm_point;

        is>>temp.final_point;
        return is;
    }
    friend ostream& operator<< (ostream& os,const SUBJECT_POINT& temp){
        cout<<"------------------------------\n";
        cout<< "Ten mon hoc: "<<temp.Name<<'\n';
        cout<< "Diem qua trinh: "<<temp.point_of_process<<'\n';
        cout<< "Diem giua ki: "<<temp.midterm_point<<'\n';
        cout<< "Diem cuoi ki: "<<temp.final_point<<'\n';
        cout<< "Diem trung binh: "<<temp.point_average_of_subject<<'\n';
        cout<<"------------------------------\n";
        return os;
    }
};
int main(){
    int n;
    do{
        cout<<"Nhap so luong mon hoc (n): ";
        cin>>n;
        if(n<=3) cout<<"n phai lon hon 3!\nvui long nhap lai n: ";
    } while(n<=3);
    vector<SUBJECT_POINT> mang_subject(n);
    for(int i=0;i<n;i++){
        cout<<"Nhap mon hoc "<<i+1<<"\n";
        cin>>mang_subject[i];
        mang_subject[i].cal_point_average_of_subject();
        cout<<mang_subject[i];
    }
    // Khai bao cac bien can thiet
    double diem_trung_binh_tat_ca_cac_mon=0;
    double diem_trung_binh_min=mang_subject[0].get_point_average_of_subject();
    double diem_trung_binh_max=diem_trung_binh_min;
    double diem_trung_binh_dang_xet=0;
    int vi_tri_max=0;
    int vi_tri_min=0;
    // Tinh diem trung binh tat ca cac mon va tim diem trung binh max va min
    for(int i=0;i<n;i++){
        diem_trung_binh_dang_xet=mang_subject[i].get_point_average_of_subject();
        diem_trung_binh_tat_ca_cac_mon+=diem_trung_binh_dang_xet;
        if(diem_trung_binh_dang_xet>diem_trung_binh_max){
            diem_trung_binh_max=diem_trung_binh_dang_xet;
            vi_tri_max=i;
        }
        if(diem_trung_binh_dang_xet<diem_trung_binh_min){
            diem_trung_binh_min=diem_trung_binh_dang_xet;
            vi_tri_min=i;
        }
    }
    diem_trung_binh_tat_ca_cac_mon/=n;
    cout<<"-----------------------------------------------\n";
    cout<<"Diem trung binh tat ca cac mon (GPA): "<<diem_trung_binh_tat_ca_cac_mon<<"\n";
    cout<<"-----------------------------------------------\n";
    cout<<"Mon hoc co diem trung binh cao nhat:\n";
    cout<<mang_subject[vi_tri_max];
    cout<<"Mon hoc co diem trung binh thap nhat:\n";
    cout<<mang_subject[vi_tri_min];
}
