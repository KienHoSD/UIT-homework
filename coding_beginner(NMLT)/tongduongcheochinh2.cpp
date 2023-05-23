#include <iostream>
#define MAX 100
using namespace std;
bool lacotdonvi(double matrix[][MAX],int SIZE,int j){
    for(int i=0;i<SIZE;i++){
        if(i!=j&&matrix[i][j]!=0) return false;
        if(i==j&&matrix[i][j]!=1) return false;
    }
    return true;
}
bool lacotfeb(double matrix[][MAX],int SIZE,int j){
    for(int i=0;i<=j;i++){
        if(i!=j&&matrix[i][j]!=0) return false;
        if(i==j&&matrix[i][j]!=1) return false;
    }
    return true;
}
int main()
{
    int SIZE,SIZE2;
    cin>>SIZE>>SIZE2;
    double matrix[MAX][MAX];
    for(int i=0; i<SIZE ; i++){
        for(int j=0; j<SIZE; j++){
            cin >> matrix[i][j];
        }
    }
    int countf=0;
    int socotkhongdonvi=0;
    for(int j=0; j<SIZE; j++){
        if(lacotdonvi(matrix,SIZE,j)==false){
            socotkhongdonvi++;
            if(lacotfeb(matrix,SIZE,j)==false) break;
            else countf++;
        }
        if (socotkhongdonvi>=2||countf==2) break;
    }
    if (countf==1&&socotkhongdonvi==1) cout<<"Yes";
    else if(countf==0&&socotkhongdonvi==0) cout<<"Yes";
    else cout<<"No";
    return 0;
}
