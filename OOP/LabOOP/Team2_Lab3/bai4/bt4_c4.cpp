#include <bits/stdc++.h>
using namespace std;

class DonThuc;
class DaThuc;

class DonThuc{
    private:
        double heso;
        double somu;
    public:
        DonThuc(double heso=0, double somu=0){
            this->heso = heso;
            this->somu = somu;
        }
        friend istream& operator>>(istream &is, DonThuc &dt){
            cout<<"Nhap don thuc: ";
            is >> dt.heso >> dt.somu; // TODO: Bonus format (heso)x^(somu), for example 2x^2
            return is;
        }
        friend ostream& operator<<(ostream &os, DonThuc &dt){
            os << dt.heso << "x^" << dt.somu;
            return os;
        }
        double get_heso() const {
            return heso;
        }
        double get_somu() const {
            return somu;
        }
        DonThuc set_heso(double n){
            heso = n;
            return *this;
        }
        DonThuc set_somu(double n){
            somu = n;
            return *this;
        }
        // Overload + operator
        DonThuc operator+(const DonThuc& other){
            DonThuc result;
            if (this->somu == other.somu) {
                result.heso = this->heso + other.heso;
                result.somu = this->somu;
            } else {
                result.heso = this->heso;
                result.somu = this->somu;
            }
            return result;
        }
        // Overload - operator
        DonThuc operator-(const DonThuc& other){
            DonThuc result;
            if (this->somu == other.somu) {
                result.heso = this->heso - other.heso;
                result.somu = this->somu;
            } else {
                result.heso = this->heso;
                result.somu = this->somu;
            }
            return result;
        }
        // Overload * operator
        DonThuc operator*(const DonThuc& other){
            DonThuc result;
            result.heso = this->heso * other.heso;
            result.somu = this->somu + other.somu;
            return result;
        }
        // Helper function to "Find the first term of the quotient by dividing the highest degree term of the dividend by the highest degree term of the divisor."
        friend DonThuc find_first_term_of_quotent(const DonThuc& a, const DonThuc& b){
            DonThuc result;
            result.heso = a.heso / b.heso;
            result.somu = a.somu - b.somu;
            return result;
        }
};

bool cmp_somu(const DonThuc &a, const DonThuc &b){
    return a.get_somu() > b.get_somu();
}
bool find_somu(const DonThuc &a, double somu){
    return a.get_somu() == somu;
}
bool heso_bang_0(const DonThuc &a){
    return a.get_heso()==0;
}


