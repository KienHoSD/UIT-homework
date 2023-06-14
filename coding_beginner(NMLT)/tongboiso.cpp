#include <bits/stdc++.h>
using namespace std;
int main()
{
    int boisocuaba=0;
    int boisocuanam=0;
    int n;
    int u;
    cout<<"Nhap so n: ";
    cin>>n;
    if(n%3==0 || n%5==0){
        u=n-1;
    }
    else{
        u=n;
    }
    for(int i=1;i<=u/3;i++)
        boisocuaba += i*3;
    for(int i=1;i<=u/5;i++)
        boisocuanam += i*5;
    cout<<"Tong boi so cua 3 va 5 va nho hon "<<n<<" la "<<boisocuaba + boisocuanam;
}
