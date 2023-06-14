#include <iostream>

class sophuc{
    private:
        int thuc,ao;
    public:
        sophuc(){
            thuc=0;
            ao=1;
        }
        sophuc(int a,int b){
            thuc=a;
            ao=b;
        }
        void nhap(){
            std::cout<<"Nhap thuc:";
            std::cin>>thuc;
            std::cout<<"Nhap ao:";
            std::cin>>ao;
        }
        void xuat(){
            std::cout<<"Phan thuc ="<<thuc<<"\n";
            std::cout<<"Phan ao ="<<ao<<"\n";
        }
        sophuc operator+(sophuc p){
            sophuc temp;
            temp.thuc=p.thuc+this->thuc;
            temp.ao=p.ao+this->ao;
            return temp;
        }
        sophuc operator-(sophuc p){
            sophuc temp;
            temp.thuc=this->thuc-p.thuc;
            temp.ao=this->ao-p.ao;
            return temp;
        }
        sophuc operator*(sophuc p){
            sophuc temp;
            temp.thuc=this->thuc*p.thuc-this->ao*p.ao;
            temp.ao=this->thuc*p.ao+this->ao*p.thuc;
            return temp;
        }
        sophuc operator/(sophuc p){
            sophuc temp;
            temp.thuc=(this->thuc*p.thuc+this->ao*p.ao)/(p.ao*p.ao+p.thuc*p.thuc);
            temp.ao=(p.thuc*this->ao-p.ao*this->thuc)/(p.ao*p.ao+p.thuc*p.thuc);
            return temp;
        }
};
int main(){
    sophuc p1,p2;
    std::cout << "Nhap so phuc 1:\n";
    p1.nhap();
    std::cout << "Nhap so phuc 2:\n";
    p2.nhap();
    std::cout << "Phep cong:\n";
    (p1+p2).xuat();
    std::cout << "Phep tru:\n";
    (p1-p2).xuat();
    std::cout << "Phep nhan:\n";
    (p1*p2).xuat();
    std::cout << "Phep chia:\n";
    (p1/p2).xuat();
}

