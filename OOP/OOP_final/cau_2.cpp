#include <iostream>
#include <vector>
using namespace std;
class MATRIX{
private:
    int dong,cot;
    vector<vector<int>> matrix;
public:
    MATRIX(){
        dong=0;cot=0;
    }
    MATRIX(int d,int c){
        dong=d;cot=c;
        matrix.resize(dong,vector<int>(cot,0));
    }
    void Nhap(){
        cin>>dong>>cot;
        int temp;
        matrix.resize(dong,vector<int>(cot,0));
        for(int i=0;i<dong;i++){
            for(int j=0;j<cot;j++){
                cin>>temp;
                matrix[i][j]=temp;
            }
        }
    }
    void Xuat(){
        for(int i=0;i<dong;i++){
            for(int j=0;j<cot;j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    MATRIX operator+ (const MATRIX& temp){
        MATRIX ans(this->dong,this->cot);
        for(int i=0;i<this->dong;i++){
            for(int j=0;j<this->cot;j++)
                ans.matrix[i][j]=this->matrix[i][j]+temp.matrix[i][j];
        }
        return ans;
    }
    MATRIX operator- (const MATRIX& temp){
        MATRIX ans(this->dong,this->cot);
        for(int i=0;i<this->dong;i++){
            for(int j=0;j<this->cot;j++)
                ans.matrix[i][j]=this->matrix[i][j]-temp.matrix[i][j];
        }
        return ans;
    }
    MATRIX operator* (const MATRIX& temp){
        MATRIX ans(this->dong,temp.cot);
        for(int i=0;i<this->dong;i++)
            for(int j=0;j<temp.cot;j++)
                for(int e=0;e<this->cot;e++)
                    ans.matrix[i][j]+=this->matrix[i][e]*temp.matrix[e][j];       
        return ans;
    }
    friend ostream& operator<< (ostream& os, MATRIX matrix){
        for(int i=0;i<matrix.dong;i++)
            for(int j=0;j<matrix.cot;j++)
                os<<matrix.matrix[i][j];
        return os;
    }
    friend istream& operator>> (istream& is, MATRIX matrix){
        for(int i=0;i<matrix.dong;i++)
            for(int j=0;j<matrix.cot;i++)
                is>>matrix.matrix[i][j];
        return is;
    }
    
};
int main(){
    MATRIX A(3,3);
    MATRIX B(3,3);
    cin>> A;
    cin>> B;
    cout<<"\nma tran A:\n";
    cout<<A;
    cout<<"\nma tran B:\n";
    cout<<B;
    cout<<"\nma tran ket qua cua A * B\n";
    (A*B).Xuat();
    cout<<"\nma tran ket qua cua A + B\n";
    (A+B).Xuat();
    cout<<"\nma tran ket qua cua A - B\n";
    (A-B).Xuat();
}