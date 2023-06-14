#include <iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=11;j++){
            if(i==1||i==4){
                if(j%2!=0) cout<<x;
                else cout<<" ";
            }
            else{
                if(j==1||j==11) cout<<x;
                else cout<<" ";
            }
        } cout<<endl;
    }
    for(int i = 1; i <= 6; i++) {
        for(int j = i; j < 6; j++) cout << " ";
        for(int j = 1; j <= (2*i-1); j++) {
            if(i==6){
                if(j%2!=0) cout<<x;
                else cout<<" ";
            }
            else if(j==1||j==(2*i-1)) cout << x;
            else cout<<" ";
        }
        cout << endl;
    }
}
