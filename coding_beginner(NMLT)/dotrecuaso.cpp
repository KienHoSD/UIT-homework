#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
using namespace std;
int main(){
    int64_t n,i,dem=0;
    int64_t j;
    char sokhong= '0';
    cin>>n;
    string dongchuso = to_string(n);
    for(i=dongchuso.length()-1;i>=0;i--){
        if(n%10==0){
            n/=10;
        }
        else if(n%10!=0)
            break;
    }
    for(j=i;j>=0;j--){
        if(dongchuso[i]=='0')
            dem++;
    }
    cout<<dem;
}
