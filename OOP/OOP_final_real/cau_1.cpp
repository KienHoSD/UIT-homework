#include <iostream>
#include <string>
using namespace std;
class SUBJECT_POINT{
private:
    string Name;
    double point_of_process;
    double midterm_point;
    double final_point;
    double point_average_of_subject;
public:
    void cal_point_average_of_subject(){
        point_average_of_subject = point_of_process*0.2 + midterm_point*0.3 + final_point*0.5;
    }
    void Nhap(){
        cout<< "Nhap ten mon hoc: ";
        getline(cin,Name);
        do{
            cout<< "Nhap diem qua trinh: "; 
            cin>>point_of_process;
            if(point_of_process<0) cout<<"\ndiem khong the la so am!\n";
        } while(point_of_process<0);
        do{
            cout<< "Nhap diem giua ki: "; 
            cin>>midterm_point;
            if(midterm_point<0) cout<<"\ndiem khong the la so am!\n";
        } while(midterm_point<0);
        do{
            cout<< "Nhap diem cuoi ki: "; 
            cin>>final_point;
            if(final_point<0) cout<<"\ndiem khong the la so am!\n";
        } while(final_point<0);
    }
    void Xuat(){
        cout<< "Ten mon hoc: "<<Name<<'\n';
        cout<< "Diem qua trinh: "<<point_of_process<<'\n';
        cout<< "Diem giua ki: "<<midterm_point<<'\n';
        cout<< "Diem cuoi ki: "<<final_point<<'\n';
        cout<< "Diem trung binh: "<<point_average_of_subject<<'\n';
    }
    friend istream& operator>>(istream& is, SUBJECT_POINT& temp){
        cout<< "Nhap ten mon hoc: ";
        getline(cin,temp.Name);
        do{
            cout<< "Nhap diem qua trinh: "; 
            is>>temp.point_of_process;
            if(temp.point_of_process<0) cout<<"\ndiem khong the la so am!\n";
        } while(temp.point_of_process<0);
        do{
            cout<< "Nhap diem giua ki: "; 
            is>>temp.midterm_point;
            if(temp.midterm_point<0) cout<<"\ndiem khong the la so am!\n";
        } while(temp.midterm_point<0);
        do{
            cout<< "Nhap diem cuoi ki: "; 
            is>>temp.final_point;
            if(temp.final_point<0) cout<<"\ndiem khong the la so am!\n";
        } while(temp.final_point<0);
        return is;
    }
    friend ostream& operator<< (ostream& os,const SUBJECT_POINT& temp){
        cout<< "Ten mon hoc: "<<temp.Name<<'\n';
        cout<< "Diem qua trinh: "<<temp.point_of_process<<'\n';
        cout<< "Diem giua ki: "<<temp.midterm_point<<'\n';
        cout<< "Diem cuoi ki: "<<temp.final_point<<'\n';
        cout<< "Diem trung binh: "<<temp.point_average_of_subject<<'\n';
        return os;
    }
};
int main(){

}