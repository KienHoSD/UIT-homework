#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(){
    float a;
    float n,i;
    float sauphay,Min=100;
    double ketqua;
    double Minx;
    cin>>a>>n;
    sauphay=a-floor(a);
    cout<<setprecision(100);
    for(i=0;i<=n;i++)
        if(abs(sauphay-float(i/n))<=Min){
            Min=abs(sauphay-float(i/n));
            Minx=float(i/n);
        }
    cout<<setprecision(10);
    ketqua=Minx+floor(a);
    cout<<ketqua;
}
