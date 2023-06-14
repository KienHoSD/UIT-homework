#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main(){
    uint64_t k,m,n;
    int a,b;
    uint64_t tong=0;
    cin>>a>>k>>b>>m>>n;
    long double i=n/((a+b)-(static_cast<float>(a)/static_cast<float>(k))-(static_cast<float>(b)/static_cast<float>(m)));
    cout<<setprecision(200);
    uint64_t u=i;
    tong=n+1;
    while(tong>n){
        u--;
        tong=a*u-((u/k)*a)+b*u-((u/m)*b);
    }
    while(tong<n){
        u++;
        tong=a*u-((u/k)*a)+b*u-((u/m)*b);
    }
    cout<<u;
}
