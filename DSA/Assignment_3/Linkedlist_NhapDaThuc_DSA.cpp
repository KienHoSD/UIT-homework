/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;

	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;

	}

	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;

	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}

};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};


//###INSERT CODE HERE -
void Nhap(DATHUC& p, double heso, int somu){
    DONTHUC *donThuc = new DONTHUC(heso, somu);
    if (p.head == nullptr){
        p.head = new Node(donThuc);
        p.tail = p.head;
    }
    else{
        p.tail->next = new Node(donThuc);
        p.tail = p.tail->next;
    }
}

void Xuat(DATHUC p){
    Node *temp = p.head;
    if (temp == nullptr){
        cout << "0";
        return;
    }
    int solan=0;
    while (temp != nullptr){
        if(temp->data->heso==0){
            temp = temp->next;
            continue;
        }
        solan++;
        if (temp->data->heso < 0)
            cout << "-";
        else if(solan!=1)
            cout << "+";
        if(abs(temp->data->heso)!=1||temp->data->somu==0)
            cout << abs(temp->data->heso);
        if (temp->data->somu > 1)
            cout << "x^" << temp->data->somu;
        else if(temp->data->somu == 1) cout<< "x";
        temp = temp->next;
    }
    if(solan==0) cout<<"0";

}

double TinhDaThuc(DATHUC p, double x){
    double result = 0;
    Node *temp = p.head;
    while (temp != nullptr){
        result += temp->data->heso * pow(x, temp->data->somu);
        temp = temp->next;
    }
    return result;
}
//2x^15-x^10+x^5+6x^2-8.5x-10.52
//2x^15-x^10+x^5+6x^2-8.5x-10.52
//-10x^6+x^5-1
//-10x^6+x^5-1

int main() {
    DATHUC B;
    int N;

    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }


    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
