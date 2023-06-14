#include <iostream>
#include <math.h>
using namespace std;
int main(){
    uint64_t k,m,n;
    int a,b;
    uint64_t tong=0;
    cin>>a>>k>>b>>m>>n;
    if(n<=0){
        uint64_t i=n/(a+b)-1;
        while(tong<n){
            i++;
            tong=a*i-((i/k)*a)+b*i-((i/m)*b);
        }
        cout<<i;
    }
    else{
        float i=n/((a+b)-(static_cast<float>(a)/static_cast<float>(k))-(static_cast<float>(b)/static_cast<float>(m)));
        uint64_t u=static_cast<uint64_t>(i);
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

}
