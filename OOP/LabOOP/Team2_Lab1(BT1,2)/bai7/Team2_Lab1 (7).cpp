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
            std::cin >> thuc >> ao;
        }
        void xuat(){
            if (ao == 0) std::cout << thuc <<"\n";
            else if (ao < 0) std::cout << thuc << ao << "i\n";
            else std::cout << thuc << "+" << ao << "i\n";
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
    sophuc p1;
    std::cout << "Nhap phan thuc va phan ao cua so phuc 1: ";
    p1.nhap();
    std::cout << "Nhap phan thuc va phan ao cua so phuc 2: ";
    int a,b; std::cin >> a >> b;
    sophuc p2(a,b);
    std::cout << "So phuc 1: ";
    p1.xuat();
    std::cout << "So phuc 2: ";
    p2.xuat();
    std::cout << "Phep cong: ";
    (p1+p2).xuat();
    std::cout << "Phep tru: ";
    (p1-p2).xuat();
    std::cout << "Phep nhan: ";
    (p1*p2).xuat();
    std::cout << "Phep chia: ";
    (p1/p2).xuat();
}

