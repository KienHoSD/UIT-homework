#include <iostream>
#include <string>
using namespace std;
int main(){
    string dongchuso;
    int i,j;
    getline(cin,dongchuso);
    string dongchusodefault=dongchuso;
    unsigned long long dongso;
    for(i=0;i<=dongchuso.length()-1;i++){
        for(j=9;j>=1;j--){
            if(dongchuso[i]!=char(j+48)){
                dongchuso[i]=char(j+48);
            }
            dongso = stoll(dongchuso);
            if (dongso%3==0&&dongchuso!=dongchusodefault){
                break;
            }
            else{
                dongso = stoll(dongchusodefault);
            }
        }
        if (dongso%3==0){
                break;
        }
        dongchuso=dongchusodefault;
    }
    cout<<dongso;
}