class DaThuc{
    private:
        int n;
        vector<DonThuc> dathuc;
    public:
        DaThuc gen(int n=0){
            this->n = n;
            dathuc.resize(n, DonThuc());
            return *this;
        }
        DaThuc(int n=0){
            gen(n);
        }
        DaThuc(vector<DonThuc> dt){
            this->n = dt.size();
            this->dathuc = dt;
        }
        DaThuc operator=(const DaThuc& other){
            this->n = other.n;
            this->dathuc = other.dathuc;
            return *this;
        }
        DaThuc sapxep(){
            if (dathuc.empty()) {
                return *this;
            }
            sort(dathuc.begin(), dathuc.end(), cmp_somu);
            return *this;
        }
        // Scan over dt.dathuc vector, find 2 items i and j that dt.dathuc[i].get_somu() == dt.dathuc[i].get_somu(), if found, merge them by adding: dt.dathuc[i].set_heso(dt.dathuc[i].get_heso() + dt.dathuc[i].get_heso())
        DaThuc rutgon(){
            for (int i = 0; i < dathuc.size(); i++) {
                for (int j = i + 1; j < dathuc.size(); j++) {
                    if (dathuc[i].get_somu() == dathuc[j].get_somu()) {
                        DonThuc merged = dathuc[i] + dathuc[j];
                        dathuc[i] = merged;
                        dathuc[j] = DonThuc(0, dathuc[i].get_somu());
                    }
                }
            }
            // Erase all monomials with 0 coefficient (using heso_bang_0 function) in dathuc vector.
            dathuc.erase(remove_if(dathuc.begin(), dathuc.end(), heso_bang_0), dathuc.end());
            return *this;
        }
        friend istream& operator>>(istream &is, DaThuc &dt){
            // TODO: Input format: "ax^b + cx + d" or "a*x^b - c*x + d", use regex to validate format, remove all whitespace and split it into vector<DonThuc>, while also remove all monomials with 0 coefficent.
            // cout<<"Nhap so luong don thuc trong da thuc: ";
            // cin>>dt.n;
            // for (int i=0; i<dt.n; i++){
            //     double a, b;
            //     is >> a >> b;
            //     if (a!=0){
            //     }
            //         dt.dathuc.push_back(DonThuc(a, b));
            // }
            // dt.sapxep();
            // return is;
            string input;
            cout << "Nhap da thuc: ";
            getline(is, input);
            if (input.length() and input[0]!='-')
                input = "+" + input;

            // Remove all whitespace
            input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

            // Use regex to split input into vector<DonThuc>
            regex pattern("([+-]?\\d*\\.?\\d*)?\\*?(x)?(\\^(\\d+))?");
            sregex_iterator it(input.begin(), input.end(), pattern);
            sregex_iterator end;
            // "it" is pointer holding 4 capturing group: coefficient, variable (x), exponent, and the exponent value.
            while (it != end) {
                // All possibilities:
                // 1. Normal monomial (e.g. 2x^2 or 2x^2): 4/4 groups: 1, 2, 3, 4
                // 2. Coefficient 1 but exponent not 1 (e.g. x^3 or x^4): 3-4/4 groups: (1), 2, 3, 4
                // 3. Coefficient any and exponent 1 (e.g. 5x or x): 5x or x: 2/4 groups: 1, 2
                // 4. Just coefficient: 1/4 group: 1
                double a = 0;
                double b = 0;
                if (it->str(1)=="") // No match
                    break;
                if (it->str(1)!="" and it->str(2)=="" and it->str(3)=="" and it->str(4)==""){ // P4
                    a = stod(it->str(1));
                    b = 0;
                } 
                else if (it->str(1)!="" and it->str(2)=="x" and it->str(3)=="" and it->str(4)==""){ // P3
                    if (it->str(1)=="+")
                        a = 1;
                    else if (it->str(1)=="-")
                        a = -1;
                    else
                        a = stod(it->str(1));
                    b = 1;
                }
                else{
                    if (it->str(1)=="+") // P2
                        a = 1;
                    else if (it->str(1)=="-") // P2
                        a = -1;
                    else // P1
                        a = stod(it->str(1));
                    b = stod(it->str(4));
                }
                dt.dathuc.push_back(DonThuc(a, b));
                ++it;
            }
            dt.n = dt.dathuc.size();
            dt.sapxep();
            dt.rutgon();
            return is;
        }
        friend ostream& operator<<(ostream &os, DaThuc &dt){
            if (dt.dathuc.empty()) {
                os << 0;
                return os;
            }
            for (int i = 0; i < dt.dathuc.size(); i++) {
                if (i != 0 and dt.dathuc[i].get_heso()>0) // Đơn thức đầu tiên nếu hệ số là số dương thì không được xuất dấu + trước hệ số
                    if (dt.dathuc[i].get_heso()==1)
                        cout<<"+";
                    else
                        cout<<"+"<<dt.dathuc[i].get_heso();
                else {
                    if (dt.dathuc[i].get_heso()==-1) // Đơn thức có hệ số bằng -1 thì không xuất số 1
                        cout<<"-";
                    else if (dt.dathuc[i].get_heso()!=1) 
                        cout<<dt.dathuc[i].get_heso();
                    // Đơn thức có hệ số bằng 1 thì không xuất số 1
                }
                // x^0? Đơn thức có số mũ bằng 0 thì chỉ xuất hệ số của đơn thức
                // 1x^0 -> 1 or -1x^0 => -1
                if (dt.dathuc[i].get_somu()==0){
                    if (dt.dathuc[i].get_heso()==-1 or dt.dathuc[i].get_heso()==1)
                        cout<<abs(dt.dathuc[i].get_heso());
                    continue;
                }
                // Đơn thức có số mũ bằng 1 thì không xuất số mũ
                if (dt.dathuc[i].get_somu() != 1){
                    cout<<"x^"<<dt.dathuc[i].get_somu();
                }
                else
                    cout<<"x";
            }
            return os;
        }
        // Overload + operator
        friend DaThuc operator+(const DaThuc& a, const DaThuc& b){
            DaThuc result = a;
            // Merge 2 vector a.dathuc and b.dathuc and assign into result.dathuc
            for (const auto& don_thuc : b.dathuc) {
                result.dathuc.push_back(don_thuc);
            }
            result.sapxep();
            result.rutgon();
            return result;
        }
        // Overload - operator
        friend DaThuc operator-(const DaThuc& a, const DaThuc& b){
            DaThuc result = a;
            // Merge 2 vector a.dathuc and -(b.dathuc) and assign into result.dathuc
            for (const auto& don_thuc : b.dathuc) {
                result.dathuc.push_back(DonThuc(-don_thuc.get_heso(), don_thuc.get_somu()));
            }
            result.sapxep();
            result.rutgon();
            return result;
        }
        // Overload * operator
        friend DaThuc operator*(const DaThuc& a, const DaThuc& b){
            DaThuc result;
            for (DonThuc don_thuc_a: a.dathuc){
                for (DonThuc don_thuc_b: b.dathuc){
                    result.dathuc.push_back(don_thuc_a * don_thuc_b);
                }
            }
            result.sapxep();
            result.rutgon();
            return result;
        }
        friend DaThuc operator/(const DaThuc& a, const DaThuc& b){
            /*
            The steps for the polynomial division are given below.

            Step 1: Arrange the dividend and the divisor in the descending order of their exponents. (using DaThuc.sapxep_nguoc method)

            Step 2: Find the first term of the quotient by dividing the highest degree term of the dividend by the highest degree term of the divisor. (using DonThuc.find_first_term_of_quotent method)

            Step 3: Then multiply the divisor by the current quotient and subtract the result from the current dividend. This will give a new dividend.

            Step 4: Find the next term of the quotient by dividing the largest degree term of the new dividend obtained in step 3 by the largest degree term of the divisor.

            Step 5: Repeat steps 3 and 4 again until the degree of the remainder is less than the degree of the divisor.
            */
            DaThuc check = b;
            if (check.dathuc.size()==0){
                cout << "Chung toi phat hien ban chia da thuc voi 0. Tat nhien chung toi khong muon lam phien phuc ban, xin phep thoat khoi ham nay. ";
                return DaThuc();
            }
            DaThuc result;
            // Step 1: Sort a and b in descending order of their exponents (okay, a and b sorted)
            // Step 2: Find the first term of the quotient
            DonThuc first_term = find_first_term_of_quotent(a.dathuc[0], b.dathuc[0]);
            result.dathuc.push_back(first_term);
            // Step 3-5: Repeat until degree of remainder is less than degree of divisor or no remainder.
            DaThuc remainder = a - (b * DaThuc({first_term}));
            while (remainder.dathuc.size() > 0 && remainder.dathuc[0].get_somu() >= b.dathuc[0].get_somu()) {
                DonThuc next_term = find_first_term_of_quotent(remainder.dathuc[0], b.dathuc[0]);
                result.dathuc.push_back(next_term);
                remainder = remainder - (b * DaThuc({next_term}));
            }
            result.sapxep();
            result.rutgon();
            return result;
        }
        friend DaThuc operator%(const DaThuc& a, const DaThuc& b){
            DaThuc check = b;
            if (check.rutgon().dathuc.size()==0){
                cout << "Chung toi phat hien ban chia da thuc voi 0. Tat nhien chung toi khong muon lam phien phuc ban, xin phep thoat khoi ham nay. ";
                return DaThuc();
            }
            DaThuc result;
            result = a - (b * (a / b));
            return result;
        }
        // Overload () operator with 1 arg. to find value of f(x) (f is DaThuc)
        double operator()(double x){
            if (this->dathuc.size()==0)
                return 0;
            double val = 0;
            for (DonThuc dt: this->dathuc){
                val += (dt.get_heso() * pow(x, dt.get_somu()));
            }
            return val;
        }
};

int main(){
    DaThuc f, g;
    double x;
    cout << "Nhap lan luot da thuc f(x) va g(x).\n";
    cin >> f >> g;
    // cout<< a << endl << b << endl;
    DaThuc tong = f + g;
    cout << "Tong: " << tong << endl;
    DaThuc hieu = f - g;
    cout << "Hieu: " << hieu << endl;
    DaThuc tich = f * g;
    cout << "Tich: " << tich << endl;
    DaThuc thuong = f / g;
    cout << "Thuong: " << thuong << endl;
    DaThuc phandu = f % g;
    cout << "Phan du cua phep chia tren: " << phandu << endl;
    cout << "Nhap x de tinh gia tri f(x): ";
    cin >> x;
    cout << "f(" << x << ") = " << f(x) << endl;
    cout << "Nhap x de tinh gia tri g(x): ";
    cin >> x;
    cout << "g(" << x << ") = " << g(x) << endl;
    return 0;
}